/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preciseme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:27:05 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 12:53:32 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_preciseme(t_fandf *info, char *str)
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
