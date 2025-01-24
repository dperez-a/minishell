#include "../../minishell.h"

//* personalized prompt
char *create_prompt(void)
{
    const char *prompt_color = "\033[90m";
    const char *reset_color = "\033[0m";
    const char *prompt_emoticon = "🐚 ";
    char *prompt = NULL;

    asprintf(&prompt, "%s%sminiconcha> %s", prompt_color, prompt_emoticon, reset_color);
    return prompt;
}

//* verify if the user wants to get out
int check_exit(t_data *data)
{
    if (data->user_input == NULL || 
    strcmp(data->user_input, "exit") == 0)
        return 1;
    return 0;
}
