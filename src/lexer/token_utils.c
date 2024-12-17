#include "../../minishell.h"

int	save_separator(t_token **token_lst, char *str, int index, int type)
{
	int		length;
	char	*sep;

	length = (type == APPEND || type == HEREDOC) ? 3 : 2; // Tamaño del separador
	sep = ft_calloc(length, sizeof(char)); // Asignar memoria para el separador
	if (!sep)
		return (1);

	// Copiar el separador en `sep`
	for (int i = 0; i < length - 1; i++)
		sep[i] = str[index++];

	sep[length - 1] = '\0'; // Finalizar cadena
	lst_add_back_token(token_lst, lst_new_token(sep, NULL, type, DEFAULT));
	return (0);
}

int	save_word(t_token **token_lst, char *str, int index, int start)
{
	char	*word;
	int		length;

	length = index - start;
	if (length <= 0) // Evitar palabras vacías
		return (0);

	word = ft_calloc(length + 1, sizeof(char)); // Reservar memoria para la palabra
	if (!word)
		return (1);

	// Copiar la palabra desde `str`
	ft_strlcpy(word, &str[start], length + 1);

	lst_add_back_token(token_lst, \
		lst_new_token(word, ft_strdup(word), WORD, DEFAULT));
	return (0);
}


int	is_separator(char *str, int i)
{
	if (((str[i] > 8 && str[i] < 14) || str[i] == 32)) // Espacios
		return (SPACES);
	else if (str[i] == '|' && str[i + 1] != '|') // Validar `|` individual
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<') // `<<`
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>') // `>>`
		return (APPEND);
	else if (str[i] == '<') // `<`
		return (INPUT);
	else if (str[i] == '>') // `>`
		return (TRUNC);
	else if (str[i] == '\0') // Fin de cadena
		return (END);
	else
		return (0); // No es separador
}


int	set_status(int status, char *str, int i)
{
	if (str[i] == '\'' && status == DEFAULT)
		status = SQUOTE;
	else if (str[i] == '\"' && status == DEFAULT)
		status = DQUOTE;
	else if (str[i] == '\'' && status == SQUOTE)
		status = DEFAULT;
	else if (str[i] == '\"' && status == DQUOTE)
		status = DEFAULT;
	return (status);
}

int	save_word_or_sep(int *i, char *str, int start, t_data *data)
{
	int	type;

	type = is_separator(str, (*i));
	if (type)
	{
		if ((*i) != 0 && is_separator(str, (*i) - 1) == 0)
			save_word(&data->token, str, (*i), start);
		if (type == APPEND || type == HEREDOC || type == PIPE
			|| type == INPUT || type == TRUNC || type == END)
		{
			save_separator(&data->token, str, (*i), type);
			if (type == APPEND || type == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}
