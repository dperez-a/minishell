/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francrypto <francrypto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:06:47 by francrypto        #+#    #+#             */
/*   Updated: 2024/12/07 13:06:47 by francrypto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//? input redirections
t_token *process_input_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzamos al siguiente token
    if (token && token->type == WORD)
    {
        command->input_file = strdup(token->value);
        command->input_redir_type = REDIR_IN;
    }
    return token->next;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}

//? output redirections
t_token *process_output_redirection(t_token *token, t_command *command)
{
    printf("Procesando salida con token: %s\n", token->value);
    token = token->next;  // Avanzar al siguiente token
    if (token && token->type == WORD)
    {
        command->output_file = ft_strdup(token->value);
        command->output_redir_type = REDIR_OUT;
        printf("Archivo de salida asignado: %s\n", command->output_file);
        token = token->next;  // Avanzar al siguiente token después del archivo
    }
    else
    {
        printf("Error: Token después de la redirección no es válido.\n");
    }
    return token;  // Retornar el siguiente token
}

//? append redirections
t_token *process_append_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzamos al siguiente token
    if (token && token->type == WORD)
    {
        command->output_file = strdup(token->value);
        command->output_redir_type = APPEND;
    }
    return token->next;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}

//? heredoc redirections
t_token *process_heredoc_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzamos al siguiente token
    if (token && token->type == WORD)
    {
        command->output_file = strdup(token->value);
        command->output_redir_type = HEREDOC;
    }
    return token->next;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}
