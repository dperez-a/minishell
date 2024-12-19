#include "../../minishell.h"

// // Muestra el prompt y lee la entrada del usuario
// char *get_user_input(void)
// {
//     char *input = readline("minishell> ");
//     if (!input)
//     {
//         printf("exit\n");
//         return NULL;
//     }
//     if (*input)
//         add_history(input);
//     return input;
// }

// // process the user input, tokenizen and showin the tokens
// void process_user_input(t_data *data)
// {
//     if (tokenization(data, data->user_input) == 0)
//         print_token_list(&data->token); // depuration
//     else
//     {
//         printf("Error al tokenizar la entrada: %s\n", data->user_input);
//     }
//     lstclear_token(&data->token, free); // clear the tokens
// }

void interactive_shell(void)
{
    char *input;

    while (1)
    {
        // prompt 
        input = readline("🌊 \033[90;1mminiconcha<3 \033[0m");
        if (!input)
        {
            printf("exit\n");
            break;
        }
        if (*input)
            add_history(input);
        // aquí se procesa el input (de momento sólo imprime lo que introduce el usuario)
        printf("Comando introducido: %s\n", input);
        free(input);
    }
}
