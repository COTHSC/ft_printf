/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:32:13 by jescully          #+#    #+#             */
/*   Updated: 2021/01/22 08:56:31 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>



int ft_printf(const char *formatstring, ...);

int main()
{
    int i = 0;
    int unautrei = 2000;
    int encoreunautrei = 30000;
    int canarretepas = 12;
	float dec = 3.12345;
    char *soyonsfous = "this is a strong string";
	char *strf;
	int iquatorze = -12;

	int ft;
	int real;
	ft = ft_printf("w %.*i \n",  iquatorze, i);
	ft = printf("w %.*i \n",  iquatorze, i);
	ft = ft_printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12, i);
    real = printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12 ,i);

	printf("chars printed from ft: %i\n", ft);
	printf("chars printed from tf: %i\n", real);
// 	printf("w %3.4i \n", i);
//    printf("w %15i \n", i);
//    printf("w %5i \n", i);   
//   	printf("w %-5i \n", i);
//    printf("w %-25i \n", i);
//    printf("w %-33i \n", i);
//    printf("w %-15i \n", i);
//    printf("w %-5i \n", i);




    return 0;
}
