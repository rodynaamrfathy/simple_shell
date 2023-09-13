Simple Shell Project (0x16)
This is a group project for the ALX School. The goal of this project is to create a simple UNIX command interpreter (shell) in the C programming language. The project will be completed by a team consisting of Rodyna Amr and Mohamed Essam. The project started on September 6, 2023, at 6:00 AM, and must be completed by September 21, 2023, at 6:00 AM.
Project Description
The goal of this project is to create a simple UNIX command interpreter (shell) that can handle various UNIX commands. The shell should have the following features:

Display a prompt and wait for the user to enter a command.
Execute the entered command and display the results.
Handle errors gracefully, including command not found errors.
Support command lines with arguments.
Handle the PATH to find programs.
Implement built-in commands like exit and env.
Implement features like changing the current directory with cd.
Handle logical operators like && and ||.
Handle variables and comments in the input.
Project Requirements
General
Allowed editors: vi, vim, emacs.
All files should be compiled on Ubuntu 20.04 LTS using gcc with the following options: -Wall -Werror -Wextra -pedantic -std=gnu89.
All code files should end with a newline character.
Your shell should use the Betty style, and it will be checked using betty-style.pl and betty-doc.pl.
Your shell should not have any memory leaks.
No more than 5 functions per file.
All header files should be include guarded.
Use system calls only when necessary.
Write a README.md file with a project description.
Create an AUTHORS file listing all contributors.
Output
Your shell should produce the same output as /bin/sh for all commands, including error messages.
Allowed Functions and System Calls
You are allowed to use the following functions and system calls:

access
chdir
close
closedir
execve
exit
_exit
fflush
fork
free
getcwd
getline
getpid
isatty
kill
malloc
open
opendir
perror
read
readdir
signal
stat (__xstat)
lstat (__lxstat)
fstat (__fxstat)
strtok
wait
waitpid
wait3
wait4
write
Learning Objectives
By the end of this project, you are expected to be able to explain the following concepts and topics without the need for external resources:

Who designed and implemented the original Unix operating system.
Who wrote the first version of the UNIX shell.
Who invented the B programming language, the predecessor to the C programming language.
Who is Ken Thompson.
How a shell works.
What is a PID (Process ID) and a PPID (Parent Process ID).
How to manipulate the environment of the current process.
The difference between a function and a system call.
How to create processes.
The three prototypes of the main function.
How the shell uses the PATH environment variable to find programs.
How to execute another program with the execve system call.
How to suspend the execution of a process until one of its children terminates.
What EOF (end-of-file) means.
Important Notes
The project emphasizes the importance of learning and understanding the concepts involved rather than copying solutions.
Copying code or solutions is strictly prohibited and may result in removal from the program.
Group work is encouraged, and both team members are responsible for the project.
The project should be completed with the knowledge gained during the program, and external resources should not be used.
The framework provided should be followed, and attention to detail is crucial.
The project is an opportunity to learn and not just to find solutions.
Resources
Unix shell
Thompson shell
Ken Thompson
Everything you need to know to start coding your own shell concept page

How to Run the Shell
To run the shell, compile the code with the following command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Project Tasks
The project is divided into multiple tasks, each building upon the previous ones. Here's an overview of the tasks:

Betty would be proud

Write code that passes the Betty checks.
Simple shell 0.1

Write a basic UNIX command line interpreter.
Display a prompt, wait for user input, and execute simple commands.
Simple shell 0.2

Handle command lines with arguments.
Simple shell 0.3

Handle the PATH to find commands.
Avoid calling fork if the command doesn't exist.
Simple shell 0.4

Implement the exit built-in command.
Simple shell 1.0

Implement the env built-in command to print the current environment.
Simple shell 0.1.1

Write your own getline function without using the getline function.
Simple shell 0.2.1

Handle arguments without using strtok.
Simple shell 0.4.1

Handle arguments for the exit built-in command.
setenv, unsetenv

Implement the setenv and unsetenv built-in commands.
cd

Implement the cd built-in command to change the current directory.
;

Handle the command separator ;.
&& and ||

Handle the logical operators && and ||.
alias

Implement the alias built-in command.
Variables

Handle variables replacement, including $? and $$.
Comments

Handle comments in the input.
File as input

Allow the shell to take a file as a command line argument.
Please note that these tasks are progressive, and you should complete each task before moving on to the next one.

Project Collaboration
This project is a group project, and both team members (Rodyna Amr and Mohamed Essam) are responsible for its completion. Effective collaboration and understanding of the codebase are crucial to the success of the project
