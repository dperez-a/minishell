#include "../../minishell.h"

//* errores de tokenización
int handle_tokenization_error(void)
{
    printf("Error: Failed tokenization.\n");
    return(1);
}

//* errores de sintaxis
int handle_syntax_error(void)
{
    printf("Error: Invalid input.\n");
    return(1);
}