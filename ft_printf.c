/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:34:23 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:59:34 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fandf				*fill(const char *str, t_fandf *info, va_list ap)
{
	int				i;

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

char				*ft_convertme(va_list ap, t_fandf *info)
{
	char			*str;

	if (info->type == 'i' || info->type == 'd')
		str = intconvert(info);
	else if (info->type == 'u')
		str = ft_uitoa(va_arg(ap, unsigned int));
	else if (info->type == 'c')
		str = ft_chartostr(va_arg(ap, int), info);
	else if (info->type == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = info->null;
	}
	else if (info->type == 'x')
		str = ft_xtoa(va_arg(ap, unsigned int));
	else if (info->type == 'X')
		str = ft_gxtoa(va_arg(ap, unsigned int));
	else if (info->type == 'p')
		str = ft_strjoin("0x", ft_xtoa(va_arg(ap, uintptr_t)));
	else
		str = ft_chartostr(info->type, info);
	printme(str, info);
	return (str);
}

int					printme(char *str, t_fandf *info)
{
	if (!ft_strncmp("0x0", str, 3) && info->prenada && info->type == 'p')
		str = "0x";
	str = ft_padme(info, str);
	info->lenprint += ft_strlen(str);
	if (info->type == 'c' && info->printn == 1 && ft_strchr(info->flags, '-'))
		ft_putchar('\0');
	ft_putstr(str);
	if (info->type == 'c' && info->printn == 1 && !ft_strchr(info->flags, '-'))
		ft_putchar('\0');
	free(str);
	return (1);
}

int					args(t_fandf *info, const char *fs, int i, va_list ap)
{
	fill(&fs[i], info, ap);
	ft_convertme(ap, info);
	if (info->type != '%')
		i += info->lenflags;
	else
	{
		i += 2;
		info->lenprint -= 2;
	}
	if (info->type != '%')
		info->lenprint -= (info->lenflags);
	return (i);
}

int					ft_printf(const char *formatstring, ...)
{
	va_list			ap;
	t_fandf			*info;
	int				i;
	int				sticky;

	sticky = 0;
	i = 0;
	va_start(ap, formatstring);
	info = innit_struct(0);
	while (formatstring[i])
	{
		if (formatstring[i] != '%')
			ft_putchar(formatstring[i++]);
		else
		{
			info = innit_struct(sticky);
			i = args(info, formatstring, i, ap);
			sticky = info->lenprint;
		}
	}
	info->lenprint += i;
	return (info->lenprint);
}
