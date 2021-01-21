/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:34:23 by jescully          #+#    #+#             */
/*   Updated: 2021/01/21 17:00:02 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

struct fandf *innit_struct()
{
	struct fandf *info;

	info = malloc(sizeof(*info));

	info->flags = NULL ;
	info->width = 0;
	info->type = 0;
	info->precision = 1;
	info->lenflags = 0;
	return info;

}

struct fandf	*fill(const char *str, struct fandf *info)
{
	int i;
	i = 1;

	info->lenflags = ft_lenflags(&str[i]) + 1;
	while (isflag(str[i]))
			info->flags = ft_appendchar(info->flags, str[i++]);
	if (ft_isdigit(str[i]))
		info->width = ft_atoi(&str[i]);
	while(ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		info->precision = ft_atoi(&str[++i]);
	while (ft_isdigit(str[i]))
		i++;
	if(ft_istype(str[i]))
		info->type = str[i];

//	printf("this is whats in my struct: %s \n", info->flags);
//	printf("this is whats in my struct: %i \n", info->width);
//	printf("this is whats in my struct: %c \n", info->type);
	printf("this is whats in my struct: %i \n", info->precision);
	return (info);
}

char	*ft_preciseme(struct fandf *info, char *str)
{
	int leftovers;
	int i;
	int counter;
	char *pad;
	char *newstr;

	counter = 0;
	i = ft_strlen(str);
	leftovers = info->precision - i;

  	if (leftovers > 0)
    {
        if (!(pad = malloc(leftovers + 1)))
                return 0;
        while (counter < leftovers)
            pad[counter++] = '0';

        pad[counter] = '\0';
        newstr = ft_strjoin(pad, str);
    }
    else
		newstr = ft_strdup(str);
    return (newstr);
}


char *ft_padme(struct fandf *info, char *str)
{
	int i;
	int counter;
	int leftovers;
	char *pad;
	char *newstr;
	
	counter = 0;
	str = ft_preciseme(info, str);
	i = ft_strlen(str);
	leftovers = info->width - i;
	if (leftovers > 0)
	{
		if (!(pad = malloc(leftovers + 1)))
				return 0;
		while (counter < leftovers)
			pad[counter++] = ' ';
		pad[counter] = '\0';
		if (ft_strchr(info->flags, '-'))
			newstr = ft_strjoin(str, pad);
		else
			newstr = ft_strjoin(pad, str);
	}
	else
		newstr = ft_strdup(str);
	return (newstr);
}




int	ft_convertme(va_list ap, struct fandf *info)
{
	char *str;

	if (info->type == 'i')
		str = ft_itoa(va_arg(ap, int));
	else if (info->type == 's')
		str = va_arg(ap, char *);
	else if (info->type == 'f')
		str = ft_ftoa(va_arg(ap, double));
	str = ft_padme(info, str);
	ft_putstr(str);
	free(str);
	return 1;
}

int ft_printf(const char *formatstring, ...)
{
	va_list	ap;
	struct fandf *info;
	int i;

	i  = 0;
	va_start(ap, formatstring);
	while (formatstring[i])
	{
		if (formatstring[i] != '%')
			ft_putchar(formatstring[i++]);
		else
		{
			info = innit_struct();
			fill(&formatstring[i], info);
			ft_convertme(ap, info);
			i = i + info->lenflags;
		}
	}
	return 0;
}

