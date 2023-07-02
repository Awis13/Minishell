#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

void cmd_exit(char **args);
void cmd_echo(char **args);
void cmd_pwd(char **args);
void cmd_ls(char **args);
void cmd_cd(char **args);

void cmd_exit(char **args)
{
    // free any allocated resources here
    ft_printf("Exiting...\n");
    free(args);
    exit(0);
}

void cmd_echo(char **args)
{
    int i = 1;
    while (args[i])
    {
        if (i > 1)
        {
            ft_printf(" ");
        }
        ft_printf("%s", args[i]);
        i++;
    }
    ft_printf("\n");
    free(args);
}

void cmd_pwd(char **args)
{
    char cwd[MAX_PATH_LENGTH];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        ft_printf("%s\n", cwd);
    }
    else
    {
        ft_printf("Error: Unable to get current working directory.\n");
    }
    free(args);
}

void cmd_cd(char **args)
{
    if (args[1] == NULL)
    {
        ft_printf("Error: Expected argument to \"cd\".\n");
    }
    else
    {
        // Remove trailing newline
        size_t len = ft_strlen(args[1]);
        if (len > 0 && args[1][len - 1] == '\n')
            args[1][len - 1] = '\0';

        if (chdir(args[1]) != 0)
        {
            perror("chdir");
            ft_printf("Error: Unable to change directory to '%s'.\n", args[1]);
        }
        else
        {
            char cwd[MAX_PATH_LENGTH];
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                ft_printf("Current directory: %s\n", cwd);
            }
            else
            {
                ft_printf("Error: Unable to get current working directory.\n");
            }
        }
    }
    free(args);
}



char *find_executable(char *command)
{
    char *path_env = getenv("PATH");
    if (path_env == NULL)
    {
        ft_printf("Error: PATH environment variable not set.\n");
        return NULL;
    }

    char *path = strdup(path_env);
    char *dir = strtok(path, ":");
    while (dir != NULL)
    {
        char executable_path[MAX_PATH_LENGTH];
        snprintf(executable_path, sizeof(executable_path), "%s/%s", dir, command);
        if (access(executable_path, X_OK) == 0)
        {
            free(path);
            return strdup(executable_path);
        }

        dir = strtok(NULL, ":");
    }

    free(path);
    ft_printf("Error: Executable \"%s\" not found.\n", command);
    return NULL;
}

struct
{
    char *name;
    void (*func)(char **);
} cmd_table[] = {
    {"exit", cmd_exit},
    {"echo", cmd_echo},
    {"pwd", cmd_pwd},
    {"cd", cmd_cd},
    // add more commands here
};

void print_intro(void)
{
    ft_printf("   _____  .__       .__  _________.__           .__  .__   \n");
    ft_printf("  /     \\ |__| ____ |__|/   _____/|  |__   ____ |  | |  |  \n");
    ft_printf(" /  \\ /  \\|  |/    \\|  |\\_____  \\ |  |  \\_/ __ \\|  | |  |  \n");
    ft_printf("/    Y    \\  |   |  \\  |/        \\|   Y  \\  ___/|  |_|  |__\n");
    ft_printf("\\____|__  /__|___|  /__/_______  /|___|  /\\___  >____/____/\n");
    ft_printf("        \\/        \\/           \\/      \\/     \\/           \n");
    ft_printf("Type 'exit' to exit.\n");
}

int main(void)
{
    print_intro();

    while (1)
    {
        ft_printf("# ");
        char *line = get_next_line(0);
        if (!line)
            break;

        char **args = ft_split(line, ' '); // parse the line into arguments
        free(line); // free the line after splitting

        if (!args || !args[0])
        {
            free(args);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            cmd_exit(args);
            break;
        }

        size_t i = 0;
        while (i < sizeof(cmd_table) / sizeof(cmd_table[0]))
        {
            if (strcmp(args[0], cmd_table[i].name) == 0)
            {
                cmd_table[i].func(args); // call the appropriate function
                break;
            }
            i++;
        }

        if (i == sizeof(cmd_table) / sizeof(cmd_table[0]))
        {
            char *executable_path = NULL;
            if (strchr(args[0], '/') != NULL)
            {
                // Command contains a path separator, treat it as an absolute or relative path
                if (access(args[0], X_OK) == 0)
                {
                    executable_path = strdup(args[0]);
                }
            }
            else
            {
                // Command does not contain a path separator, search for the executable
                size_t cmd_length = strlen(args[0]);
                if (cmd_length > 0 && args[0][cmd_length - 1] == '\n')
                {
                    args[0][cmd_length - 1] = '\0';  // Remove the newline character
                }
                executable_path = find_executable(args[0]);
            }

            if (executable_path != NULL)
            {
                pid_t pid = fork();
                if (pid == 0)
                {
                    // Child process
                    execv(executable_path, args);
                    ft_printf("Error: Failed to execute \"%s\".\n", args[0]);
                    free(executable_path);
                    free(args);
                    exit(1);
                }
                else if (pid < 0)
                {
                    // Forking error
                    ft_printf("Error: Forking process failed.\n");
                }
                else
                {
                    // Parent process
                    int status;
                    waitpid(pid, &status, 0);
                }
            }
            free(executable_path);
            free(args);
        }
    }
    return 0;
}
