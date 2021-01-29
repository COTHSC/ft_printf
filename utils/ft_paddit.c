/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:29:11 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:49:43 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_paddit(t_fandf *info, char *str, int leftovers)
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
