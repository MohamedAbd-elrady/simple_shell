# 0x16. C - Simple Shell

## Simple Shell
> In this project, we coded from scratch a simple Unix shell. A shell is an interactive
> command-line interpreter. We created a shell that would utilize the command line
> interface (CLI). It allows users to type in a defined set of
> commands (e.g. "rm" to remove files, "cat" to combine word documents, etc) and have the
> operating system run the appropriate function. User can type in a command (i.e. "ls" or "rm")
> and have the files be displayed or modified in a list on the command line.
> some developers prefer the CLI to interact with the shell because their typing is quicker than
> clicking and dragging. There are a few versions of Unix shells, from the very first (Ken Thompson's)
> shell that can be activated by typing ```sh``` in the terminal to today's most popular Bash
> (Bourne Again Shell). Later versions of the shell handle memory leaks better and
> have more functionality. Our shell is a simple version that handles memory leaks
> very well and has basic functionality. You can create/write/read/open/remove
> folders, print things to the terminal, change directories, print where you are
> in the system, etc.


### Synopsis
> This repository holds all the code necessary for our custom simple shell to run.
> Our shell currently handles the executions of executables found in the
> environmental variable PATH, with or without their full paths. Sample commands
> that our shell supports include ```ls``` (```/bin/ls```), ```pwd```, ```echo```,
> ```which```, ```whereis```, etc. We've also created the following builtins.

### Builtins
* ```exit``` exits shell (```Usage: exit [status]```)
* ```env``` prints environmental variables (Usage: ```env```)
* ```setenv``` creates or modifies an environmental variable (Usage: ```setenv name value```)
* ```unsetenv``` removes an envrionmental variable (Usage: ```unsetenv name value```)
* ```cd``` changes directories (Usage: ```cd [-][~][path]```) [still working on]

### Functions and system calls used
```read```, ```signal```, ```malloc```, ```free```, ```getcwd```, ```chdir```, ```access```, ```execve```, ```wait```, ```write```,  ```exit```

### Description of what each file shows:
```
man_3_shell ------------------------ custom manpage for our simple shell
shell_main.c ----------------------- holds entrance into program
shell.h ---------------------------- holds prototypes of functions spread across all files
```
**Helper files**
```
shell_prompt.c --------------------- handles outline of shell's reprompting and executing
non_interactive_mode.c ------------- handles output when shell is called outside of shell
string.c --------------------------- duplicates a string and compares if two strings match
_strtok.c -------------------------- (custom) tokenizes user's command input and returns array
_getline.c ------------------------- (custom) reads user's typed input into buffer
_which.c --------------------------- appends command to PATHs, fleshes paths out, returns match
_cd.c ------------------------------ changes directories
linked_lists.c --------------------- adds and deletes nodes; prints and frees linked list
get_env.c -------------------------- finds and returns copy of environmental variable
env_linked_list.c ------------------ prints and creates linked list of envrionmental variables
set_unset_env.c -------------------- finds environment variable index node, sets and unsets
_execve.c -------------------------- executes and frees command, then exits program
__exit.c --------------------------- handles if user types exit or exit(value)
int_to_string.c -------------------- converts int to string to write error messages
print_error.c ---------------------- prints special error messages for certain fails
```
### Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## How To Install, Compile, and Use
Install and Compile
```
(your_terminal)$ git clone https://github.com/MohamedAbd-elrady/simple_shell.git
(your_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o hsh
```
**Non-Interactive Mode**
```
echo "ls -l" | ./hsh
```
**Interactive Mode***
Activate the shell
```
(your_terminal)$ ./hsh
$
```
Sample Usage
```
$ ls -al
total 4
-rw-rw-r-- 1 vagrant vagrant   186 oct 17 21:16 file_01.c
-rw-rw-r-- 1 vagrant vagrant    74 oct 17 21:16 file_02.c
$ echo "This is cool!"
This is cool!
$ man ./man_1_simple_shell (opens our manpage for more information)
```
Stop and return to your original shell
```
$ exit
(your_terminal)$
```


### To Do

##### mandatory
- [x] Betty
- [x] Simple shell 0.1
- [x] Simple shell 0.2 handle arguments
- [x] Simple shell 0.3 handle `PATH`
- [x] Simple shell 0.4 `exit` built-in
- [x] Simple shell 1.0 `env` built-in

##### advanced
- [x] create `getline`
- [x] create `strtok`
- [x] handle `exit` built-in with argument
- [x] implement `setenv` and `unsetenv`
- [ ] implement `cd` built-in
- [ ] handle `;`
- [ ] handle `&&`, `||`
- [ ] implement `alias`
- [ ] handle `$$`, `$?`
- [ ] handle `#`
- [ ] file as input
fix

---
### Authors
- Mohamed Abd-elrady [Linkedin](https://www.linkedin.com/in/mohamed-abd-elrady-mosa/)
- Mohamed khaled [Linkedin](https://www.linkedin.com/in/mohamed-k-kamal/)
