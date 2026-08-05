# Experiment 02 – Input/Output System Calls in Linux

## 🎯 Objective

To understand and implement basic Linux Input/Output (I/O) system calls used for file handling. This experiment demonstrates how to create, open, read, write, and close files using Linux system calls.

---

## 📚 Introduction

Linux provides a set of **system calls** that allow a program to communicate directly with the operating system. File handling is one of the most common uses of these system calls.

Unlike standard C library functions (`fopen()`, `fscanf()`, etc.), Linux system calls operate at a lower level and provide direct access to the operating system.

The main system calls covered in this experiment are:

- `open()` – Opens or creates a file.
- `read()` – Reads data from a file.
- `write()` – Writes data into a file.
- `close()` – Closes the opened file.

---

# 1. open() System Call

## Purpose

The `open()` system call is used to open an existing file or create a new file.

### Syntax

```c
fd = open("sample.txt", O_CREAT | O_WRONLY, 0644);
```

### Explanation

- `sample.txt` → Name of the file.
- `O_CREAT` → Creates the file if it does not already exist.
- `O_WRONLY` → Opens the file in write-only mode.
- `0644` → Sets file permissions.
- `fd` → File descriptor returned by the operating system.

If the file opens successfully, a file descriptor is returned.

If opening the file fails, `open()` returns **-1**.

---

# 2. read() System Call

## Purpose

The `read()` system call reads data from a file into a buffer.

### Syntax

```c
read(fd, buffer, BUFFER_SIZE);
```

### Explanation

- `fd` → File descriptor of the opened file.
- `buffer` → Stores the data read from the file.
- `BUFFER_SIZE` → Maximum number of bytes to read.

After reading, the buffer is displayed on the terminal.

---

# 3. write() System Call

## Purpose

The `write()` system call writes data from the program into a file.

### Syntax

```c
write(fd, message, strlen(message));
```

### Explanation

- `fd` → File descriptor.
- `message` → Data to be written.
- `strlen(message)` → Number of characters to write.

If the write operation is successful, the specified message is stored inside the file.

---

# 4. close() System Call

## Purpose

The `close()` system call closes the opened file after all operations are completed.

### Syntax

```c
close(fd);
```

Closing the file releases the file descriptor and informs the operating system that the program has finished using the file.

---

# File Descriptor

Whenever a file is opened, Linux assigns it a **File Descriptor (FD)**.

A file descriptor is simply an integer that uniquely identifies an opened file.

Example:

```
sample.txt
      │
      ▼
Linux opens the file
      │
      ▼
fd = 3
```

All subsequent operations such as `read()`, `write()`, and `close()` use this file descriptor instead of the file name.

---

# File Permissions (0644)

The permission value **0644** means:

| User | Permission |
|------|------------|
| Owner | Read + Write |
| Group | Read |
| Others | Read |

This allows the owner to modify the file while everyone else can only read it.

---

# Error Handling

Each system call should be checked for errors.

Example:

```c
if(fd == -1)
{
    printf("Error opening file");
    return 1;
}
```

If the system call fails, it returns **-1**, allowing the program to detect the error and terminate safely.

---

# Programs Included

- Open a file using `open()`
- Read data using `read()`
- Write data using `write()`
- Close the file using `close()`

---

# Learning Outcome

After completing this experiment, I learned:

- How Linux system calls differ from standard C file handling functions.
- How to create and open files using `open()`.
- How to read file contents using `read()`.
- How to write data into files using `write()`.
- How to safely close files using `close()`.
- The concept of a File Descriptor.
- The importance of checking errors while performing file operations.

---

## Conclusion

This experiment provided practical knowledge of Linux Input/Output system calls used for file handling. It demonstrated how programs interact directly with the operating system to create, open, read, write, and close files. Understanding these system calls forms the foundation for advanced Linux programming and operating system concepts.