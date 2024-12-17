#include "../../minishell.h"

void handle_unexpected_eof(int status)
{
    if (status == DQUOTE)
        errmsg("unexpected EOF while looking for matching", "\"", 1);
    else if (status == SQUOTE)
        errmsg("unexpected EOF while looking for matching", "\'", 1);
    errmsg("syntax error", "unexpected end of file", 0);
}

int	tokenization(t_data *data, char *str)
{
	int	i;
	int	end;
	int	start;
	int	status;

	i = -1;
	start = 0;
	end = ft_strlen(str);
	status = DEFAULT;
	while (++i <= end)
	{
		status = set_status(status, str, i);
		if (status == DEFAULT)
			start = save_word_or_sep(&i, str, start, data);
		if (start == -1) // Detectar error en `save_word_or_sep`
			return (1);
	}
	if (status != DEFAULT)
	{
		if (status == DQUOTE)
			errmsg("unexpected EOF while looking for matching", "\"", 1);
		else if (status == SQUOTE)
			errmsg("unexpected EOF while looking for matching", "'", 1);
		errmsg("syntax error", "unexpected end of file", 0);
		return (1);
	}
	return (0);
}

