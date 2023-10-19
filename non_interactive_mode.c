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
 * remove_comment - removes/ignores everything after a '#' char
 * @input: input to be used
 *
 * Return: void
 */
void remove_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}

/**
 * semi_colon - replace ';' char with '\n' to be tokenized
 * @input: input to be used
 *
 * Return: nothing
 */
void semi_colon(char *input)
{
	int i = 0;

	if (input[i] == ';')
		input[i] = '\n';
	while (input[i] != '\0')
	{
		if (input[i] == ';')
			input[i] = '\n';
		i++;
	}
	input[i] = '\0';
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
	remove_comment(input);
	semi_colon(input);
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
	/*if (n_line != NULL)*/
		free_double_ptr(n_line);
	free_linkedlist(env);
	if (ExitState == -11)
		ExitState = 0;
	exit(ExitState);
}
