#include "../../minishell.h"

int validate_tokens(t_token *tokens)
{
    t_token *current = tokens;
    // Verificar que el primer token no sea un pipe
    if (current && current->type == PIPE)
    {
        printf("Error: El primer token no puede ser un pipe.\n");
        return 1;
    }
    while (current)
    {
        // Verificar que no haya dos pipes consecutivos
        if (current->type == PIPE && current->next && current->next->type == PIPE)
        {
            printf("Error: No pueden haber dos pipes consecutivos.\n");
            return 1;
        }

        // Verificar que no haya redirecciones sin archivo asociado
        if ((current->type == REDIR_IN || current->type == REDIR_OUT) && (!current->next ||
        current->next->type != WORD))
        {
            printf("Error: Redirección sin archivo asociado.\n");
            return 1;
        }
        // Verificar que no haya redirecciones consecutivas
        if ((current->type == REDIR_IN || current->type == REDIR_OUT) && current->next &&
        (current->next->type == REDIR_IN || current->next->type == REDIR_OUT))
        {
            printf("Error: No pueden haber redirecciones consecutivas.\n");
            return 1;
        }
        current = current->next;
    }
    // Verificar que el último token no sea un pipe
    if (tokens && current && current->type == PIPE)
    {
        printf("Error: El último token no puede ser un pipe.\n");
        return 1;
    }
    return 0;
}
