/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:43:28 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:53:17 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	ilength(long long int number)
{
	int		i;

	i = 1;
	if (number < 0)
	{
		i++;
		number = -number;
	}
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(unsigned int nb)
{
	char	*ret;
	int		len;

	if (!(ret = (char*)malloc(sizeof(char) * (ilength(nb) + 1))))
		return (NULL);
	ret[ilength(nb)] = '\0';
	len = ilength(nb) - 1;
	while (ilength(nb) != 1)
	{
		ret[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	ret[0] = nb + '0';
	return (ret);
}
