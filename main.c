/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:32:13 by jescully          #+#    #+#             */
/*   Updated: 2021/01/28 12:08:45 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>



int ft_printf(const char *formatstring, ...);

int main()
{
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
	int ft;
	int real;

    int     a = -4;
    int     b = 0;
    char    c = 'a';
    int     d = 2147483647;
    int     e = -2147483648;
    int     f = 42;
    int     g = 25;
    int     h = 4200;
    int     i = 8;
    int     j = -12;
    int     k = 123456789;
    int     l = 0;
    int     m = -12345678;
    char    *n = "abcdefghijklmnop";
    char    *o = "-a";
    char    *p = "ah";
    char    *q = "0";
    char    *r = "%%";
    char    *s = NULL;
    char    *t = "0x12345678";
    char    *u = "-0";

	a = 0;
	b = -2;
ft = ft_printf("-->|%-16.p|<--\n", p);
	printf("\n");
real = printf("-->|%-16.p|<--\n", p);
	printf("\n");


//ft = ft_printf("%5c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	printf("\n");
//real = printf("%5c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
//real =	printf("%%%d", h, "bada", r, p, r, r, i, r, i, r, i);
//ft_printf("%.s, %.s, %.s, %.s, %.s", n, n, n, n, n);
	printf("\n");
	printf("this is the fake deal %d" , ft);
//  printf("%.s, %.s, %.s, %.s, %.s", n, n, n, n, n);
	printf("\n");
	printf("this is the real deal %d" , real);
/*	ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);

	printf("\n");
	printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
		printf("\n");
	//ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d);
	printf("\n");
ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	printf("\n");
//	printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d);
 printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);

	printf("\n");
	ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	printf("\n");
	printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	printf("\n");
	ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d",a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	printf("\n");
	printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d",a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	printf("\n");
	/*	printf("%-12s0*@ \n", "bada"); 
		ft_printf("%-12s0*@ \n", "bada"); 

	
	
	
	printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i); 
	printf("\n");
	ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i); 
	printf("\n");
	

	pointer = &c;
 ft = ft_printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12, i);
 ft = printf("w %015i %017.15i %020i %.*i \n", i, i, i, 12, i);
 	ft_printf("%*i, %*d, %*d, %*d \n", ii, ii, ii, ii, ii, ii, ii ,ii );
 	printf("%*i, %*d, %*d, %*d \n", ii, ii, ii, ii, ii, ii, ii ,ii );

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


*/

    return 0;
}
