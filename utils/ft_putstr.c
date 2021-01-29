/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:15:02 by jescully          #+#    #+#             */
/*   Updated: 2021/01/29 10:17:05 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		ft_putstr(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
	return (size);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
