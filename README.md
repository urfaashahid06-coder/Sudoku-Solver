# Sudoku Solver (C++)

A command-line 9x9 Sudoku solver written in C++ using recursive backtracking and real-time row, column, and 3x3 subgrid validation. Built during my first semester of Software Engineering.

## Features

- **Recursive Backtracking Solver (`solvesod`):** Finds a valid solution by placing digits `1–9` into empty (`0`) cells and backtracking whenever a conflict is encountered.
- **Live Board Validation:** Checks for duplicate non-zero values across rows (`rowrepeat`), columns (`colrepeat`), and 3x3 subgrids (`minigrid`).
- **Row-by-Row Confirmation & Input Guardrails:** Validates digit ranges (`0–9`), handles non-numeric input (`cin.fail()`), and lets you accept (`A`) or re-enter (`E`) each row before moving to the next.
- **Unreachable Board Detection:** Prints a clear message if no valid solution exists for the given puzzle.

## How It Works

1. **Input & Validation:** Prompts the user row by row for 9 values (`0` represents an empty cell), checking for out-of-range numbers, invalid input types, and row/column/subgrid duplicates.
2. **Constraint Checking (`isSafe`):** Verifies whether placing a candidate number at `(row, col)` violates Sudoku rules in its row, column, or 3x3 box.
3. **Backtracking Search (`solvesod`):** Locates the next empty cell, tries numbers `1` through `9`, recurses to solve the rest of the board, and resets the cell to `0` if a dead end is reached.

## Getting Started

### Prerequisites
- A C++ compiler supporting standard C++ (e.g., `g++`, MinGW, or Visual Studio)

### Compile and Run

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o sudoku_solver
./sudoku_solver
```

## Sample Usage & Output

```text
Sudoku Solver!!
Enter 9 numbers for row 1 (0 for missing digit):
5 3 0 0 7 0 0 0 0
You entered row 1: 5 3 0 0 7 0 0 0 0
Do you want to accept this row or edit it? (A=accept / E=edit): A
...
SOLVING...
Solved Sudoku:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```