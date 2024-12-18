
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
    
    //* backup for the expansion changes *//
    char			*str_backup;
    bool			var_exists;
    int				type;
    int				status;
    bool			join;
    struct s_token	*prev;
    struct s_token	*next;
}	t_token;

typedef struct s_command {
    //* the command to execute *//
    char *command;

    //* input file *//
    char *input_file;

    //* output file *//
    char *output_file;

    //* kind of input redirection (REDIR_IN) *//
    int input_redir_type;

    //* kind of output redirection (REDIR_OUT or APPEND) *//
    int output_redir_type;
} t_command;

typedef struct s_data
{
    //* Indica si el modo es interactivo *//
    bool        interactive;   
    
    //* Puntero a la lista de tokens generados *//
    t_token     *token;
    
    //* Entrada proporcionada por el usuario *//
    char        *user_input;   
    
    //* Variables de entorno *//
    char        **env;    
    
    //* Directorio de trabajo actual //*
    char        *working_dir;  
    
    //* Directorio de trabajo anterior *//
    char        *old_working_dir;
    
    //* Información sobre el comando procesado *//
    t_command   *cmd;
    
    //* ID del proceso en ejecución *//
    pid_t       pid;
}   t_data;


enum e_quoting_status {
	//* default status without quotes *//
    DEFAULT,

    //* single quotes status *//
	SQUOTE,

    //* double quotes status *//
    DQUOTE
};

// principal structure
typedef struct s_pipeline {
    
    //* command list separated by pipes *//
    t_command   **commands;

    //* number of commands *//
    int         count;
}   t_pipeline;
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                      〘ENUM〙

// diferent token types
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