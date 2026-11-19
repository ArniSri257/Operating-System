# Operating-System
This is a GitHub repository for my Operating System lab

PROGRAM#1
Objective: Write programs using the following system calls of the LINUX operating system: fork(), exec(), getpid(), exit(), wait(), close(), stat(), opendir(), readdir(). 

Code:
1. getpid()
Purpose: Returns the Process ID (PID) of the currently running process.
Program
#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("My Process ID is %d\n", getpid());
    return 0;
}
Compile and Run
gcc getpid.c -o getpid
./getpid

2. fork()
Purpose: Creates a new child process.
After calling fork(), there are two processes:   a)Parent Process   and   b)Child Process 
Program
#include <stdio.h>
#include <unistd.h>
int main()
{
    fork();
    printf("Hello from Process %d\n", getpid()); 
    return 0;
}

Compile and Run
gcc fork.c -o fork

./fork

3. wait()
Purpose: Makes the parent process wait until the child process finishes.
Program
#include <stdio.h>#include <unistd.h>#include <sys/wait.h>
int main()
{
    if(fork()==0)
    {
        printf("Child Process\n");
    }
    else
    {
        wait(NULL);
        printf("Parent Process\n");
    }

    return 0;
}
Compile and Run
gcc wait.c -o wait

./wait


4. exec()
Purpose: Replaces the current program with another program.
Example: executing the ls command.
#include <stdio.h>#include <unistd.h>
int main()
{
    execl("/bin/ls","ls","-l",NULL);

    printf("This line will not execute.");

    return 0;
}

Compile and Run
gcc exec.c -o exec

./exec


5. close()
Purpose: Closes an open file descriptor.
Program
#include <stdio.h>#include <fcntl.h>#include <unistd.h>
int main()
{
    int fd = open("sample.txt", O_RDONLY);

    if(fd!=-1)
    {
        printf("File Opened\n");

        close(fd);

        printf("File Closed\n");
    }

    return 0;
}

Compile
Create the file first: touch sample.txt
gcc close.c -o close
./close


6. stat()
Purpose: Displays information about a file.
Program
#include <stdio.h>#include <sys/stat.h>
int main()
{
    struct stat file;

    stat("sample.txt",&file);

    printf("Size = %ld bytes\n",file.st_size);

    return 0;
}

Compile and Run
gcc stat.c -o stat

./stat


7. opendir()
Purpose: Opens a directory.
Program
#include <stdio.h>#include <dirent.h>
int main()
{
    DIR *dir;

    dir=opendir(".");

    if(dir)
    {
        printf("Directory Opened Successfully\n");
        closedir(dir);
    }

    return 0;
}

Compile and Run
 
gcc opendir.c -o opendir

./opendir



8. readdir()
Purpose: Lists all files inside a directory.

Program
#include <stdio.h>#include <dirent.h>
int main()
{
    struct dirent *entry;

    DIR *dir = opendir(".");

    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}

Compile and Run
gcc readdir.c -o readdir

./readdir


PROGRAM#2
Objective: Write programs using the I/O system calls of LINUX operating system (open, read, write, etc)

For Open the file 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    fd = open("sample.txt", O_CREAT | O_WRONLY, 0644);
    if(fd == -1)
    {
        printf("Error opening file\n")
        return 1;
    }
     printf("File opened successfully.\n");
     close(fd);
     return 0;
}
For read the file :
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
int main()
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    // Open the file in read-only mode
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // Read data from the file
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1)
    {
        printf("Error reading file.\n");
        close(fd);
        return 1;
    }
    // Add null character to make it a string
    buffer[bytesRead] = '\0';
    printf("File Contents:\n");
    printf("%s", buffer);
              // Close the file
    close(fd);     return 0;  }

For Write : 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd;
    char message[] = "Hello!\nWelcome to Linux System Calls.\nThis file is created using write() system call.\n";
               // Open or create the file
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // Write data to the file
    if (write(fd, message, strlen(message)) == -1)
    {
       printf("Error writing to file.\n");
        close(fd);
        return 1;
    }
    printf("Data written successfully to output.txt\n");
               // Close the file
    close(fd);
     return 0;  }

Explanation of the Code:
Headers:
fcntl.h: Contains declarations for open().
unistd.h: Contains declarations for read(), write(), and close().
File Descriptors:
open(): Opens a file and returns a file descriptor (an integer that refers to the opened file).
read(): Reads data from the file associated with the file descriptor.
write(): Writes data to a file associated with the file descriptor.
close(): Closes the file descriptor after operations.
Error Handling:
If open(), read(), or write() fails, the program prints an error message using perror() and exits.
Permissions:
In open(), the mode 0644 is used, which means:
Owner: Read and write permission.
Group: Read permission.
Others: Read permission

