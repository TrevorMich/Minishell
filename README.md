# README

Allowed functions:

readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs

<pre><b>readline </b>will read a line from the terminal and return it, using
       <b>prompt </b>as a prompt.  If <b>prompt </b>is <b>NULL </b>or an empty string, no
       prompt is issued.  The line returned is allocated with <a href="https://man7.org/linux/man-pages/man3/malloc.3.html">malloc(3)</a>;
       the caller must free it when finished.  The line returned has the
       final newline removed, so only the text of the line remains.</pre>


```c
char *line;

line = readline("Minishell$: ");
```

**Return value:** 

<pre><b>readline </b>returns the text of the line read.  A blank line returns
       the empty string.  If <b>EOF </b>is encountered while reading a line,
       and the line is empty, <b>NULL </b>is returned.  If an <b>EOF </b>is read with
       a non-empty line, it is treated as a newline.</pre>

***[--------rl_clear_history:----------](%E2%80%B8--------rl_clear_history:-----------)***

An history of the commands has to be stored, and that can be done by calling;

    ****add_history(**line**)***

This enables user get at the line later.

```c
rl_clear_history (void);
```

Clear the history list by deleting all of the entries.


**[--------rl_on_new_lline:-----------](%E2%80%B8--------rl_on_new_lline:-----------)**

 It is commonly used in interactive programs to handle user input, command history, and line editing features such as tab completion and line editing shortcuts.

The purpose of `rl_on_new_line` is to update the screen after outputting a newline character (`'\n'`). In some cases, when you print a newline character directly without using `rl_on_new_line`, the prompt or subsequent text might not be correctly displayed on a new line, resulting in a messy or incorrect display.

*char* line;*

 *input = readline("Enter your name: ");
    rl_on_new_line(); // Update the screen after printing the prompt*

 *printf("Hello, %s!\n", line);*

    *free(line);
    return 0;*


***--------rl_replace_new_line---------***

It is used to replace the current input line with a new line of text.

void rl_replace_line(const char *text, int clear_undo);

* `text`: A pointer to a null-terminated string that represents the new line of text to be displayed as the current input line.
* `clear_undo`: An integer value (0 or 1) that specifies whether to clear the undo information. If set to 1, the undo history for the current line is cleared; if set to 0, the undo history is preserved.

***`----------Access----------------`***

The `access` function in C is used to check the accessibility or permissions of a file. It allows you to determine whether a file can be read, written, or executed by the current user or process.

    ***
    int  	access(const char *path, int mode);***

The `access` function in C is used to check the accessibility or permissions of a file. It allows you to determine whether a file can be read, written, or executed by the current user or process. The function prototype is as follows:

The `access` function takes two parameters:

* `path`: A pointer to a null-terminated string representing the path to the file or directory you want to check.
* `mode`: An integer value that specifies the type of access to be checked. It can be one or a combination of the following constants:
  * `R_OK`: Checks for read permission.
  * `W_OK`: Checks for write permission.
  * `X_OK`: Checks for execute permission.
  * `F_OK`: Checks for the existence of the file.

The `access` function returns an integer value indicating the result of the access check. The return value can be one of the following:

* `0`: Indicates that the requested access is granted (the file can be accessed according to the specified mode).
* `-1`: Indicates an error occurred during the access check. The error can be further examined using the `errno` variable.

**-------waitpid----------**

Can wait for a specific child process to finish execution. takes in 3 parameters

    ***waitpid(pid, &status, flag);***


**-------wait3-------------**

Similar to waitpid(), it allows a parent process to wait for the termination of a specific child process or any child process, with additional options for retrieving resource usage information.

** *pid_t 	wait3(intstatus, int options, struct rusage ******rusage);***

The parameters of `wait3()` are as follows:

* `status`: A pointer to an integer variable where the exit status or termination information of the child process will be stored.
* `options`: Additional options for controlling the behavior of `wait3()`. These options can include `WNOHANG` (returns immediately if no child process has exited) and `WUNTRACED` (returns if a child process has stopped but not terminated).
* `rusage`: A pointer to a `struct rusage` variable that will be populated with resource usage information of the terminated child process.

The return value of `wait3()` is the process ID of the terminated child process or -1 if an error occurs.


**--------wait4------------**

    ***pid_twait4(pid_t pid, int *status, int options, struct rusage *rusage);***

The parameters of `wait4()` are as follows:

* `pid`: The process ID of the child process you want to wait for. It can have several possible values:
  * `-1`: Wait for any child process.
  * `0`: Wait for any child process in the same process group as the caller.
  * A positive value: Wait for a specific child process with the given process ID.
* `status`: A pointer to an integer variable where the exit status or termination information of the child process will be stored.
* `options`: Additional options for controlling the behavior of `wait4()`. These options can include `WNOHANG` (returns immediately if no child process has exited) and `WUNTRACED` (returns if a child process has stopped but not terminated).
* `rusage`: A pointer to a `struct rusage` variable that will be populated with resource usage information of the terminated child process.

