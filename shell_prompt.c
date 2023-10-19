#include "shell.h"

/**
 * ctrl_c_handle - ignore ^C input
 * @n: prameter
 */
void ctrl_c_handle(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * ctrl_d_handle - exits program if Ctrl-D was pressed
 * @i: characters read
 * @command: user's command
 * @env: environmental variable linked list
 */
void ctrl_d_handle(int i, char *command, list_t *env)
{
	if (i == 0)
	{
		free(command);
		free_linkedlist(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * space_ignore - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *space_ignore(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * builtin_func - handles builtins (exit, env, cd)
 * @token: user's command
 * @env: environmental variable
 * @num: take in nth user command to write error message
 * @command: command to free
 * @en: enviro
 * Return: 1 if builtin, 0 if not
 */
int builtin_func(char **token, list_t *env, int num, char **command, char **en)
{
	int i = 0, j;

	/* if user types "exit", free cmd tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		i = __exit(token, env, num, command, en);
	}
	/* if user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		free_double_ptr(token);
		if (en != NULL)
		{
			for (j = 0; en[j] != NULL; j++)
		
			{
		
				write(1, en[j], _strlen(en[j]));
		
				write(1, "\n", 1);
	
			}
		}
		/*_env(token, env);*/
		i = 1;
	}
	/* if user types "cd" , it will change directory */
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = _cd(token, env, num);
	}
	/*if user types "setenv", create or modify linked list node */
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	/* if user types "setenv", remove linked list node */
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}

	return (i);
}

/**
 * shell_prompt - gets user commands and executes it if applicable
 *
 * @en: envrionmental variables
 *
 * Return: 0 if success
 */
int shell_prompt(char **en)
{
	list_t *env;

	char *input, *token, **tokens;
	size_t input_size, n;
	int command_line_num = 0, ExitState = 0;

	env = env_linked_list(en);
	do {
		command_line_num++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive_mode(env, en);

		signal(SIGINT, ctrl_c_handle);
		input = NULL;
		input_size = 0;
		input_size = _getline(&input);
		ctrl_d_handle(input_size, input, env);
		token = input;
		input = space_ignore(input);
		n = 0;
		while (input[n] != '\n')
			n++;
		input[n] = '\0';
		if (input[0] == '\0')
		{
			free(token);
			continue;
		}
		tokens = NULL;
		tokens = _strtok(input, " ");
		if (token != NULL)
			free(token);
		ExitState = builtin_func(tokens, env, command_line_num, NULL, en);
		if (ExitState)
			continue;
		ExitState = _execve(tokens, env, command_line_num);
	} while (1);
	return (ExitState);
}
