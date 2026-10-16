# Quiz 5 — Constructors, Setters, and Destructors

This quiz tests three ideas: **which constructor runs for each object**, **how a setter can reject bad values**, and **when a destructor runs**.

## The Answer

```
A10 B5 5 X5 10 X10
```

## Key Takeaways

1. An object declared with no arguments (`Counter c1;`) uses the **default constructor**. An object declared with arguments (`Counter c2(5);`) uses the constructor whose parameters match.
2. `setCount` only changes `count` when the new value is `>= 0`. A negative value is **ignored**, and the old value stays.
3. A local object's destructor runs **automatically when the object goes out of scope**, which is at the closing `}` of the function it was declared in. You never call it yourself.
4. Objects are destroyed in the **reverse order** they were created. `c2` is created after `c1` and destroyed before it.

## Step-by-Step Trace

The `Counter` class prints something in three places:

| Member function | When it runs | Prints |
|---|---|---|
| `Counter()` | object created with no arguments | `A` + `count` (always `A10`) |
| `Counter(int c)` | object created with one `int` | `B` + `count` |
| `~Counter()` | object goes out of scope | `X` + `count` |

### `Counter c1;`
No arguments, so the **default constructor** runs. `count` is set to `10`.

Prints: `A10 `

### `demo();`
Control jumps into `demo`. `c1` still exists in `main`; it is just waiting.

#### `Counter c2(5);`
One `int` argument, so the **one-parameter constructor** runs. `count` is set to `5`.

Prints: `B5 `

#### `c2.setCount(-3);`
The check `if (c >= 0)` is `-3 >= 0`, which is **false**. Nothing happens. **`count` is still `5`**.

Prints: nothing

#### `cout << c2.getCount() << " ";`
`getCount()` returns `5`.

Prints: `5 `

#### End of `demo` (the closing `}`)
`c2` is a local variable of `demo`, so it goes out of scope here. Its **destructor** runs with `count = 5`.

Prints: `X5 `

### `cout << c1.getCount() << " ";`
Back in `main`. `c1` was never changed, so `getCount()` returns `10`.

Prints: `10 `

### `return 0;` and the end of `main`
`c1` is a local variable of `main`, so it goes out of scope at the end of `main`. Its **destructor** runs with `count = 10`.

Prints: `X10 `

### Full output

```
A10 B5 5 X5 10 X10
```

---

## Why the Other Choices Are Wrong

### B

```
A10 B5 -3 X-3 10 X10
```

This answer assumes `setCount(-3)` changes `count` to `-3`. But `setCount` has a guard: `if (c >= 0)`. Since `-3` is negative, the assignment is skipped and `count` stays `5`. So `getCount()` prints `5`, and the destructor prints `X5`, not `X-3`.

### C

```
A10 B5 5 10 X5 X10
```

This answer delays `c2`'s destructor until the end of the program. But `c2` belongs to `demo`, not `main`. It is destroyed as soon as `demo` ends, **before** `main` prints `c1.getCount()`. So `X5` must come before `10`.

### D

```
A10 B5 5 X5 10
```

This answer forgets that `c1` also has a destructor. `c1` is a local object in `main`, so when `main` ends, `~Counter()` runs for it too and prints `X10`. Every object that is constructed is also destroyed.

---

## Common Mistakes to Avoid

| Mistake | What happens |
|---|---|
| Ignoring the `if` inside `setCount` | You'd think `count` becomes `-3` and print `-3` and `X-3` (choice B) |
| Thinking all destructors run at the end of the program | You'd print `X5` after `10` instead of before it (choice C) |
| Forgetting the destructor runs for objects in `main` | You'd leave off the final `X10` (choice D) |
| Mixing up which constructor runs | `Counter c1;` uses the default constructor (`A10`); `Counter c2(5);` uses the one-parameter constructor (`B5`) |
