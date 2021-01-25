/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:34:23 by jescully          #+#    #+#             */
/*   Updated: 2021/01/25 15:55:40 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

struct fandf *innit_struct(int sticky)
{
	struct fandf *info;

	info = malloc(sizeof(*info));

	info->flags = NULL ;
	info->width = 0;
	info->filler = ' ';
	info->type = 0;
	info->precision = 1;
	info->lenflags = 0;
	info->lenprint = sticky;
	return info;

}

struct fandf	*fill(const char *str, struct fandf *info, va_list ap)
{
	int i;
	i = 1;

	info->lenflags = ft_lenflags(&str[i]) + 1;

	while (isflag(str[i]))
			info->flags = ft_appendchar(info->flags, str[i++]);
	
	if (ft_strchr(info->flags, '0') && !ft_strnchr(str, '.', info->lenflags))
		info->filler = '0';

	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (str[i] == '*')
		{
			info->width = va_arg(ap, int);
			i += 1;
		}
		else 
			info->width = ft_atoi(&str[i]);
	}
	while(ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		if (str[i + 1] == '*')
		{
			info->precision = va_arg(ap, int);
			i += 2;
		}
		else
			info->precision = ft_atoi(&str[++i]);
	}
	while (ft_isdigit(str[i]))
		i++;
	if(ft_istype(str[i]))
		info->type = str[i];
	else
	{
		info->lenflags = 1;
	}
	return (info);
}

char	*ft_preciseme(struct fandf *info, char *str)
{
	int leftovers;
	int i;
	int counter;
	char *pad;
	char *newstr;

	if (!str)
		return NULL;
	counter = 0;
	i = ft_strlen(str);
	leftovers = info->precision - i;
	if (info->type == 0 || (info->precision == 0 && str[0] == '0' ))
	{
		newstr = "";
		return newstr;
	}
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
			pad[counter++] = info->filler;
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

	if (info->type == 'i' || info->type == 'd')
		str = ft_itoa(va_arg(ap, int));
	else if (info->type == 'u')
		str = ft_uitoa(va_arg(ap, unsigned int));
	else if (info->type == 'c')
		str = ft_chartostr(va_arg(ap, int));
	else if (info->type == 's')
		str = va_arg(ap, char *);
//	else if (info->type == 'f')
//		str = ft_ftoa(va_arg(ap, double));
	else if (info->type == 'x')
		str = ft_xtoa(va_arg(ap, unsigned int));
	else if (info->type == 'X')
		str = ft_Xtoa(va_arg(ap, unsigned int));
	else
		str = "";

	str = ft_padme(info, str);
	info->lenprint += ft_strlen(str);
	ft_putstr(str);
	free(str);
	return 1;
}

int ft_printf(const char *formatstring, ...)
{
	va_list	ap;
	struct fandf *info;
	int i;
	int sticky;

	sticky = 0;
	i  = 0;
	va_start(ap, formatstring);
	info = innit_struct(0);
	while (formatstring[i])
	{
		if (formatstring[i] != '%')
			ft_putchar(formatstring[i++]);
		else
		{
			info = innit_struct(sticky);
			fill(&formatstring[i], info, ap);
			ft_convertme(ap, info);
			i += info->lenflags;
			info->lenprint -= (info->lenflags);
			sticky = info->lenprint;
		}
	}
	info->lenprint += i;
	return info->lenprint;
}

