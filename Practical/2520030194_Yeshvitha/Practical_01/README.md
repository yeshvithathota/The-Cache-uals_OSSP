# Practical 01

## Aim

To write a C program that accepts a Linux command, creates a child process using `fork()`, executes the command using `execvp()`, and makes the parent process wait using `wait()`.

## Program Description

The program accepts a Linux command from the user.

- `fork()` creates a child process.
- `execvp()` executes the entered Linux command.
- `getpid()` displays the process ID.
- `getppid()` displays the parent process ID.
- `wait()` makes the parent process wait for the child process.

## Input

```text
ls


Parent PID: 2676
Child PID: 2677
Parent PID: 2676
Program.c  input.txt  output.txt  program
Child process completed.


C:\Users\Yeshvitha\OneDrive\Pictures\Screenshots\Screenshot 2026-09-15 125621.png
