#include "shell.h"

/**
 * custom_token_size - returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: number of tokens
 */
int custom_token_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delm)
		{
			num_delm++;
		}
		i++;
	}
	return (num_delm);
}


/**
 * custom_strtok - tokenizes a string even the continuous delim
 * with empty string
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: an array of tokens
 */
char **custom_strtok(char *str, char *delm)
{
	int buff_size = 0, p = 0, StringIndex = 0, i = 0, len = 0, StringEnding = 0;
	char **tokens = NULL, d_ch;


	d_ch = delm[0];

	buff_size = custom_token_size(str, d_ch);
	tokens = malloc(sizeof(char *) * (buff_size + 2));
	if (tokens == NULL)
		return (NULL);


	while (str[StringEnding] != '\0')
		StringEnding++;
	while (StringIndex < StringEnding)
	{

		len = token_strlen(str, StringIndex, d_ch);
		tokens[p] = malloc(sizeof(char) * (len + 1));
		if (tokens[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[StringIndex] != d_ch) &&
				(str[StringIndex] != '\0'))
		{
			tokens[p][i] = str[StringIndex];
			i++;
			StringIndex++;
		}
		tokens[p][i] = '\0';
		p++;
		StringIndex++;
	}
	tokens[p] = NULL;
	return (tokens);
}

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell
 * @env: environmental variable
 * Return: a copy of fleshed out command
 */
char *_which(char *str, list_t *env)
{
	char *path, *cat = NULL, **tokens;
	int i = 0;

	path = get_env("PATH", env);
	tokens = custom_strtok(path, ":");
	free(path);

	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(tokens[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_double_ptr(tokens);
			return (cat);
		}
		free(cat);
		i++;
	}
	free_double_ptr(tokens);
	return (str);
}
