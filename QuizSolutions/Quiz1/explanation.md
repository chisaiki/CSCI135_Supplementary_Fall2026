# Quiz 1 — Printing "I love Python!" 20 Times

## The Problem

Write a C++ program that prints `I love Python!` **20 times**, each on its own line, **using a loop**.

We *could* write 20 separate `cout` statements, but that would be repetitive and hard to change (what if we needed 1,000 lines?). A loop lets us write the print statement **once** and tell the computer to repeat it.

## The Solution

```cpp
#include <iostream>

using namespace std;

int main(){

    for (int i = 0; i < 20; i++){
        cout << "I love Python!" << endl;
    }

    return 0;
}
```


## Key Takeaways

1. Loops let you repeat code without copy-pasting it.
2. A `for` loop has three parts: **start**, **condition**, **update**.
3. `for (int i = 0; i < N; i++)` repeats exactly **N** times.
4. Watch out for off-by-one errors (`<` vs `<=`) and infinite loops (forgetting `i++`).

## Line-by-Line Breakdown

### `#include <iostream>`
This brings in the **input/output stream** library. Without it, C++ doesn't know what `cout` or `endl` are.

### `using namespace std;`
`cout` and `endl` live inside the `std` (standard) namespace. This line lets us write `cout` instead of `std::cout` every time.

### `int main(){ ... }`
Every C++ program starts running from `main`. Everything inside the curly braces `{ }` is what the program does.

### `for (int i = 0; i < 20; i++){ ... }`
This is the loop — the heart of the solution. A `for` loop has **three parts** inside the parentheses, separated by semicolons:

| Part | Code | What it does |
|------|------|--------------|
| 1. Initialization | `int i = 0` | Creates a counter variable `i` and starts it at `0`. Runs **once**, before the loop begins. |
| 2. Condition | `i < 20` | Checked **before every repetition**. If it's `true`, the loop body runs. If it's `false`, the loop stops. |
| 3. Update | `i++` | Runs **after every repetition**. Adds 1 to `i` (same as `i = i + 1`). |

### `cout << "I love Python!" << endl;`
This is the **loop body** — the code that gets repeated.
- `cout <<` sends text to the screen.
- `"I love Python!"` is the exact text we print.
- `endl` ends the line, so the next print starts on a new line. Without it, everything would be squished onto one line: `I love Python!I love Python!I love Python!...`

### `return 0;`
Tells the operating system the program finished successfully.

---

## Common Mistakes to Avoid

| Mistake | What happens |
|---|---|
| `i <= 20` (with `i = 0`) | Runs for 0 through 20 → **21 times** (one too many!) |
| `i = 1; i < 20` | Runs for 1 through 19 → **19 times** (one too few!) |
| Forgetting `i++` | `i` stays 0 forever, `i < 20` is always true → **infinite loop** |
| Forgetting `endl` (or `"\n"`) | All 20 phrases print on **one line** |
| Typo in the text (e.g. `"I Love python"`) | Output doesn't match exactly — autograders check every character! |
| Putting a `;` right after the `for(...)` | `for (...);` makes an empty loop; the `cout` then runs only **once** |

> `for (int i = 1; i <= 20; i++)` is **also correct** — it counts 1 through 20, which is still 20 times. Just be consistent about where you start and how you compare.


## Alternate Solution: `while` Loop

The same thing can be done with a `while` loop. Notice it uses the exact same three pieces — they're just spread out:

```cpp
int i = 0;                         // 1. Initialization

while (i < 20){                    // 2. Condition
    cout << "I love Python!" << endl;
    i++;                           // 3. Update
}
```

Both loops do the same thing. In general:
- Use a **`for` loop** when you know **how many times** to repeat (like "20 times").
- Use a **`while` loop** when you repeat **until something happens** (like "until the user types 0").


