int ft_istype(char c)
{
    if (c == 'p' || c == '%' || c == 'c' || c == 'u' || c == 'i' || c == 's' || c == 'f' || c == 'x' || c == 'X' || c == 'd')
        return 1;
    else return 0;
}
