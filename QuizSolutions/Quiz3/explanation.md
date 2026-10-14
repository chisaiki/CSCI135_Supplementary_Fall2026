# Quiz 3 — Scope, Default Arguments, and `static`

This quiz tests three ideas: **variable scope (shadowing)**, **default arguments**, and **`static` local variables**.

## The Answer

```
call 1: total is 110
call 2: total is 120
report sees 120
main total is 1
```

## Key Takeaways

1. A local variable with the same name as a global **shadows** it, but only inside the function where it is declared. Other functions still see the global.
2. When you call a function with no arguments, **every** parameter with a default uses its default, not just the first one.
3. A `static` local variable is created **once** and keeps its value between calls. It is not reset to `0` each time.

## Step-by-Step Trace

There are **two different variables** named `total`:

| Variable | Where it lives | Starting value | Who can see it |
|---|---|---|---|
| global `total` | outside every function | `100` | `tally` and `report` |
| local `total` | inside `main` | `1` | only `main` |

### `int total = 1;`
Creates a **new** variable inside `main`. It does not change the global `total`, which is still `100`.

### `tally();`
No arguments are passed, so both defaults are used: `amount = STEP = 5` and `times = 2`.

- `calls` starts at `0`, then `calls++` makes it `1`.
- `tally` has no local `total`, so `total` here means the **global** one.
- `total += 5 * 2` → `100 + 10 = 110`.

Prints: `call 1: total is 110`

### `tally(10, 1);`
Both arguments are given, so the defaults are ignored: `amount = 10`, `times = 1`.

- `calls` is `static`, so it still holds `1` from last time. `calls++` makes it `2`.
- `total += 10 * 1` → `110 + 10 = 120`.

Prints: `call 2: total is 120`

### `report();`
`report` also has no local `total`, so it reads the **global** one, which is now `120`.

Prints: `report sees 120`

### `cout << "main total is " << total << endl;`
We're back in `main`, where the local `total` shadows the global. Nothing ever changed the local one, so it is still `1`.

Prints: `main total is 1`

---

## Why the Other Choices Are Wrong

### B

```
call 1: total is 110
call 2: total is 120
report sees 120
main total is 120
```

The first three lines are right; the last line is wrong. This answer assumes `main` prints the **global** `total`. But `main` declares its own `int total = 1;`, which shadows the global inside `main`. `tally` changed the global, not `main`'s local, so `main` still prints `1`.

### C

```
call 1: total is 105
call 2: total is 115
report sees 115
main total is 1
```

This answer only applies the **first** default argument. It treats `tally()` as `5 * 1 = 5`, giving `105`. But `times` also has a default of `2`, so `tally()` is really `tally(5, 2)`, which adds `5 * 2 = 10` and gives `110`. Because the first call is off by 5, every line after it is off by 5 too (`115` instead of `120`). The last line (`1`) is right.

### D

```
call 1: total is 110
call 1: total is 120
report sees 120
main total is 1
```

The totals are all right, but the second line says `call 1` instead of `call 2`. This answer treats `calls` like a normal local variable that resets to `0` on every call. Because it is declared `static`, the line `static int calls = 0;` runs only **once**, the first time `tally` is called. On the second call, `calls` still holds `1`, and `calls++` makes it `2`.

---

## Common Mistakes to Avoid

| Mistake | What happens |
|---|---|
| Thinking a local variable in `main` is visible in other functions | You'd expect `tally` to add to `main`'s `total` (`1`) instead of the global (`100`) |
| Thinking a local variable changes the global with the same name | You'd expect `main` to print `120` (choice B) |
| Only using the first default argument | You'd compute `5 * 1` instead of `5 * 2` (choice C) |
| Treating `static` locals like normal locals | The counter resets every call, so both calls print `call 1` (choice D) |
