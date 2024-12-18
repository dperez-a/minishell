#include "../../minishell.h"

/**
 * process_redirection_tokens - Procesa una lista de tokens para identificar comandos y redirecciones.
 * @tokens: Lista de tokens a procesar.
 *
 * Retorna una estructura `t_command` que contiene información sobre el comando,
 * archivos de entrada/salida y tipos de redirección.
 */
t_command *process_redirection_tokens(t_token **tokens)
{
    t_command *command = ft_calloc(1, sizeof(t_command));
    if (!command)
        return NULL;

    // Inicializar los valores de la estructura
    command->command = NULL;
    command->input_file = NULL;
    command->output_file = NULL;
    command->input_redir_type = 0;
    command->output_redir_type = 0;

    // Procesar tokens para extraer el comando principal y las redirecciones
    while (*tokens)
    {
        if ((*tokens)->type == WORD && !command->command)
        {
            command->command = ft_strdup((*tokens)->str);
        }
        else if ((*tokens)->type == INPUT || (*tokens)->type == TRUNC ||
                 (*tokens)->type == APPEND || (*tokens)->type == HEREDOC)
        {
            // Llamar a funciones para manejar redirecciones específicas
            *tokens = handle_redirection(*tokens, command);
        }
        *tokens = (*tokens)->next;
    }

    return command;
}

/**
 * handle_redirection - Maneja redirecciones específicas.
 * @token: Token actual que representa una redirección.
 * @command: Estructura `t_command` donde almacenar información.
 *
 * Retorna el siguiente token después de la redirección.
 */
t_token *handle_redirection(t_token *token, t_command *command)
{
    if (token->type == INPUT && token->next && token->next->type == WORD)
    {
        command->input_file = ft_strdup(token->next->str);
        command->input_redir_type = INPUT;
        return token->next;
    }
    else if (token->type == TRUNC && token->next && token->next->type == WORD)
    {
        command->output_file = ft_strdup(token->next->str);
        command->output_redir_type = TRUNC;
        return token->next;
    }
    else if (token->type == APPEND && token->next && token->next->type == WORD)
    {
        command->output_file = ft_strdup(token->next->str);
        command->output_redir_type = APPEND;
        return token->next;
    }
    else if (token->type == HEREDOC && token->next && token->next->type == WORD)
    {
        command->output_file = ft_strdup(token->next->str);
        command->output_redir_type = HEREDOC;
        return token->next;
    }
    return token;
}
