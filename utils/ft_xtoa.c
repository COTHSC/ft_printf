/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:00:29 by jescully          #+#    #+#             */
/*   Updated: 2021/01/28 09:51:34 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

static int  xlength(long long int number)
{
    int i;

    i = 1;
    if (number < 0)
    {
        i++;
        number = -number;
    }
    while (number >= 16)
    {
        number = number / 16;
        i++;
    }
    return (i);
}


char        *ft_xtoa(uintptr_t n)
{
    char            *ret;
    uintptr_t    nb;
    int             len;
	char *hex = "0123456789abcdef";

    if (!(ret = (char*)malloc(sizeof(char) * (xlength(n) + 1))))
        return (NULL);
    ret[xlength(n)] = '\0';
    nb = n;
    len = xlength(n) - 1;
    while (xlength(nb) != 1)
    {
        ret[len--] = hex[nb % 16];
        nb = nb / 16;
    }
    ret[0] = hex[nb];
    return (ret);
}

char        *ft_Xtoa(unsigned int n)
{
    char            *ret;
    unsigned int    nb;
    int             len;
	char *hex = "0123456789ABCDEF";

    if (!(ret = (char*)malloc(sizeof(char) * (xlength(n) + 1))))
        return (NULL);
    ret[xlength(n)] = '\0';
    nb = n;
    len = xlength(n) - 1;
    while (xlength(nb) != 1)
    {
        ret[len--] = hex[nb % 16];
        nb = nb / 16;
    }
    ret[0] = hex[nb];
    return (ret);
}
