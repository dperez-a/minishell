#include "../inc/minishell.h"

void test_tokenize_input(const char *input)
{
    printf("Input: %s\n", input);
    t_token *tokens = tokenize_input(input);
    print_tokens(tokens);
    // Free tokens after use
    t_token *tmp;
    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);
        free(tmp);
    }
    printf("\n");
}

int main()
{
    // Test cases
    const char *inputs[] =
    {
        "echo $USER | grep 'hello world' > output.txt",
        "ls -la | grep minishell > result.txt",
        "cat < input.txt | sort > sorted.txt",
        "echo 'Hello, World!' >> greetings.txt",
        "export PATH=$PATH:/new/path",
        NULL
    };

    int i = 0;
    while (inputs[i] != NULL)
    {
        test_tokenize_input(inputs[i]);
        i++;
    }

    return 0;
}
