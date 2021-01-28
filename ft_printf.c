/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:34:23 by jescully          #+#    #+#             */
/*   Updated: 2021/01/28 17:12:03 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

struct fandf	*innit_struct(int sticky)
{
	struct fandf *info;

	info = malloc(sizeof(*info));
	info->flags = NULL;
	info->width = 0;
	info->filler = ' ';
	info->type = 0;
	info->precision = -1;
	info->lenflags = 0;
	info->lenprint = sticky;
	info->negint = 1;
	info->prenada = 0;
	info->printnull = 0;
	return (info);
}

int				fill_prec(struct fandf *info, va_list ap, int i, const char *s)
{
	if (s[i + 1] == '*')
	{
		info->precision = va_arg(ap, int);
		i += 2;
	}
	else if (ft_isdigit(s[i + 1]))
		info->precision = ft_atoi(&s[++i]);
	else
	{
		info->precision = ft_atoi(&s[++i]);
		info->prenada = 1;
	}
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int		fill_width(struct fandf *info, va_list ap, int i, const char *str)
{
	if (str[i] == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width = -1 * info->width;
			info->flags = ft_appendchar(info->flags, '-');
		}
		i++;
	}
	else if (ft_isdigit(str[i]))
		info->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

struct fandf	*fill(const char *str, struct fandf *info, va_list ap)
{
	int i;

	i = 1;
	info->lenflags = ft_lenflags(&str[i]) + 1;
	while (isflag(str[i]))
		info->flags = ft_appendchar(info->flags, str[i++]);
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = fill_width(info, ap, i, str);
	if (str[i] == '.')
		i = fill_prec(info, ap, i, str);
	if (ft_istype(str[i]))
		info->type = str[i];
	if (ft_strchr(info->flags, '0') && (info->precision < 0))
		info->filler = '0';
	if (info->type == 'i' || info->type == 'd')
	{
		info->negint = (va_arg(ap, int));
		info->prenada = 0;
	}
	if (ft_strchr(info->flags, '-'))
		info->filler = ' ';
	return (info);
}

char		*ft_preciseme(struct fandf *info, char *str)
{
	int		leftovers;
	int		counter;
	char	*pad;
	char	*newstr;

	if (!str)
		return (NULL);
	if (info->type == 's')
		return (ft_substr(str, 0, info->precision));
	counter = 0;
	leftovers = info->precision - ft_strlen(str);
	if (info->precision == 0 && str[0] == '0' && info->type != 'p')
		return ("");
	if (leftovers > 0)
	{
		if (!(pad = malloc(leftovers + 1)))
			return (0);
		while (leftovers-- > 0)
			pad[counter++] = '0';
		pad[counter] = '\0';
		newstr = ft_strjoin(pad, str);
	}
	else
		return (ft_strdup(str));
	return (newstr);
}

char	*ft_paddit(struct fandf *info, char *str, int leftovers)
{
	char	*pad;
	int		counter;
	char	*newstr;

	counter = 0;
	if (info->negint < 0 && info->filler == ' ')
	{
		str = ft_strjoin(ft_chartostr('-', info), str);
		leftovers--;
	}
	if (!(pad = malloc(leftovers + 1)))
		return (0);
	while (counter < leftovers)
		pad[counter++] = info->filler;
	pad[counter] = '\0';
	if (ft_strchr(info->flags, '-'))
		newstr = ft_strjoin(str, pad);
	else
	{
		if (info->negint < 0 && info->filler == '0')
			pad[0] = '-';
		newstr = ft_strjoin(pad, str);
	}
	return (newstr);
}

char			*ft_padme(struct fandf *info, char *str)
{
	int			counter;
	int			leftovers;
	char		*newstr;

	counter = 0;
	str = ft_preciseme(info, str);
	leftovers = info->width - ft_strlen(str);
	if (info->type == 'c' && str[0] == '\0')
		leftovers--;
	if (leftovers > 0)
		newstr = ft_paddit(info, str, leftovers);
	else
	{
		if (info->negint < 0)
			newstr = ft_strjoin(ft_chartostr('-', info), ft_strdup(str));
		else
			newstr = ft_strdup(str);
	}
	return (newstr);
}

int		printme(char *str, struct fandf *info)
{	
	if (!ft_strncmp("0x0", str, 3) && info->prenada && info->type == 'p')
		str = "0x";


	str = ft_padme(info, str);
	info->lenprint += ft_strlen(str);
	if (info->type == 'c' && info->printnull == 1 && ft_strchr(info->flags, '-'))
		ft_putchar('\0');
	ft_putstr(str);
	if (info->type == 'c' && info->printnull == 1 && !ft_strchr(info->flags, '-'))
		ft_putchar('\0');
	free(str);
	return 1;
}

char			*ft_convertme(va_list ap, struct fandf *info)
{
	char		*str;
	char		*strback = "(null)";

	if (info->type == 'i' || info->type == 'd')
	{
		if(info->negint < 0)
			str = ft_uitoa( -1 * info->negint);
		else
			str = ft_itoa(info->negint);
	}
	else if (info->type == 'u')
		str = ft_uitoa(va_arg(ap, unsigned int));
	else if (info->type == 'c')
		str = ft_chartostr(va_arg(ap, int), info);
	else if (info->type == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = strback;
	}
	else if (info->type == 'x')
		str = ft_xtoa(va_arg(ap, unsigned int));
	else if (info->type == 'X')
		str = ft_Xtoa(va_arg(ap, unsigned int));
	else if (info->type == 'p')
		str = ft_strjoin("0x",ft_xtoa(va_arg(ap, uintptr_t)));
	else
		str = ft_chartostr(info->type, info);
	printme(str, info);
	return (str);
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
			if (info->type != '%')
			{
				i += info->lenflags;
			}
			else
			{
				i += 2;
				info->lenprint -= 2;
			}
			if (info->type != '%')
				info->lenprint -= (info->lenflags);
			sticky = info->lenprint;
		}
	}
	info->lenprint += i;
	return info->lenprint;
}

