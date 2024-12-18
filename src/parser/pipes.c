#include "../../minishell.h"

t_token **split_by_pipes(t_token *tokens, int *num_pipes)
{
    t_token **pipe_segments;
    t_token *current;
    int count = 1; // Al menos un comando

    current = tokens;
    while (current)
    {
        if (current->type == PIPE)
            count++;
        current = current->next;
    }

    pipe_segments = ft_calloc(count + 1, sizeof(t_token *)); // Reservar memoria
    if (!pipe_segments)
        return NULL;

    int i = 0;
    current = tokens;
    while (current)
    {
        pipe_segments[i++] = current;
        while (current && current->type != PIPE)
            current = current->next;
        if (current)
        {
            t_token *next = current->next;
            current->next = NULL; // Separar segmento
            current = next;
        }
    }
    *num_pipes = count;
    return pipe_segments;
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
