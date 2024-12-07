/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francrypto <francrypto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:06:35 by francrypto        #+#    #+#             */
/*   Updated: 2024/12/07 13:06:36 by francrypto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token *tokenize_input(const char *input)
{
    t_token *head = NULL;
    t_token *current = NULL;

    while (*input) {
        input = skip_spaces(input); // ignore spaces

        if (isalnum(*input) || *input == '_' || *input == '-')
            input = process_word(input, &head, &current);
        else if (*input == '>' || *input == '<')
            input = process_redirection(input, &head, &current);
        else if (*input == '|')
            input = process_pipe(input, &head, &current);
        else if (*input == '$')
            input = process_variable(input, &head, &current);
        else
            input = process_other(input, &head, &current);
    }
    return head;
}

const char *skip_spaces(const char *input)
{
    while (ft_isspace(*input))
        input++;
    return input;
}
