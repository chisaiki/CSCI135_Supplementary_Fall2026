# CSCI 135 Supplementary Materials — Fall 2026

Welcome! This repo has extra materials for **CSCI 135 (Intro to C++)**: worked quiz solutions with explanations, plus short tutorials on topics that go a little beyond lecture.

Use it to **review after a quiz** or **look at a topic from another angle**. It doesn't replace lecture, the textbook, or office hours.

---

## What's Inside

```
CSCI135_Supplementary_Fall2026/
├── QuizSolutions/            Solutions and explanations for each quiz
│   ├── Quiz1/
│   │   ├── solution.cpp      Working C++ code for the quiz
│   │   └── explanation.md    Step-by-step walkthrough of the solution
│   ├── Quiz2/
│   └── ... up to Quiz10/
│
├── CursorMovementTutorial/   Moving the cursor around the terminal (Windows)
│   ├── simple.cpp            Start here: put text at a chosen row/column
│   ├── main.cpp              Build a data-entry form and animate a yoyo
│   └── screenclass.cpp       The same ideas wrapped in a Screen class
│
└── README.md                 You are here
```

### `QuizSolutions/`
There is one folder per quiz (`Quiz1` through `Quiz10`). Each folder has:
- **`solution.cpp`**: a complete program you can compile and run.
- **`explanation.md`**: how the solution works and why, including common mistakes.

Solutions are posted **after** each quiz, so some folders may be empty until then.

### `CursorMovementTutorial/`
This tutorial shows how to control *where* text appears in the console, so you can draw forms and simple animations. Read the files in this order:

1. **`simple.cpp`**: the basics. Move the cursor and print.
2. **`main.cpp`**: functions like `placeCursor()` and `clearScreen()`, used to build a form and a yoyo animation.
3. **`screenclass.cpp`**: the same tools organized into a class. Good practice for classes, constructors, and member functions.

> ⚠️ These programs use `<windows.h>`, so they only compile and run on **Windows**.

---

## How to Use This Repo

Compile and run a program
From the folder that contains the `.cpp` file:
```bash
g++ -std=c++11 solution.cpp -o solution
./solution
```
On Windows (PowerShell or Command Prompt), run it with `./solution.exe`.

Example for the cursor tutorial:
```bash
cd CursorMovementTutorial
g++ -std=c++11 simple.cpp -o simple
./simple.exe
```

### 3. Study tips
- **Try the problem yourself first.** You'll learn much more from reading a solution after you've struggled with it.
- **Read `explanation.md` alongside `solution.cpp`.** Don't just skim the code.
- **Break things on purpose.** Change a value, delete a line, recompile, and see what happens.
- **Type it out** rather than copy-pasting. It helps the syntax stick.

---

## Questions?
If something is unclear or doesn't compile, ask in class, come to office hours!!

Happy coding! 🚀
