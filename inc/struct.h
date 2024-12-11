
#ifndef STRUCT_H
# define STRUCT_H
# include "../minishell.h"
# include <stdbool.h>
# include <sys/types.h>

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘STRUCT〙

typedef struct s_token
{	
    char			*str;
    char			*str_backup;
    bool			var_exists;
    int				type;
    int				status;
    bool			join;
    struct s_token	*prev;
    struct s_token	*next;
}	t_token;

typedef struct s_command {
    char *command;         // the command to execute
    char *input_file;      // input file
    char *output_file;     // output file
    int input_redir_type;  // kind of input redirection (REDIR_IN)
    int output_redir_type; // kind of output redirection (REDIR_OUT or APPEND)
} t_command;

typedef struct s_data
{
    bool        interactive;   // Indica si el modo es interactivo
    t_token     *token;        // Puntero a la lista de tokens generados
    char        *user_input;   // Entrada proporcionada por el usuario
    char        **env;         // Variables de entorno
    char        *working_dir;  // Directorio de trabajo actual
    char        *old_working_dir; // Directorio de trabajo anterior
    t_command   *cmd;          // Información sobre el comando procesado
    pid_t       pid;           // ID del proceso en ejecución
}   t_data;

enum e_quoting_status {
	DEFAULT,
	SQUOTE,
	DQUOTE
};

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                      〘ENUM〙

enum e_token_types {
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
};

#endif