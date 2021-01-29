/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:34:00 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:52:22 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_fandf	*innit_struct(int sticky)
{
	t_fandf	*info;

	info = malloc(sizeof(*info));
	info->flags = NULL;
	info->width = 0;
	info->filler = ' ';
	info->type = 0;
	info->precision = -1;
	info->lenflags = 0;
	info->lenprint = sticky;
	info->negint = 1;
	info->prenada = 0;
	info->printn = 0;
	info->null = "(null)";
	return (info);
}
