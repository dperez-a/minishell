#ifndef MINISHELL_H
# define MINISHELL_H

#define TEST_MODE 1 // Cambia a 0 para activar el entorno interactivo

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//									   〘MINISHELL〙

//* first init struct because of the errors on the makefile *//
# include "inc/struct.h"
//* libft *//
# include "libft/libft.h"

//* all files from my inc *//
# include "inc/lexer.h"
# include "inc/parser.h"
# include "inc/utils.h"
# include "inc/env.h"
# include "inc/inc.h"
# include "inc/define.h"

#endif