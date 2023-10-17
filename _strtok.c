#include "shell.h"

/**
 * token_strlen - returns token's string length for mallocing
 * @str: a token
 * @pos: index position in user's command typed into shell
 * @delm: delimeter
 * Return: token length
 */
int token_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}

/**
 * token_size - returns number of delim ignoring continuous delim
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: number of delims so that (num token = delims + 1)
 */
int token_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			num_delm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			num_delm--;
		}
		i++;
	}
	return (num_delm);
}

/**
 * ignore_delm - returns a version of string without preceeding delims
 * @str: string
 * @delm: delimiter
 * Return: new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _strtok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: an array of tokens
 */
char **_strtok(char *str, char *delm)
{
	int buff_size = 0, p = 0, StringIndex = 0, i = 0, len = 0,
	StringEnd = 0, t = 0;
	char **tokens = NULL, d_ch;

	d_ch = delm[0];

	str = ignore_delm(str, d_ch);

	buff_size = token_size(str, d_ch);
	tokens = malloc(sizeof(char *) * (buff_size + 2));
	if (tokens == NULL)
		return (NULL);
	while (str[StringEnd] != '\0')
		StringEnd++;
	while (StringIndex < StringEnd)
	{
		if (str[StringIndex] != d_ch)
		{
			len = token_strlen(str, StringIndex, d_ch);
			tokens[p] = malloc(sizeof(char) * (len + 1));
			if (tokens[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[StringIndex] != d_ch) && (str[StringIndex] != '\0'))
			{
				tokens[p][i] = str[StringIndex];
				i++;
				StringIndex++;
			}
			tokens[p][i] = '\0';
			t++;
		}
		if (StringIndex < StringEnd && (str[StringIndex + 1] != d_ch
		&& str[StringIndex + 1] != '\0'))
			p++;
		StringIndex++;
	}
	p++;
	tokens[p] = NULL;
	return (tokens);
}
