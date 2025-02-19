#include "../../minishell.h"

// Funciones de prueba
void test_init_environment(void)
{
    t_data data;
    init_environment(&data);
    if (data.env != NULL && data.working_dir != NULL && data.pid == getpid())
        printf("test_init_environment: PASSED\n");
    else
        printf("test_init_environment: FAILED\n");
}

void test_tokenization(void)
{
    t_data data;
    data.user_input = "echo hello";
    int result = tokenization(&data, data.user_input);
    if (result == 0 && data.token != NULL && strcmp(data.token->str, "echo") == 0 && strcmp(data.token->next->str, "hello") == 0)
        printf("test_tokenization: PASSED\n");
    else
        printf("test_tokenization: FAILED\n");
    lstclear_token(&data.token, free);
}

void test_check_exit(void)
{
    t_data data;
    data.user_input = "exit";
    printf("Debug: data.user_input = %s\n", data.user_input); // Mensaje de depuración
    int result = check_exit(&data);
    printf("Debug: result = %d\n", result); // Mensaje de depuración
    if (result == 1)
        printf("test_check_exit: PASSED\n");
    else
        printf("test_check_exit: FAILED\n");
}

int main(void)
{
    // Ejecutar pruebas
    test_init_environment();
    test_tokenization();
    test_check_exit();

    // Código original del main
    t_data data;
    init_environment(&data);

    // Casos de prueba
    const char *inputs[] = {
        // "ls -la | grep minishell > result.txt",
        // "cat < input.txt | sort > sorted.txt",
        // "echo 'Hello World!' | wc -l",
        // "| invalid_start",
        // "invalid_command | | double_pipe",
        "echo hello | grep h | wc -l | sort > result.txt",
        // "echo hola > file1.txt > file2.txt",
        // "echo hola mundo",
        // "ls -l -a ",
        // "grep 'txt' archivos.txt",
        NULL
    };

    int i = 0;
    while (inputs[i]) {
        printf("\n🐚 Procesando input: %s\n", inputs[i]);

        data.user_input = ft_strdup(inputs[i]);
        if (!data.user_input) {
            printf("Error: No se pudo duplicar la entrada.\n");
            i++;
            continue;
        }

        // Tokenización
        if (tokenization(&data, data.user_input) == 0)
        {
            if (validate_tokens(data.token) == 0)
            {
                t_pipeline *pipeline = process_pipeline(data.token);
                if (pipeline) {
                    print_pipeline(pipeline);
                    free_pipeline(pipeline);
                } 
                else
                    printf("Error: Fallo al procesar la tubería.\n");
            }
            else
                printf("Error: Validación de tokens fallida.\n");
        }
        else
            printf("Error al tokenizar la entrada.\n");

        cleanup_data(&data);
        i++;
    }

    return 0;
}
