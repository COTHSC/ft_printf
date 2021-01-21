#include "libft/libft.h"
#include <stdio.h>



int ft_printf(const char *formatstring, ...);

int main()
{
    int i = 1000;
    int unautrei = 2000;
    int encoreunautrei = 30000;
    int canarretepas = 12;
	float dec = 3.12345;
    char *soyonsfous = "this is a strong string";
	char *strf;

	//strf = ft_ftoa(dec);
	//printf("this is the float %s \n", strf);
	//printf("this is the float %f \n", dec);

//	ft_printf("here take some string %-177i does this work? %-10i how bout one more? %-12i and finally %i why stop there? %-12s \n", i, unautrei, encoreunautrei, canarretepas, soyonsfous);
/*    ft_printf("w %3f \n", dec);
    ft_printf("w %3i \n", i);
    ft_printf("w %25i \n", i);
    ft_printf("w %33i \n", i);
    ft_printf("w %15i \n", i);
    ft_printf("w %5i \n", i);   
   	ft_printf("w %-5i \n", i);
    ft_printf("w %-25i \n", i);
    ft_printf("w %-33i \n", i);
    ft_printf("w %-15i \n", i);
    ft_printf("w %-5i \n", i);*/
	ft_printf("w %3.522i \n", i);
   /* printf("w %3.1f \n", dec);
    printf("w %3.0f \n", dec);
    printf("w %3.12f \n", dec);
    printf("w %3.4f \n", dec);
    printf("w %15i \n", i);
    printf("w %5i \n", i);   
   	printf("w %-5i \n", i);
    printf("w %-25i \n", i);
    printf("w %-33i \n", i);
    printf("w %-15i \n", i);
    printf("w %-5i \n", i);*/


//    ft_printf("here take some string %-177i does this work? %-10i \n", i, encoreunautrei);
//    ft_printf("here take some string %-i does this work? %-i %-i \n", i, unautrei, encoreunautrei);


    return 0;
}
