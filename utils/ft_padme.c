/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:38:43 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 14:51:29 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_padme(t_fandf *info, char *str)
{
	int		counter;
	int		leftovers;
	char	*newstr;

	counter = 0;
	str = ft_preciseme(info, str);
	if (info->type == 'p')
		str = ft_strjoin("0x", ft_strdup(str));
	if (!ft_strncmp("0x0", str, 3) && (info->prenada || !info->precision) \
			&& info->type == 'p')
		str = "0x";
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
