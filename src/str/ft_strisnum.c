#include <stdbool.h>
#include "ctype_42.h"

bool	ft_strisnum(const char *s)
{
	if (s[0] == '+' || s[0] == '-')
		s += 1;
	if (!FT_ISDIGIT(s[0]))
		return (0);
	while (FT_ISDIGIT(s[0]))
		s += 1;
	return (s[0] == '\0');
}
