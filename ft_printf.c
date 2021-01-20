#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
struct	fandf
{
	char *flags;
	int width;
	char type;
	int lenflags;
};

void innit_struct(struct fandf *info)
{

	info->flags = NULL ;
	info->width = 0;
	info->type = 0;
	info->lenflags = 0;

}


int	ft_lenflags(const char *str)
{
	int i;

	i = 0;

	while (str[i] != ' ' && str[i])
		i++;
	return i;
}

char	*ft_appendchar(char const *s1, char const s2)
{
	int		size;
	char	*retstr;
	int		i;
	int		c;

	i = 0;
	c = 0;

	if (!s1)
	{
		retstr = (char*)malloc(sizeof(retstr) * 2);
		retstr[0] = s2;
		retstr[1] = '\0';
		return retstr;
	}
	else
		size = ft_strlen(s1) + 1;
	if (!(retstr = (char*)malloc(sizeof(retstr) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		retstr[i] = s1[i];
		i++;
	}
	retstr[i++] = s2;
	retstr[i] = '\0';
	return (retstr);
}

struct fandf	*fill(const char *str, struct fandf *info)
{
	int i;
	i = 1;

	info->lenflags = ft_lenflags(&str[i]) + 1;
	while (isflag(str[i]))
			info->flags = ft_appendchar(info->flags, str[i++]);
	if (ft_isdigit(str[i]))
		info->width = ft_atoi(&str[i]);
	while(ft_isdigit(str[i]))
		i++;
	if(ft_istype(str[i]))
		info->type = str[i];




//	printf("this is whats in my struct: %s \n", info->flags);
//	printf("this is whats in my struct: %i \n", info->width);
//	printf("this is whats in my struct: %c \n", info->type);
return (info);
}

int	ft_convertme(va_list ap, struct fandf *info)
{
	if (info->type == 'i')
		ft_putstr(ft_itoa(va_arg(ap, int)));
	if (info->type == 's')
		ft_putstr(va_arg(ap, char *));

	return 1;
}


int ft_printf(const char *formatstring, ...)
{
	va_list	ap;
	struct fandf *info;
	int i;

	va_start(ap, formatstring);
	while (formatstring[i])
	{
		if (formatstring[i] != '%')
			ft_putchar(formatstring[i++]);
		else
		{
			innit_struct(info);
			fill(&formatstring[i], info);
			ft_convertme(ap, info);
			i = i + info->lenflags;
		}
	}
	return 0;
}

int main()
{
	int i = 1000;
	int unautrei = 2000;
	int encoreunautrei = 30000;	
//	int canarretepas = 12;	

//	ft_printf("here take some string %-177i does this work? %-10i how bout one more? %-12i and finally %i", i, unautrei, encoreunautrei, canarretepas); 
	ft_printf("here take some string %-177i does this work? %-10i", i, unautrei); 
//	ft_printf("here take some string %-i does this work? %-i %-i", i, unautrei, encoreunautrei); 


	return 0;
}
