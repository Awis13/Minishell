#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <dirent.h>

void cmd_exit(char **args);
void cmd_echo(char **args);
void cmd_pwd(char **args);

void cmd_exit(char **args __attribute__((unused)))
{
    // free any allocated resources here
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
}

void cmd_pwd(char **args __attribute__((unused)))
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        ft_printf("%s\n", cwd);
    }
    else
    {
        ft_printf("Error: Unable to get current working directory.\n");
    }
}

void cmd_ls(char **args __attribute__((unused)))
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(".")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            ft_printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        ft_printf("Error: Unable to open directory.\n");
    }
}
#include <string.h>

void cmd_cd(char **args)
{
    if (args[1] == NULL)
    {
        ft_printf("Error: Expected argument to \"cd\".\n");
    }
    else
    {
        size_t dir_length = strlen(args[1]);
        if (dir_length > 0 && args[1][dir_length - 1] == '\n') {
            args[1][dir_length - 1] = '\0';  // Remove the newline character
        }
        
        if (chdir(args[1]) != 0)
        {
            ft_printf("Error: Unable to change directory to \"%s\".\n", args[1]);
        }
        else
        {
            char cwd[1024];
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
}



struct
{
    char *name;
    void (*func)(char **);
} cmd_table[] = {
    { "exit", cmd_exit },
    { "echo", cmd_echo },
    { "pwd", cmd_pwd },
    { "ls", cmd_ls },
	{"cd", cmd_cd },
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
        if (!args || !args[0])
        {
            free(line);
            continue;
        }

        size_t i = 0;
        while (i < sizeof(cmd_table) / sizeof(cmd_table[0]))
        {
            if (ft_strncmp(args[0], cmd_table[i].name, ft_strlen(cmd_table[i].name)) == 0)
            {
                cmd_table[i].func(args); // call the appropriate function
                break;
            }
            i++;
        }

        free(line);
    }
}
