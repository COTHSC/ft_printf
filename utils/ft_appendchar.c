#include "../libft/libft.h"
char    *ft_appendchar(char const *s1, char const s2)
{
    int     size;
    char    *retstr;
    int     i;
    int     c;

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
