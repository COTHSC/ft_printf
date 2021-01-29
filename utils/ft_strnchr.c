/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <jescully@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:05:59 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:18:11 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strnchr(const char *s, int c, int range)
{
	int		i;
	char	*cs;

	if (!s)
		return (0);
	cs = (char *)s;
	i = 0;
	while (s[i] && i < range)
	{
		if (cs[i] == c)
			return (&cs[i]);
		i++;
	}
	if (cs[i] == c)
		return (&cs[i]);
	return (NULL);
}
