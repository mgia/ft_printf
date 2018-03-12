#include "libft.h"

char			*ft_strrev(char *str)
{
	int 	l;
	int 	i;
	char 	temp;

	l = ft_strlen(str) - 1;
	i = 0;
	while (i < (l - i))
	{
		temp = str[i];
		str[i] = str[l - i];
		str[l - i] = temp;
		i++;
	}
	return (str);
}
