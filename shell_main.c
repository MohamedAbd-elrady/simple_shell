#include "shell.h"

/**
 * main - simple shell program
 *
 * @ac: argument counter
 * @av: argument vectors
 * @env: environmental variables
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	shell_prompt(env);

	return (0);
}
