# 📝 NOTES – Experiment 03: Linux Commands using System Calls

## Aim
To understand and implement basic Linux command functionalities using C programming and system calls.

---

# 1. ls Command

### Purpose
The `ls` command is used to display all files and directories present in the current directory.

### Header Files
```c
#include <stdio.h>
#include <dirent.h>
```

### Functions Used

#### `opendir()`
- Opens a directory.
- Returns a pointer of type `DIR`.
- Returns `NULL` if the directory cannot be opened.

#### `readdir()`
- Reads one entry (file or folder) from the opened directory.
- Returns a pointer to a `struct dirent`.
- Returns `NULL` when no more entries are available.

#### `closedir()`
- Closes the opened directory and frees associated resources.

### Workflow
1. Open the current directory using `opendir(".")`.
2. Check whether the directory opened successfully.
3. Read each entry using `readdir()`.
4. Print the name of each file or directory.
5. Close the directory using `closedir()`.

### Output
Displays all files and folders in the current working directory.

---

# 2. grep Command

### Purpose
The `grep` command searches for a specific word or pattern inside a text file.

### Header Files
```c
#include <stdio.h>
#include <string.h>
```

### Functions Used

#### `fopen()`
Opens a file for reading.

#### `fgets()`
Reads one line at a time from the file.

#### `strstr()`
Searches whether a word exists inside a string.

#### `fclose()`
Closes the file after reading.

### Workflow
1. Open the text file.
2. Read the file line by line.
3. Search each line for the required word.
4. Print matching lines.
5. Close the file.

### Output
Displays all lines containing the searched word.

---

# 3. pwd Command

### Purpose
The `pwd` command displays the current working directory.

### Header Files
```c
#include <stdio.h>
#include <unistd.h>
```

### Function Used

#### `getcwd()`
Returns the absolute path of the current working directory.

### Workflow
1. Create a character array.
2. Call `getcwd()`.
3. Print the returned directory path.

### Output
Displays the absolute path of the current directory.

---

# 4. mkdir Command

### Purpose
The `mkdir` command creates a new directory.

### Header Files
```c
#include <stdio.h>
#include <sys/stat.h>
```

### Function Used

#### `mkdir()`
Creates a new directory with specified permissions.

### Workflow
1. Take the directory name as input.
2. Call `mkdir()`.
3. Check whether creation was successful.
4. Display an appropriate message.

### Output
Creates a new folder in the current directory.

---

# 5. rm Command

### Purpose
The `rm` command deletes a file from the current directory.

### Header Files
```c
#include <stdio.h>
```

### Function Used

#### `remove()`
Deletes the specified file.

### Workflow
1. Read the filename.
2. Call `remove()`.
3. Display whether deletion was successful.

### Output
Removes the selected file.

---

# 6. cp Command

### Purpose
The `cp` command creates a copy of a file.

### Header Files
```c
#include <stdio.h>
```

### Functions Used

#### `fopen()`
Opens source and destination files.

#### `fgetc()`
Reads one character from the source file.

#### `fputc()`
Writes one character to the destination file.

#### `fclose()`
Closes both files after copying.

### Workflow
1. Open the source file.
2. Create/open the destination file.
3. Read characters from the source.
4. Write each character to the destination.
5. Close both files.

### Output
Creates an exact copy of the source file.

---

# Important Functions Summary

| Function | Purpose |
|----------|---------|
| `opendir()` | Opens a directory |
| `readdir()` | Reads directory entries |
| `closedir()` | Closes the directory |
| `fopen()` | Opens a file |
| `fgets()` | Reads one line from a file |
| `strstr()` | Searches for a substring |
| `fclose()` | Closes a file |
| `getcwd()` | Returns current working directory |
| `mkdir()` | Creates a new directory |
| `remove()` | Deletes a file |
| `fgetc()` | Reads one character |
| `fputc()` | Writes one character |

---

# Compilation Commands

```bash
gcc readdir.c -o readdir
./readdir
```

```bash
gcc grep.c -o grep
./grep
```

```bash
gcc pwd.c -o pwd
./pwd
```

```bash
gcc mkdir.c -o mkdir
./mkdir
```

```bash
gcc rm.c -o rm
./rm
```

```bash
gcc cp.c -o cp
./cp
```

---

# Key Learning Outcomes

- Learned how Linux commands work internally.
- Understood directory handling using `<dirent.h>`.
- Learned file handling using `fopen()`, `fclose()`, `fgetc()`, and `fputc()`.
- Understood searching text using `strstr()`.
- Learned how to obtain the current working directory using `getcwd()`.
- Learned to create and remove directories/files programmatically.
- Understood how to copy one file into another using C programming.

---

# Conclusion

This experiment demonstrated how commonly used Linux commands such as **ls, grep, pwd, mkdir, rm, and cp** can be implemented in C. It provided practical experience with directory handling, file handling, and system-level programming concepts while improving understanding of Linux system utilities.