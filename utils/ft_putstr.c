#include "../libft/libft.h"

int ft_putstr(char *str)
{
    int size;

    size = ft_strlen(str);
    write(1, str, size);
    return size;
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}
