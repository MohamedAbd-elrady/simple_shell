#include "shell.h"

/**
 * custom_atoi - custom atoi converts string to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int custom_atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (num);
}

/**
 * __exit - frees user input and then exits main program with a value
 * @str: user's command into shell
 * @env: bring in environmental variable to free at error
 * @num: bring in nth user command line input to print in error message
 * @command: bring in command to free
 * Return: 0 if success 2 if fail
 */
int __exit(char **str, list_t *env, int num, char **command)
{
	int exit_value = 0;

	if (str[1] != NULL)
		exit_value = custom_atoi(str[1]);

	if (exit_value == -1)
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linkedlist(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(exit_value);
}
