#include "../../inc/minishell.h"

/**
 * process_other - Handles unrecognized characters in the input.
 * Creates a token of type OTHER with the character and adds it to the token list.
 *
 * @param input: Pointer to the current position in the input string.
 * @param head: Pointer to the head of the token list.
 * @param current: Pointer to the current token in the list.
 * @return: Updated pointer to the input after processing the character.
 */
const char *process_other(const char *input, t_token **head, t_token **current)
{
    char other_char[2] = {*input, '\0'};  // Convert character to string
    t_token *new_token = create_token(other_char, OTHER);  // Create a token
    add_token(head, current, new_token);  // Add the token to the list
    input++;  // Advance to the next character
    return input;
}


const char *process_word(const char *input, t_token **head, t_token **current)
{
    const char *start = input;
    while (isalnum(*input) || *input == '_' || *input == '-' || *input == '.')
        input++;
    t_token *new_token = create_token(strndup(start, input - start), WORD);
    add_token(head, current, new_token);
    return input;  // Returns the actualized pointer
}

const char *process_pipe(const char *input, t_token **head, t_token **current)
{
    t_token *new_token = create_token("|", PIPE);
    add_token(head, current, new_token);
    input++;  // advance to the new character after the pipe
    return input;
}

const char *process_redirection(const char *input, t_token **head, t_token **current)
{
    t_token *new_token = NULL;

    if (*input == '>')
        input = handle_output_redirection(input, &new_token);
    else if (*input == '<')
        input = handle_input_redirection(input, &new_token);
    if (new_token)
        add_token(head, current, new_token);
    return input;
}

const char *process_variable(const char *input, t_token **head, t_token **current)
{
    const char *start = input++;
    while (isalnum(*input) || *input == '_')
        input++;
    t_token *new_token = create_token(strndup(start, input - start), VARIABLE);
    add_token(head, current, new_token);

    return input;
}
