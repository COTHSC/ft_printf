/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:32:26 by jescully          #+#    #+#             */
/*   Updated: 2021/01/27 10:33:01 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_chartostr(char c)
{
	char *str;

	if (!(str =(char *)malloc(2)))
		return NULL;
	str[0] = c;
	str[1] = '\0';

	return str;
}
