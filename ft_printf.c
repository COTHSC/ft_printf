#include <stdlib.h>
#include <stdio.h>
//#include "libft/libft.h"
struct	fandf
{
	char *flags;
	int width;
	char type;
};

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	isflag(char c)
{
	if (c == '-')
		return 1;
	else return 0;
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <='9')
		return 1;
	else return 0;
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

int		ft_atoi(char *str)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

char	*ft_convert(

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

struct fandf	*fill(char *str, struct fandf *info)
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





int main()
{
	char *strtoparse = "%--10i";
	struct fandf info;

	info = innit_struct();

	fill(strtoparse, &info);

	
	return 0;
}
