# Quiz 6 — Composition, Private Helpers, and Separate Files (7.8 – 7.11)

This quiz tests four ideas: **putting one class inside another (has-a)**, **private member functions**, **ordinary functions that pass and return objects**, and **splitting a class across `.h` and `.cpp` files**.

## The Expected Output

```
Shelf area: 32 sq ft
Total cost: $112.00

Dimensions rejected:
shelf is oversized.
```

## Key Takeaways

1. A `Shelf` **has a** `Rectangle`. That is **composition**: the `Rectangle` is a private data member, not a parent class. There is no `: public Rectangle` anywhere.
2. A **private member function** can be called by the class's own member functions (like `setDimensions`) but **not** from `main`. Trying `shelf.isOversized();` in `main` is a compile error.
3. A function that is **not a member** (`makeShelf`, `displayShelf`) can only use the class's **public** interface.
4. Passing an object as `const Shelf &` avoids making a copy **and** promises not to change it, so only `const` member functions can be called on it.
5. The class does **no input or output**. It only stores and computes. All `cout` lives in the client.

## File Layout

| File | What goes in it |
|---|---|
| `Rectangle.h` | Given in the quiz: the `Rectangle` class declaration |
| `Rectangle.cpp` | Definitions of `Rectangle`'s member functions (needed to link) |
| `Shelf.h` | The `Shelf` class **declaration only**, with no function bodies |
| `Shelf.cpp` | The `Shelf` member function **definitions**, each written as `Shelf::name(...)` |
| `client.cpp` | `makeShelf`, `displayShelf`, and `main`. This is the only file with `cout` |

Build with all three `.cpp` files:

```
g++ client.cpp Shelf.cpp Rectangle.cpp
```

`Shelf.h` includes `Rectangle.h` because the `Shelf` class has a `Rectangle` member. The compiler must know what a `Rectangle` is before it can lay out a `Shelf`.

---

## Requirement by Requirement

### 1. Has-a: `Rectangle size;` and `double costPerSqFt;`

```cpp
class Shelf
{
    private:
        Rectangle size;
        double    costPerSqFt;
```

`size` is a whole `Rectangle` object living inside every `Shelf`. Because `length` and `width` are private **to `Rectangle`**, `Shelf` cannot touch `size.length` directly. It must go through `Rectangle`'s public functions: `size.setLength(...)`, `size.getWidth()`, `size.calcArea()`.

### 2. The private helper `isOversized()`

```cpp
bool Shelf::isOversized() const
{
    return size.calcArea() > 50;
}
```

It is declared under `private:` in `Shelf.h`, so:

- `setDimensions` (a member) **can** call it.
- `main` (not a member) **cannot**. `shelf.isOversized()` gives *"isOversized is private within this context."*

Note that it is **greater than** 50, so a shelf of exactly 50 sq ft is allowed.

### 3. The public interface

```cpp
Shelf();
bool   setDimensions(double, double);
void   setCostPerSqFt(double);
double getArea() const;
double getCost() const;
```

**Default constructor.** `Rectangle` has no constructor, so its `length` and `width` start out as garbage. The `Shelf` constructor sets them to `0` (through the setters) and sets `costPerSqFt` to `0`, so a new `Shelf` is always in a valid state.

**`setDimensions`** has two ways to fail:

```cpp
bool Shelf::setDimensions(double len, double wid)
{
    if (len < 0 || wid < 0)              // reject negatives
        return false;

    double oldLen = size.getLength();    // remember the old size
    double oldWid = size.getWidth();

    size.setLength(len);
    size.setWidth(wid);

    if (isOversized())                   // reject oversized shelves
    {
        size.setLength(oldLen);          // put the old size back
        size.setWidth(oldWid);
        return false;
    }
    return true;
}
```

`isOversized()` takes no parameters and looks at the **current** `size`, so we have to set the new dimensions first. If they turn out to be too big, we **restore the old ones**. A rejected call should leave the shelf unchanged.

