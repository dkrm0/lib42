#include <stddef.h>
#include "str_42.h"

char	*ft_strrev(char *str)
{
	size_t	half;
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	if (len % 2 == 0)
		half = len / 2;
	else
		half = (len - 1) / 2;
	--len;
	while (i < half)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i++] = tmp;
	}
	return (str);
}
