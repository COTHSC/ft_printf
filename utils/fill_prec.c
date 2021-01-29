/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:23:02 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:46:03 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	fill_prec(t_fandf *info, va_list ap, int i, const char *s)
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