**`getArea` and `getCost`** are `const` because they only read. That matters in requirement 4.

### 4. Two ordinary (non-member) functions

```cpp
Shelf makeShelf(double len, double wid, double cost)
{
    Shelf s;                    // local Shelf
    s.setDimensions(len, wid);
    s.setCostPerSqFt(cost);
    return s;                   // returned by value (a copy)
}
```

`s` is a local variable, so it would be destroyed when the function ends. Returning **by value** hands a copy back to the caller, so this is safe. (Returning `Shelf &` to a local would **not** be safe.)

```cpp
void displayShelf(const Shelf &s)
{
    cout << "Shelf area: " << s.getArea() << " sq ft" << endl;
    cout << fixed << setprecision(2);
    cout << "Total cost: $" << s.getCost() << endl;
}
```

Because `s` is a `const` reference, only `const` member functions may be called on it. If `getArea` or `getCost` were missing `const`, this would not compile.

The area prints **before** `fixed` is turned on, so it shows as `32` and not `32.00`.

Neither function has `Shelf::` in front of its name. They are not members.

### 5. No I/O inside the class

`Shelf.h` and `Shelf.cpp` do not even `#include <iostream>`. The class reports problems by **returning `false`**, and the client decides what to print. This keeps the class reusable: a GUI program could use the same `Shelf` without any console output.

---

## Step-by-Step Trace of `main`

### `Shelf shelf = makeShelf(8, 4, 3.50);`
Inside `makeShelf`:
- `Shelf s;` runs the default constructor: `0 x 0`, `$0` per sq ft.
- `s.setDimensions(8, 4)`: not negative. Area `32` is not `> 50`, so it is kept and returns `true`.
- `s.setCostPerSqFt(3.50)` stores `3.50`.
- `s` is returned and copied into `shelf`.

### `displayShelf(shelf);`
- `getArea()` → `8 * 4 = 32`
- `getCost()` → `32 * 3.50 = 112`, printed as `112.00`

Prints:
```
Shelf area: 32 sq ft
Total cost: $112.00
```

### `cout << endl;`
Prints the blank line.

### `shelf.setDimensions(10, 6)`
- Not negative.
- Old size `8 x 4` is saved and the new size `10 x 6` is set.
- `isOversized()`: `60 > 50` is **true**.
- The old size `8 x 4` is restored and the function returns `false`.

`!false` is `true`, so `main` prints:
```
Dimensions rejected:
shelf is oversized.
```

---

## Common Mistakes to Avoid

| Mistake | Why it's wrong |
|---|---|
| `class Shelf : public Rectangle` | That is inheritance (is-a). The quiz asks for **has-a**, a `Rectangle` member. |
| Putting `isOversized()` under `public:` | Then `main` could call it. It must be **private**. |
| Adding extra public functions (`getLength`, `print`, ...) | The quiz says the public interface is those five members **and nothing more**. |
| Writing `cout` inside `setDimensions` or the class | Requirement 5: every bit of I/O lives in the client. |
| Making `displayShelf` or `makeShelf` a member (`Shelf::displayShelf`) | They must be **ordinary** functions. |
| Forgetting `const` on `getArea` / `getCost` | `displayShelf(const Shelf &s)` can't call them, so it's a compile error. |
| Calling `isOversized()` **before** setting the new size | It checks the **old** size, so a 10 x 6 shelf would be wrongly accepted. |
| Not restoring the old size on rejection | A rejected call leaves the shelf at 10 x 6, even though it returned `false`. |
| Accessing `size.length` directly from `Shelf` | `length` is private to `Rectangle`. Use `size.setLength()` / `size.calcArea()`. |
| Function bodies inside `Shelf.h` | The quiz says `Shelf.h` is **declaration only**. |
| `setprecision(2)` without `fixed` | `112` would print as `1.1e+02`. You need `fixed` to get `112.00`. |
