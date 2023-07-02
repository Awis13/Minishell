# Minishell (Work in Progress)
![](001.png)

Minishell is a simple command-line interface program written in C. It provides a basic shell environment where users can enter commands and execute corresponding functions.

## Getting Started
To build and run Minishell, follow these steps:

1. Clone the repository:
   ```shell
   git clone https://github.com/Awis13/Minishell.git
   ```

2. Navigate to the project directory:
   ```shell
   cd minishell
   ```

3. Build the project using the provided makefile:
   ```shell
   make
   ```

4. Run the program:
   ```shell
   ./minishell
   ```

## Usage
1. Enter commands: Type commands such as `echo Hello, World!` or `pwd` and press Enter to execute them.
2. View output: The program will display the output of the executed command.
3. Exit: To exit the program, enter the `exit` command.

## Makefile
The project includes a makefile that simplifies the build process. Here are the available make targets:

- `make`: Builds the project and generates the executable file.
- `make clean`: Removes the object files generated during the build process.
- `make fclean`: Removes the object files and the executable file.
- `make re`: Performs a clean rebuild of the project.

## Future Enhancements
- More commands: Expand the `cmd_table` array in the source code to include additional commands and their corresponding functions.
- Redirection and piping: Implement functionality to handle file redirection and command piping.
- Environment variables: Support environment variables and variable substitution.
