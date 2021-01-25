/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:32:13 by jescully          #+#    #+#             */
/*   Updated: 2021/01/25 14:17:18 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>



int ft_printf(const char *formatstring, ...);

int main()
{
    int i = 0;
    int ii = 1;
   // int unautrei = 2000;
  //  int encoreunautrei = 30000;
   // int canarretepas = 12;
//	float dec = 3.12345;
 //   char *soyonsfous = "this is a strong string";
//	char *strf;
	unsigned int uint = 4294967295;
	int iquatorze = -12;
	int ecapartenexa = 0xff;
	int ecapartenexamaisnegatif = -0xff;
	char *pointer;
	char c = 'c';
	int ft;
	int real;


	pointer = &c;
	
	ft = ft_printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12, i);
 	ft_printf("%*i, %*d, %*d, %*d \n", ii, ii, ii, ii, ii, ii, ii ,ii );
 	ft_printf("w %0.0i \n", ii);
	ft_printf("%c \n", 'n');
	ft = ft_printf("this is a string \n");
	real = printf("this is a string \n");
	printf("thi is the fake %i \n", ft);
	printf("thi is the real %i \n", real);
	ft_printf("ft %random \n", i);
	printf("tf %random \n", i);
	ft_printf("char %c \n", 'n');
	printf("char %c \n", 'n');

	
	ft_printf("unsigned %u \n", uint);
	printf("unsigned %u \n", uint);
	ft_printf("ft %.0i \n", i);
	printf("tf %.0i \n", i);
	ft_printf("ft %.*i \n", -4, i);
	printf("tf %.*i \n", -4, i);
	ft_printf("ft %.i \n", 0);
	printf("tf %.i \n", 0);
	ft_printf("ft %.1i \n", 0);
	printf("tf %.1i \n", 0);
	ft_printf("ft %.*i \n", -2, 0);
	printf("tf %.*i \n", -2, 0);
	
	
	printf("%x\n", ecapartenexamaisnegatif);
	ft_printf("%x\n", ecapartenexamaisnegatif);
	printf("%x\n", ecapartenexamaisnegatif);
	ft_printf("%x\n", ecapartenexamaisnegatif);
	printf("%x\n", ecapartenexamaisnegatif);
	
	ft_printf("%x\n", ecapartenexamaisnegatif);
	printf("%x\n", ecapartenexamaisnegatif);

	ft_printf("%x\n", ecapartenexa);
	printf("%x\n", ecapartenexa);
	ft_printf("%X\n", ecapartenexa);
	printf("%X\n", ecapartenexa);
	ft_printf("%i\n", i);
	printf("%i \n", i);
	ft_printf("w %0.*i %.*i %2i\n", 12, i,  iquatorze, i, i);
	printf("w %0.*i %.*i %2i \n", 12, i,  iquatorze, i, i);

	ft = ft_printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12, i);
	real = printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12, i);

	printf("chars printed from ft: %i\n", ft);
	printf("chars printed from tf: %i\n", real);

 	ft_printf("w %0.i \n", ii);
 	printf("w %0.i \n", ii);
 	ft_printf("w %15i \n", i);
 	printf("w %15i \n", i);
	ft_printf("w %5i \n", i);   
	printf("w %5i \n", i);   
	ft_printf("w %-5i \n", i);
	printf("w %-5i \n", i);
	ft_printf("w %-25i \n", i);
	printf("w %-25i \n", i);
	ft_printf("w %-33i \n", i);
	printf("w %-33i \n", i);
	ft_printf("w %-15i \n", i);
	printf("w %-15i \n", i);
	ft_printf("w %-5i \n", i);
	printf("w %-5i \n", i);




    return 0;
}
