#include "../../minishell.h"

#include "../../minishell.h"

t_token **split_by_pipes(t_token *tokens, int *num_pipes)
{
    t_token **segments = NULL;
    t_token *current = tokens;
    int count = 1; // Contamos al menos un segmento

    // Contar pipes para saber cuántos segmentos tendremos
    while (current)
    {
        if (current->type == PIPE)
            count++;
        current = current->next;
    }
    *num_pipes = count;

    // Reservar memoria para los segmentos
    segments = ft_calloc(count + 1, sizeof(t_token *));
    if (!segments)
        return (NULL);

    // Dividir tokens por pipes
    current = tokens;
    int i = 0;
    segments[i++] = tokens;
    while (current)
    {
        if (current->type == PIPE)
        {
            current->str = NULL;  // No necesitamos el token `|` en los comandos
            segments[i++] = current->next;
            current->next = NULL; // Rompemos la lista aquí
        }
        current = current->next;
    }
    return (segments);
}


t_pipeline *process_pipeline(t_token *tokens)
{
    int num_pipes;
    t_token **segments = split_by_pipes(tokens, &num_pipes);

    if (!segments)
        return NULL;

    t_pipeline *pipeline = ft_calloc(1, sizeof(t_pipeline));
    if (!pipeline)
        return NULL;

    pipeline->commands = ft_calloc(num_pipes, sizeof(t_command *));
    if (!pipeline->commands)
        return NULL;

    pipeline->count = num_pipes;
    for (int i = 0; i < num_pipes; i++)
    {
        pipeline->commands[i] = process_redirection_tokens(&segments[i]);
        if (!pipeline->commands[i])
        {
            printf("Error: Fallo en el comando %d\n", i + 1);
            // Limpieza y retorno de error
            return NULL;
        }
    }
    return pipeline;
}
