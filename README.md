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
g++ -std=c++17 -Wall -Wextra sudoku_solver.cpp -o sudoku_solver
./sudoku_solver
