#include "../../minishell.h"

t_command *process_redirection_tokens(t_token **tokens)
{
    t_command *command = ft_calloc(1, sizeof(t_command));
    if (!command)
        return NULL;
    // Inicialización de campos a valores predeterminados
    command->command = NULL;
    command->input_file = NULL;
    command->output_file = NULL;
    command->input_redir_type = 0;
    command->output_redir_type = 0;

    // Procesar el primer token (comando)
if (*tokens)
{
    printf("Token inicial: '%s', Tipo: %d\n", (*tokens)->value, (*tokens)->type);
    if ((*tokens)->type == WORD)
    {
        command->command = ft_strdup((*tokens)->value);
        if (!command->command)
        {
            // printf("Error: No se pudo asignar memoria para el comando.\n");
            free(command);
            return NULL;
        }
        // printf("Comando asignado: %s\n", command->command);
        *tokens = (*tokens)->next;  // Avanzar al siguiente token
    }
    else
        printf("Error: Token inicial no es un comando.\n");
}
else
    // printf("Error: Tokens es NULL al inicio del procesamiento.\n");
while (*tokens && ((*tokens)->type == REDIR_IN || (*tokens)->type == REDIR_OUT ||
                   (*tokens)->type == APPEND || (*tokens)->type == HEREDOC))
{
    // printf("Procesando redirección de tipo: %d\n", (*tokens)->type);
    t_token **new_tokens = process_redirection_types(tokens, command);
    if (!new_tokens)
    {
        // printf("Error: Tokens se volvió NULL durante el procesamiento.\n");
        break;
    }
    tokens = new_tokens;
    // printf("Tokens actualizados: %p\n", (void *)tokens);
}
    return command;
}


t_token **process_redirection_types(t_token **tokens, t_command *command)
{
    if ((*tokens)->type == REDIR_IN)
    {
        *tokens = process_input_redirection(*tokens, command);
    }
    else if ((*tokens)->type == REDIR_OUT)
    {
        *tokens = process_output_redirection(*tokens, command);
    }
    else if ((*tokens)->type == APPEND)
    {
        *tokens = process_append_redirection(*tokens, command);
    }
    else if ((*tokens)->type == HEREDOC)
    {
        *tokens = process_heredoc_redirection(*tokens, command);
    }
    return tokens;
}