PROGRAM#3
Objective: Write C programs to simulate LINUX commands like ls, grep, etc.

1.Displays all files and directories in the current directory.
#include <stdio.h>#include <dirent.h>
int main()
{
    struct dirent *d;
    DIR *dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory.\n");
        return 1;
    }

    printf("Files and Directories:\n");

    while ((d = readdir(dir)) != NULL)
    {
        printf("%s\n", d->d_name);
    }

    closedir(dir);
    return 0;
}
2. Simulate grep Command

#include <stdio.h>#include <string.h>
int main()
{
    FILE *fp;
    char filename[100], word[50], line[200];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, word))
        {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}

3. Simulate pwd Command

#include <stdio.h>#include <unistd.h>
int main()
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current Directory: %s\n", cwd);
    else
        printf("Error!\n");

    return 0;
}

4. Simulate mkdir Command

#include <stdio.h>#include <sys/stat.h>
int main()
{
    char dirname[100];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    if (mkdir(dirname, 0777) == 0)
        printf("Directory created successfully.\n");
    else
        printf("Directory already exists or cannot be created.\n");

    return 0;
}

5. Simulate rm Command

#include <stdio.h>
int main()
{
    char filename[100];

    printf("Enter filename to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
        printf("File deleted successfully.\n");
    else
        printf("Unable to delete file.\n");

    return 0;
}

6. Simulate cp Command

#include <stdio.h>
int main()
{
    FILE *src, *dest;
    char source[100], target[100];
    char ch;

    printf("Enter source file: ");
    scanf("%s", source);

    printf("Enter destination file: ");
    scanf("%s", target);

    src = fopen(source, "r");
    dest = fopen(target, "w");

    if (src == NULL || dest == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");

    return 0;
}

PROGRAM#4
Objective: Write a program to create processes and threads. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

// Thread function
void* thread_function(void* arg) {
    printf("Thread: Thread ID: %lu, Process ID: %d\n", pthread_self(), getpid());
    return NULL;
}
int main() {
    // Creating a new process using fork()
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: Process ID: %d, Parent ID: %d\n", getpid(),   getppid());

        // Creating a thread in the child process
        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread in child process");
            return 1;
        }

        // Wait for the thread to finish
        pthread_join(thread, NULL);
        printf("Child Process: Thread finished, Process ID: %d\n", getpid());
        else {
        // Parent process
        printf("Parent Process: Process ID: %d, Child Process ID: %d\n", getpid(),      pid);
}

        // Creating a thread in the parent process
        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread in parent process");
            return 1;
        }

        // Wait for the thread to finish
        pthread_join(thread, NULL);
        printf("Parent Process: Thread finished, Process ID: %d\n", getpid());

        // Wait for the child process to finish
        wait(NULL);
        printf("Parent Process: Child process finished, Process ID: %d\n", getpid());
    }
return 0;  }

PROGRAM#5
Objective: Write a program solving the Producer-Consumer problem using semaphores.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define MAX_ITEMS 10
// Shared buffer
int buffer[BUFFER_SIZE];
int count = 0;  // Current count of items in the buffer
// Semaphores
sem_t empty;    // Tracks empty slots
sem_t full;     // Tracks full slots
pthread_mutex_t mutex;  // Mutex to protect buffer access
void* producer(void* arg) {
    while (1) {
        int item = rand() % 100;  // Produce an item
        sem_wait(&empty);         // Wait for an empty slot
        pthread_mutex_lock(&mutex); // Enter critical section

        // Add item to the buffer
        buffer[count] = item;
        count++;
       printf("Produced %d, Buffer count: %d\n", item, count);
       pthread_mutex_unlock(&mutex); // Exit critical section
       sem_post(&full);            // Signal that there is a new item
                  sleep(rand() % 3);  // Sleep to simulate work
    }
}
            void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);         // Wait for a full slot
        pthread_mutex_lock(&mutex); // Enter critical section
                   // Remove item from the buffer
        count--;
        int item = buffer[count];
        printf("Consumed %d, Buffer count: %d\n", item, count);
       pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&empty);            // Signal that there is an empty slot
                   sleep(rand() % 3);  // Sleep to simulate work
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);  // BUFFER_SIZE empty slots
    sem_init(&full, 0, 0);             // 0 full slots
    pthread_mutex_init(&mutex, NULL);  // Initialize mutex

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the threads to finish (they won't, in this infinite loop example)
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up (not reached in this example)
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
OUTPUT-

