/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francrypto <francrypto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:05:41 by francrypto        #+#    #+#             */
/*   Updated: 2024/12/07 13:05:42 by francrypto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../minishell.h"
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘PARSE〙

//? process.c
const char	*process_other(const char *input, t_token **head, t_token **current);
const char	*process_word(const char *input, t_token **head, t_token **current);
const char	*process_pipe(const char *input, t_token **head, t_token **current);
const char	*process_redirection(const char *input, t_token **head, t_token **current);
const char	*process_variable(const char *input, t_token **head, t_token **current);

//? tokenize_input.c
t_token		*tokenize_input(const char *input);
const char	*skip_spaces(const char *input);

//? tokenize_utils.c
t_token		*create_token(const char *value, t_token_type type);
void		add_token(t_token **head, t_token **current, t_token *new_token);
void		print_tokens(t_token *tokens);

#endif