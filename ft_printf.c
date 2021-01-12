#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
struct	fandf
{
	char *flags;
	int width;
	char type;
};



int	isflag(char c)
{
	if (c == '-')
		return 1;
	else return 0;
}

int	ft_putstr(char *str)
{
	int size;

	size = ft_strlen(str);
	write(1, str, size);
	return 1;
}

int	ft_istype(char c)
{
	if (c == 'i')
		return 1;
	else return 0;
}

struct fandf innit_struct()
{
	struct fandf info;

	info.flags = NULL ;
	info.width = 0;
	info.type = 'i';

	return info;
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
	int i = 0;

	if (str[i++] == '%')
	{
		while (isflag(str[i]))
				info->flags = ft_appendchar(info->flags, str[i++]);
		if (ft_isdigit(str[i]))
			info->width = ft_atoi(&str[i]);
		while(ft_isdigit(str[i]))
			i++;
		if(ft_istype(str[i]))
				info->type = str[i];
	}


	printf("this is whats in my struct: %s \n", info->flags);
	printf("this is whats in my struct: %i \n", info->width);
	printf("this is whats in my struct: %c \n", info->type);
	return (info);
}

int	ft_convertme(va_list ap, struct fandf *info)
{
	if (info->type == 'i')
		ft_putstr(ft_itoa(va_arg(ap, int)));
	return 1;
}


int ft_printf(const char *formatstring, ...)
{
	va_list	ap;
	struct fandf *info;

	*info = innit_struct();
	va_start(ap, formatstring);
	info = fill(formatstring, info);
	ft_convertme(ap, info);

	return 0;
}



int main()
{
	int i = 100;
	
	ft_printf("%-177i", i); 

	return 0;
}