The return value of `wait4()` is the process ID of the terminated child process or -1 if an error occurs.


**------sigemptyset---------**

   ** *int sigemptyset(sigset_t *set);***

The sigemptyset() function is used to initialize a signal set to be

    empty, i.e., containing no signals

The `sigemptyset()` function takes a pointer to a `sigset_t` data structure and initializes it to an empty set. The `sigset_t` data structure is an implementation-defined data type that represents a signal set.

The function returns 0 on success or -1 if an error occurs.


**------sigaddset--------------**

** *int sigaddset(sigset_t *set, int signum)***

The sigaddset() function is used to add a signal to a signal set.

Signals are software interrupts that are sent to a program by the operating system or another program. Signal sets are collections of signals that can be manipulated using a set of functions in the signal.h library.

The `sigaddset()` function takes a pointer to a `sigset_t` data structure and adds the specified signal `signum` to the signal set. The `signum` parameter represents the signal number of the signal you want to add to the set.

The function returns 0 on success or -1 if an error occurs.


**--------getcwd--------------**

The `getcwd()` function takes two parameters:

* `buf`: A pointer to a character array (`char *`) where the current working directory will be stored.
* `size`: The size of the character array `buf`.

The function returns a pointer to the character array `buf` if successful, which contains the absolute path of the current working directory. If an error occurs, it returns `NULL` and sets `errno` appropriately.

   ** *char *getcwd(char *buf, size_t size);***


**----------chdir-------------------**

The `chdir()` function is used to change the current working directory in the C programming language.

    ***int chdir(const char *path);***

The `chdir()` function takes a single parameter:

* `path`: A pointer to a null-terminated string that specifies the path of the directory to change to. It can be either an absolute path or a relative path.

The function returns 0 on success or -1 if an error occurs. The error can be determined by checking the value of the global variable `errno`.


**----------stat-------------------**

The `stat()` function in C is used to retrieve information about a file or directory. It provides various details such as file size, permissions, timestamps, and more.

    *int 	stat(const char *pathname, struct stat *statbuf);***

The `stat()` function takes two parameters:

* `pathname`: A pointer to a null-terminated string that specifies the path to the file or directory for which you want to retrieve information.
* `statbuf`: A pointer to a `struct stat` variable where the information about the file or directory will be stored.

The `struct stat` structure contains various fields to store information about the file or directory. Some of the commonly used fields of `struct stat` include:

* `st_mode`: File mode and permissions.
* `st_size`: File size in bytes.
* `st_mtime`: Time of the last modification.
* `st_atime`: Time of the last access.
* `st_ctime`: Time of the last status change (metadata modification).

The function returns 0 on success or -1 if an error occurs. The error can be determined by checking the value of the global variable `errno`.


**-------lstat----------**

The `lstat()` function in C is similar to the `stat()` function, but it is specifically used for retrieving information about symbolic links.

 ** *
    int		lstat(const char pathname, struct stat statbuf);***

The `lstat()` function takes two parameters:

* `pathname`: A pointer to a null-terminated string that specifies the path to the symbolic link or file for which you want to retrieve information.
* `statbuf`: A pointer to a `struct stat` variable where the information about the symbolic link or file will be stored.

The `struct stat` structure contains various fields to store information about the symbolic link or file, similar to the `stat()` function.

The behavior of `lstat()` differs from `stat()` when the specified path is a symbolic link. `lstat()` retrieves information about the symbolic link itself, while `stat()` follows the symbolic link and retrieves information about the target file or directory.

The function returns 0 on success or -1 if an error occurs. The error can be determined by checking the value of the global variable `errno`.


**--------fstat-------------**

The `fstat()` function in C is used to retrieve information about an open file identified by its file descriptor.

    **int	fstat(int fd, struct stat *statbuf);***

The `fstat()` function takes two parameters:

* `fd`: The file descriptor of the open file for which you want to retrieve information.
* `statbuf`: A pointer to a `struct stat` variable where the information about the file will be stored.

The `struct stat` structure contains various fields to store information about the file, similar to the `stat()` function.

The function returns 0 on success or -1 if an error occurs. The error can be determined by checking the value of the global variable `errno`.


**--------open-------------**

The `open()` function in C is used to open a file or create a new file if it doesn't exist. It provides access to files using file descriptors.

    **int	open(const char *pathname, int flags, mode_t mode);***

The `open()` function takes three parameters:

* `pathname`: A pointer to a null-terminated string that specifies the path to the file you want to open or create.
* `flags`: An integer that specifies the flags for opening the file, such as read-only, write-only, or read-write access, along with additional options like creating a new file or truncating an existing file.
* `mode`: A file permission mode that specifies the access permissions for the newly created file, applicable only when creating a new file.

