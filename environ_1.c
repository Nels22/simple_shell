#include "shell.h"

/**
 * cmp_env_name - Compares env variable names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed.
 *
 * Return: 0 if they are not equal
 *         1 if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}
	return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable.
 * @_environ: environment variable
 *
 * Return:value of the enviironment variable if it is found
 *        Otherwise - NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	/* Compare all environment variable */
	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}
	return (ptr_env + mov);
}

/**
 * _env - prints the environment variables.
 *
 * @datash - relevant data
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{
		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, data->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
