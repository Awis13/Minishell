#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"

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

struct
{
    char *name;
    void (*func)(char **);
} cmd_table[] = {
    { "exit", cmd_exit },
    { "echo", cmd_echo },
    { "pwd", cmd_pwd },
    // add more commands here
};

int main(void)
{
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
