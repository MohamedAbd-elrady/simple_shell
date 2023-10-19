#include "shell.h"

/**
 * custom_ignore - ignore spaces and newlines
 *
 * @str: envrionmental variables
 *
 * Return: new string
 */
char *custom_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive_mode - when user pipes commands into shell via pipeline
 *
 * @env: envrionmental variables
 */
void non_interactive_mode(list_t *env)
{
	size_t input_size = 0, n = 0;
	int command_line_num = 0, ExitState = 0;
	char *input = NULL, *token = NULL, **n_line, **tokens;

	input_size = _getline(&input);
	if (input_size == 0)
	{
		free(input);
		exit(0);
	}
	token = input;
	input = custom_ignore(input);
	n_line = _strtok(input, "\n"); /* tokenize each command string */
	if (token != NULL)
		free(token);
	n = 0;
	while (n_line[n] != NULL)
	{
		command_line_num++;
		tokens = NULL;
		tokens = _strtok(n_line[n], " ");
		ExitState = builtin_func(tokens, env, command_line_num, n_line);
		if (ExitState)
		{
			n++;
			continue;
		}
		ExitState = _execve(tokens, env, command_line_num);
		n++;
	}
	free_double_ptr(n_line);
	free_linkedlist(env);
	exit(ExitState);
}
