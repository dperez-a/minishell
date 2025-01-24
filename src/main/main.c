#include "../../minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../minishell.h"

// Funciones de prueba
void test_init_environment(void) {
    t_data data;
    init_environment(&data);
    if (data.env != NULL && data.working_dir != NULL && data.pid == getpid()) {
        printf("test_init_environment: PASSED\n");
    } else {
        printf("test_init_environment: FAILED\n");
    }
}

void test_tokenization(void) {
    t_data data;
    data.user_input = "echo hello";
    int result = tokenization(&data, data.user_input);
    if (result == 0 && data.token != NULL && strcmp(data.token->str, "echo") == 0 && strcmp(data.token->next->str, "hello") == 0) {
        printf("test_tokenization: PASSED\n");
    } else {
        printf("test_tokenization: FAILED\n");
    }
    lstclear_token(&data.token, free);
}

void test_check_exit(void) {
    t_data data;
    data.user_input = "exit";
    int result = check_exit(&data);
    if (result == 1) {
        printf("test_check_exit: PASSED\n");
    } else {
        printf("test_check_exit: FAILED\n");
    }
}

int main(void) {
    // Ejecutar pruebas
    test_init_environment();
    test_tokenization();
    test_check_exit();

    // Código original del main
    t_data data;
    init_environment(&data);
    char *prompt = create_prompt();

    while (true) {
        data.user_input = readline(prompt);
        if (check_exit(&data))
            break;

        if (data.user_input && *data.user_input)
            add_history(data.user_input);

        if (data.user_input && tokenization(&data, data.user_input) == 0) {
            t_pipeline *pipeline = process_pipeline(data.token);
            if (pipeline) {
                // Ejecutar el pipeline
                // execute_pipeline(pipeline);
                // Liberar memoria del pipeline
                // free_pipeline(pipeline);
            } else {
                printf("Error al procesar el pipeline.\n");
            }
        } else {
            printf("Error al tokenizar la entrada.\n");
        }

        cleanup_data(&data);
    }

    free(prompt);
    return 0;
}
