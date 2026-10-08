# Quiz 2 — Store Renovation Cost

## The Problem

Write a program that calculates how much a store owner spent to renovate their store. The program should **prompt the user** to enter:

1. the cost of the furniture
2. the cost of painting the shop
3. the cost of the display board

It should then **calculate and display the total** amount spent.

This quiz is about three basics: **variables**, **reading input with `cin`**, and **doing arithmetic**.

## The Solution

```cpp
#include <iostream>

using namespace std;

int main(){

    double furniture, painting, displayBoard;

    cout << "Enter the cost of the furniture: ";
    cin >> furniture;

    cout << "Enter the cost of painting the shop: ";
    cin >> painting;

    cout << "Enter the cost of the display board: ";
    cin >> displayBoard;

    double total = furniture + painting + displayBoard;

    cout << "Total amount spent on renovation: $" << total << endl;

    return 0;
}
```

### Sample Run

```
Enter the cost of the furniture: 1250.50
Enter the cost of painting the shop: 800
Enter the cost of the display board: 149.99
Total amount spent on renovation: $2200.49
```


## Key Takeaways

1. A **variable** is a named box that holds a value. Declare it before using it.
2. Use `double` for money, since prices can have cents (`19.99`).
3. **Prompt first, then read**: `cout` tells the user what to type, and `cin >>` stores what they typed.

## Line-by-Line Breakdown

### `#include <iostream>`
Gives us `cout` (output) and `cin` (input).


### `double furniture, painting, displayBoard;`
Creates three variables to hold the three costs. We use `double` instead of `int` because an `int` can only hold whole numbers. If the user typed `149.99` into an `int`, the `.99` would be lost.

Pick **descriptive names**. `furniture` says what the variable holds; `a`, `b`, `c` do not.

### `cout << "Enter the cost of the furniture: ";`
This is the **prompt**. Without it, the program would just sit there waiting, and the user wouldn't know what to type.

There's no `endl` here, so the user types their answer on the same line as the question.

### `cin >> furniture;`
Reads a number from the keyboard and stores it in `furniture`.

Think of the arrows as showing which way the data flows:
- `cout << x` : data flows **out** of `x` to the screen.
- `cin >> x` : data flows **in** from the keyboard to `x`.

### `double total = furniture + painting + displayBoard;`
Adds the three costs and stores the result in a new variable, `total`. This line has to come **after** all the `cin` lines. If it came before them, the variables would still be empty.


### `cout << "Total amount spent on renovation: $" << total << endl;`
Prints a label, then the value stored in `total`. You can chain as many `<<` pieces together as you want.

### `return 0;`
Tells the operating system the program finished successfully.

---

## Common Mistakes to Avoid

| Mistake | What happens |
|---|---|
| Using `int` instead of `double` | Cents are cut off: `149.99` becomes `149` |
| Calculating `total` **before** the `cin` lines | `total` is computed from empty variables, so it prints garbage or `0` |
| `cin << furniture` (wrong arrow direction) | Compile error. `cin` uses `>>` |
| Forgetting the prompt `cout` | The program runs, but the user sees a blank screen and doesn't know what to enter |
| Forgetting `#include <iomanip>` | Compile error: `setprecision` was not declared |
| Putting `"total"` in quotes | Prints the word `total` instead of the number |


## Alternate Solution: No Extra `total` Variable

You can do the addition right inside the `cout`:

```cpp
cout << "Total amount spent on renovation: $"
     << furniture + painting + displayBoard << endl;
```

This works, but storing the result in `total` first is usually clearer, and it lets you reuse the value later (for example, to add sales tax).
