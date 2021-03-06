#include <stddef.h>
#include <stdlib.h>
#include "array_42.h"

t_array			*array_create(size_t elem_size)
{
	return (array_create_with_capacity(elem_size, ARRAY_INIT_SIZE));
}

t_array			*array_create_with_capacity(size_t elem_size, size_t capacity)
{
	t_array		*a;

	a = malloc(sizeof(t_array));
	if (a == NULL)
		return (NULL);
	if (array_init_with_capacity(a, elem_size, capacity) == NULL)
	{
		free(a);
		return (NULL);
	}
	return (a);
}

void			array_destroy(t_array *a)
{
	free(a->data);
	free(a);
}
