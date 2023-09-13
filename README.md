Simple Shell Project (0x16)
This is a group project for the ALX School. The project aims to create a simple UNIX command interpreter (shell) in the C programming language.

Project Description
The goal of this project is to create a basic shell that can execute simple UNIX commands. The shell should display a prompt, accept user commands, execute them, and handle basic features like arguments, PATH, built-in commands, and logical operators.

How to Use
To compile the shell, use the following command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Project Tasks
The project is divided into multiple tasks, each building upon the previous ones. Tasks include implementing features like handling arguments, built-in commands, and logical operators.

passes the Betty checks.
 a basic UNIX command line interpreter.
Display a prompt, wait for user input, and execute simple commands.
Handle command lines with arguments.
Handle the PATH to find commands.
Avoid calling fork if the command doesn't exist.
Implement the exit built-in command.
Implement the env built-in command to print the current environment.
Write your own getline function without using the getline function.
Handle arguments without using strtok.
Handle arguments for the exit built-in command.
Implement the setenv and unsetenv built-in commands.
Implement the cd built-in command to change the current directory.
Handle the command separator ;.
Handle the logical operators && and ||.
Implement the alias built-in command.
Handle variables replacement, including $? and $$.
Handle comments in the input.
Allow the shell to take a file as a command line argument.
