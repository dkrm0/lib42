#include <stddef.h>
#include "str_42.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	return (ft_strnstr(s1, s2, ft_strlen(s1)));
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
			while (s1[i + j] == s2[j] && i + j < n)
				if (s2[++j] == '\0')
					return ((char*)s1 + i);
		++i;
	}
	return (NULL);
}