The function returns a file descriptor on success, which is a non-negative integer representing the opened file, or -1 if an error occurs. The error can be determined by checking the value of the global variable `errno`.

Here are some commonly used flags for the `flags` parameter:

* `O_RDONLY`: Open the file in read-only mode.
* `O_WRONLY`: Open the file in write-only mode.
* `O_RDWR`: Open the file in read-write mode.
* `O_CREAT`: Create a new file if it doesn't exist.
* `O_TRUNC`: Truncate the file to zero length if it exists.
* `O_APPEND`: Append data to the end of the file.

**-------opendir/readdir/closedir----------------**

The `opendir()` function in C is used to open a directory and obtain a directory stream, which is a pointer to a structure containing information about the directory's contents.

    ***DIR *opendir(const char *name);***

    struct dirent
	{
		ino_t          d_ino;       /* inode number*/
		off_t          d_off;       /* offset to the next dirent*/
		unsigned short d_reclen;    /* length of this record*/
		unsigned char  d_type;      /* type of file; not supported by all file system 		    types*/
		char           d_name[256]; /* filename */
	};

The `opendir()` function takes one parameter:

* `name`: A pointer to a null-terminated string that specifies the name of the directory you want to open.

The function returns a pointer to a `DIR` structure on success, which represents the directory stream, or `NULL` if an error occurs. The error can be determined by checking the value of the global variable `errno`.

The `DIR` structure contains implementation-specific details about the directory stream. It typically includes a file descriptor, the current position within the directory, and other internal data. You don't have direct access to the members of this structure; instead, you use it with other directory-related functions.

Once you have opened a directory using `opendir()`, you can use other functions like `readdir()` and `closedir()` to retrieve the contents of the directory and close the directory stream, respectively.

The `opendir()` function takes one parameter:

* `name`: A pointer to a null-terminated string that specifies the name of the directory you want to open.

The function returns a pointer to a `DIR` structure on success, which represents the directory stream, or `NULL` if an error occurs. The error can be determined by checking the value of the global variable `errno`.

The `DIR` structure contains implementation-specific details about the directory stream. It typically includes a file descriptor, the current position within the directory, and other internal data. You don't have direct access to the members of this structure; instead, you use it with other directory-related functions.

Once you have opened a directory using `opendir()`, you can use other functions like `readdir()` and `closedir()` to retrieve the contents of the directory and close the directory stream, respectively.

The `opendir()` function takes one parameter:

* `name`: A pointer to a null-terminated string that specifies the name of the directory you want to open.

The function returns a pointer to a `DIR` structure on success, which represents the directory stream, or `NULL` if an error occurs. The error can be determined by checking the value of the global variable `errno`.

The `DIR` structure contains implementation-specific details about the directory stream. It typically includes a file descriptor, the current position within the directory, and other internal data. You don't have direct access to the members of this structure; instead, you use it with other directory-related functions.

Once you have opened a directory using `opendir()`, you can use other functions like `readdir()` and `closedir()` to retrieve the contents of the directory and close the directory stream, respectively.

The `opendir()` function takes one parameter:

* `name`: A pointer to a null-terminated string that specifies the name of the directory you want to open.

The function returns a pointer to a `DIR` structure on success, which represents the directory stream, or `NULL` if an error occurs. The error can be determined by checking the value of the global variable `errno`.

The `DIR` structure contains implementation-specific details about the directory stream. It typically includes a file descriptor, the current position within the directory, and other internal data. You don't have direct access to the members of this structure; instead, you use it with other directory-related functions.

Once you have opened a directory using `opendir()`, you can use other functions like `readdir()` and `closedir()` to retrieve the contents of the directory and close the directory stream, respectively.


**--------isatty-------------**

### Minishell Operations

	* Reads input from user's terminal
	* Breaks the input into words and operators. These tokens are separated by metacharacters
	* Parses the tokens into simple and compound commands
	* Performs the various shell expansions, breaking the expanded tokens into lists of filenames and commands and arguments.
	* Performs any necessary redirections  and removes the redirection operators and their operands from the argument list.
	*Executes the command (see Executing Commands).
	* Optionally waits for the command to complete and collects its exit status (see Exit Status).

	Command is entered and if length is non-null, keep it in history.
	Parsing : Parsing is the breaking up of commands into individual words and strings
	Checking for special characters like pipes, etc is done
	Checking if built-in commands are asked for. If pipes are present, handling pipes.
	Executing system commands and libraries by forking a child and calling execvp.
	Printing current directory name and asking for next input.

#### Control Operators
Includes the following symbols:
`&   &&   (   )   ;   ;;   <newline>   |   ||`

#### Redirection Operators
`<     >     >|     <<     >>     <&     >&     <<-     <>`

