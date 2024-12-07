/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francrypto <francrypto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:05:52 by francrypto        #+#    #+#             */
/*   Updated: 2024/12/07 13:05:53 by francrypto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../minishell.h"
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘STRUCT〙

typedef enum e_token_type{
    WORD,       // general words
    PIPE,       // |
    REDIR_IN,   // <
    REDIR_OUT,  // >
    APPEND,     // >>
    HEREDOC,    // <<
    VARIABLE,   // $var
    OTHER       // other special caracters
}       t_token_type;

typedef struct s_token{
    char            *value;     // token content
    t_token_type    type;       // token type
    struct s_token  *next;      // next token of the list
}       t_token;

typedef struct s_command {
    char *command;         // the command to execute
    char *input_file;      // input file
    char *output_file;     // output file
    int input_redir_type;  // kind of input redirection (REDIR_IN)
    int output_redir_type; // kind of output redirection (REDIR_OUT or APPEND)
} t_command;

#endif