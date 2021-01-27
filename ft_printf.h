/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:47:48 by jescully          #+#    #+#             */
/*   Updated: 2021/01/27 12:09:26 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

struct  fandf
{
    char *flags;
    int width;
    char type;
	char filler;
	int precision;
    int lenflags;
	int lenprint;
	int negint;
	int prenada;
};

int ft_printf(const char *formatstring, ...);
int				ft_istype(char c);
int				ft_putstr(char *str);
int				isflag(char c);
int 			ft_putchar(char c);
int 			ft_lenflags(const char *str);
char    		*ft_appendchar(char const *s1, char const s2);
char    		*ft_strnchr(const char *s, int c, int range);
char        	*ft_Xtoa(unsigned int n);
char        	*ft_xtoa(unsigned int n);
char        	*ft_uitoa(unsigned int n);
char            *ft_chartostr(char c);
#endif
