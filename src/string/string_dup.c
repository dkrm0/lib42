#include <stddef.h>
#include "memory_42.h"
#include "str_42.h"
#include "string_42.h"

t_string	*string_init_ndup(t_string *s, const char *str, size_t len)
{
	if (string_init_with_capacity(s, len) == NULL)
		return (NULL);
	ft_memcpy(s->str, str, len);
	s->len = len;
	s->str[s->len] = '\0';
	return (s);
}

t_string	*string_init_dup(t_string *s, const char *str)
{
	return (string_init_ndup(s, str, ft_strlen(str)));
}

t_string	*string_create_dup(const char *str)
{
	return (string_create_ndup(str, ft_strlen(str)));
}

t_string	*string_create_ndup(const char *str, size_t len)
{
	t_string	*s;

	if ((s = string_create_with_capacity(len)) == NULL)
		return (NULL);
	ft_memcpy(s->str, str, len);
	s->len = len;
	s->str[s->len] = '\0';
	return (s);
}
