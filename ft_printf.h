/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:47:48 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:59:14 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_fandf
{
	char		*flags;
	int			width;
	char		type;
	char		filler;
	int			precision;
	int			lenflags;
	int			lenprint;
	int			negint;
	int			prenada;
	int			printn;
	char		*null;
}				t_fandf;

int				ft_printf(const char *formatstring, ...);
int				ft_istype(char c);
int				ft_putstr(char *str);
int				isflag(char c);
int				ft_putchar(char c);
int				ft_lenflags(const char *str);
char			*ft_appendchar(char const *s1, char const s2);
char			*ft_strnchr(const char *s, int c, int range);
char			*ft_gxtoa(unsigned int n);
char			*ft_xtoa(uintptr_t n);
char			*ft_uitoa(unsigned int n);
char			*ft_chartostr(char c, t_fandf *info);
int				fill_prec(t_fandf *info, va_list ap, int i, const char *s);
int				fill_width(t_fandf *info, va_list ap, int i, const char *str);
char			*ft_preciseme(t_fandf *info, char *str);
char			*ft_paddit(t_fandf *info, char *str, int leftovers);
t_fandf			*innit_struct(int sticky);
char			*intconvert(t_fandf *info);
int				printme(char *str, t_fandf *info);
char			*ft_padme(t_fandf *info, char *str);
#endif
