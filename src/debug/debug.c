#include "../../minishell.h"

void	print_token_type(t_token *token, char *prefix)
{
	printf("%s", prefix);
	if (token->type == SPACES)
		printf("SPACES\n");
	else if (token->type == WORD)
		printf("WORD\n");
	else if (token->type == VAR)
		printf("VAR\n");
	else if (token->type == PIPE)
		printf("PIPE\n");
	else if (token->type == INPUT)
		printf("INPUT\n");
	else if (token->type == TRUNC)
		printf("TRUNC\n");
	else if (token->type == HEREDOC)
		printf("HEREDOC\n");
	else if (token->type == APPEND)
		printf("APPEND\n");
	else if (token->type == END)
		printf("END\n");
}

void	print_token_list(t_token **tokens)
{
	t_token	*lst;
	int		i;

	lst = *tokens;
	printf("\n---- TOKEN LIST\n");
	i = 0;
	while (lst)
	{
		printf("--- Token [%d] [%p]\n", i, lst);
		printf("\tString = [%s]\n", lst->str);
		printf("\tStr backup = [%s]\n", lst->str_backup);
		print_token_type(lst, "\tType = ");
		printf("\tStatus = %d\n", lst->status);
		if (lst->prev)
			printf("\tPrev = [%p]\n", lst->prev);
		else
			printf("\tPrev = NULL\n");
		if (lst->next)
			printf("\tNext = [%p]\n", lst->next);
		else
			printf("\tNext = NULL\n");
		i++;
		lst = lst->next;
	}
}
