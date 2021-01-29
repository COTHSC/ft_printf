/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:56:34 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 09:59:16 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char		*ft_appendchar(char const *s1, char const s2)
{
	int		size;
	char	*retstr;
	int		i;

	i = 0;
	if (!s1)
	{
		retstr = (char*)malloc(sizeof(retstr) * 2);
		retstr[0] = s2;
		retstr[1] = '\0';
		return (retstr);
	}
	else
		size = ft_strlen(s1) + 1;
	if (!(retstr = (char*)malloc(sizeof(retstr) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		retstr[i] = s1[i];
		i++;
	}
	retstr[i++] = s2;
	retstr[i] = '\0';
	return (retstr);
}
