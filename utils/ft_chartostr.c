/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:32:26 by jescully          #+#    #+#             */
/*   Updated: 2021/01/28 16:58:11 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

char	*ft_chartostr(char c, struct fandf *info)
{
	char *str;

	if (!(str =(char *)malloc(2)))
		return NULL;
	str[0] = c;
	str[1] = '\0';
	if (str[0] == '\0')
	{
		info->printnull++;
		info->lenprint++;
	}
	return str;
}
