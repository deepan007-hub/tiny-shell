# Mini Shell in C

## Overview

This project is a simple **Unix-like mini shell written in C**.
The shell reads commands from the user, parses them into arguments, creates a child process using `fork()`, and executes the command using `execvp()`.

This project demonstrates fundamental **operating system and system programming concepts** such as process creation, command parsing, and process synchronization.

---

## Features

* Interactive shell prompt
* Command execution using system programs
* Argument parsing using `strtok()`
* Process creation using `fork()`
* Program execution using `execvp()`
* Parent process waits for child using `wait()`
* Built-in `exit` command to terminate the shell

---

## Concepts Demonstrated

This project helps understand several core concepts in **system programming**:

* Process creation (`fork`)
* Program execution (`execvp`)
* Parent-child process relationship
* Command line parsing
* Process synchronization (`wait`)
* Linux/Unix command execution

---

## Project Structure

```
tiny-shell/
│
├── shell.c
└── README.md
```

---

## How It Works

1. The shell prints a prompt `tsh>`.
2. The user enters a command (example: `ls -la`).
3. The input is read using `fgets()`.
4. The command is split into arguments using `strtok()`.
5. `fork()` creates a child process.
6. The child executes the command using `execvp()`.
7. The parent waits for the child process to finish.
8. The shell returns to the prompt.

---

## Example Usage

```
tsh> pwd
/home/user/projects

tsh> ls
shell.c
README.md

tsh> echo Hello
Hello

tsh> exit
Exiting shell...
```

---

## Compilation

Compile the program using GCC:

```
gcc shell.c -o shell
```

Run the shell:

```
./shell
```

---

## Requirements

This program uses **POSIX system calls**, so it works on:

* Linux
* macOS
* WSL (Windows Subsystem for Linux)

It will not run on native Windows compilers without a POSIX environment.

---

## Learning Outcome

By building this mini shell, I gained hands-on experience with:

* Process management in Unix systems
* System calls and OS interaction
* Command parsing in C
* Understanding how real shells execute commands

---

## Future Improvements

* Add support for built-in commands (`cd`, `pwd`)
* Implement background processes (`&`)
* Add command history
* Implement piping (`|`)
* Improve error handling

---

## Author

Deepan Raaj
Computer Science Student | Embedded Systems Enthusiast
