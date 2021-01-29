/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:35:28 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:54:13 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*intconvert(t_fandf *info)
{
	char	*str;

	if (info->negint < 0)
		str = ft_uitoa(-1 * info->negint);
	else
		str = ft_itoa(info->negint);
	return (str);
}
