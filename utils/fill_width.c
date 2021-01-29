/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:24:46 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:48:19 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	fill_width(t_fandf *info, va_list ap, int i, const char *str)
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
