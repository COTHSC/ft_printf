/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:29:27 by jescully          #+#    #+#             */
/*   Updated: 2021/01/27 10:12:43 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int ft_lenflags(const char *str)
{
    int i;
	int c;
	char *types;
	char *all;

	types = "icudsfXx% ";
	all = "icudsfXx%.-*0123456789";
	c = 0;
	if (!str)
		return 0;
	while (str[c] && ft_strchr(all, str[c]))
	{

    	i = 0;
    	while (types[i])
		{
			if (str[c] == types[i])
				return ++c;
        	i++;
		}
		c++;
	}
	return 0;
}
