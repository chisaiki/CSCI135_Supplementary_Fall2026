# Quiz 4 — Pass by Reference vs. Pass by Value

This quiz tests two ideas: **pass by reference (`&`) vs. pass by value**, and **how arguments are matched to parameters by position**.

## The Answer

```
8 5 -4
8 -9 4
```

## Key Takeaways

1. A parameter with `&` is a **reference**: it is another name for the caller's variable. Changing it changes the original.
2. A parameter without `&` is a **copy**. Changing it inside the function has no effect on the caller's variable.
3. Arguments are matched to parameters by **position**, not by name. In `tweak(z, x, y)`, `a` refers to `z`, `b` is a copy of `x`, and `c` refers to `y`.

## Step-by-Step Trace

`tweak` has three parameters:

| Parameter | Kind | Effect on the caller |
|---|---|---|
| `int &a` | reference | changes to `a` change the original |
| `int b` | copy | changes to `b` are thrown away |
| `int &c` | reference | changes to `c` change the original |

### `int x = 3, y = 5, z = 7;`
Starting values: `x = 3`, `y = 5`, `z = 7`.

### `tweak(x, y, z);`
`a` refers to `x`, `b` is a copy of `y` (`5`), and `c` refers to `z`.

- `a = a + b` → `3 + 5 = 8`. Since `a` refers to `x`, **`x` is now `8`**.
- `b = b + c` → `5 + 7 = 12`. Only the copy changes. **`y` is still `5`**.
- `c = a - b` → `8 - 12 = -4`. Since `c` refers to `z`, **`z` is now `-4`**.

Prints: `8 5 -4`

### `tweak(z, x, y);`
The order is different. `a` refers to `z`, `b` is a copy of `x` (`8`), and `c` refers to `y`.

| Parameter | Bound to | Value going in |
|---|---|---|
| `a` | `z` (reference) | `-4` |
| `b` | copy of `x` | `8` |
| `c` | `y` (reference) | `5` |

- `a = a + b` → `-4 + 8 = 4`. Since `a` refers to `z`, **`z` is now `4`**.
- `b = b + c` → `8 + 5 = 13`. Only the copy changes. **`x` is still `8`**.
- `c = a - b` → `4 - 13 = -9`. Since `c` refers to `y`, **`y` is now `-9`**.

Prints: `8 -9 4`

---

## Why the Other Choices Are Wrong

### B

```
8 12 -4
8 -9 4
```

The second line is right; the first line is wrong. This answer prints `y` as `12`, which assumes `b` is a reference to `y`. But `b` has no `&`, so it is only a copy. The line `b = b + c` changes the copy to `12`, but `y` stays `5`.

### C

```
3 5 7
3 5 7
```

This answer treats **every** parameter as pass by value, so nothing ever changes. But `a` and `c` both have `&`, so they change the caller's variables. Only `b` is a copy.

### D

```
8 5 -4
13 5 12
```

The first line is right; the second line is wrong. This answer assumes `a`, `b`, and `c` always mean `x`, `y`, and `z`, no matter how the function is called. It runs the second call as if it were `tweak(x, y, z)` again:

- `x = 8 + 5 = 13`
- `b = 5 + (-4) = 1` (copy only)
- `z = 13 - 1 = 12`

But arguments are matched by **position**. The second call is `tweak(z, x, y)`, so `a` refers to `z`, `b` is a copy of `x`, and `c` refers to `y`.

---

## Common Mistakes to Avoid

| Mistake | What happens |
|---|---|
| Thinking every parameter is a reference | You'd expect `y` to become `12` after the first call (choice B) |
| Ignoring the `&` completely | You'd expect nothing to change, so both lines print `3 5 7` (choice C) |
| Matching parameters by name instead of by position | You'd run the second call as `tweak(x, y, z)` and get `13 5 12` (choice D) |
| Forgetting that `b`'s new value is still used inside the function | `b` is a copy, but `c = a - b` uses the **updated** `b` (`12`, then `13`), not the original |
