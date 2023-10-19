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
	char **en = __environ;


	(void)ac;
	(void)av;

	shell_prompt(env, en);

	return (0);
}
