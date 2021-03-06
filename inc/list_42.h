#ifndef LIST_42_H
# define LIST_42_H

# include <stddef.h>
# include <stdarg.h>
# include <stdbool.h>
# include "pool_42.h"

# define LIST_NODE_SIZE(e)	((e) + sizeof(t_list_node))
# define LIST_NODE_DATA(e)	((void*)(((t_list_node*)e) + 1))

typedef struct			s_list_node
{
	struct s_list_node	*prev;
	struct s_list_node	*next;
}						t_list_node;

typedef struct			s_list
{
	t_pool				*pool;
	t_list_node			*head;
	t_list_node			*tail;
	size_t				len;
	size_t				elem_size;
}						t_list;

typedef void			*(*t_list_map)(const void *data, va_list ap);
typedef void			(*t_list_apply)(void *data, va_list ap);
typedef void			*(*t_list_fold)(void *acc, void *data, va_list ap);
typedef bool			(*t_list_filter)(const void *data, va_list ap);
typedef int				(*t_list_compare)(const void *e1, const void *e2);

t_list_node				*list_internal_new_node_with_copy(t_list *list,
		const void *elem);

/*
** Allocate a new `t_list` and initialize all internal fields
*/
t_list					*list_create(size_t elem_size);

/*
** Free the `t_list` and all internal data
*/
void					list_destroy(t_list *list);

/*
** Initialize an already existing `t_list` structure
*/
t_list					*list_init(t_list *list, size_t elem_size);

/*
** Free all the internal fields of an existing `t_list` structure
*/
void					list_shutdown(t_list *list);

/*
** Returns a pointer to the element at the specified index
** or NULL if index is out of range
*/
void					*list_get_at(const t_list *list, size_t index);
void					*list_get_first(const t_list *list);
void					*list_get_last(const t_list *list);

/*
** Copy the element `elem` in the list at the index specified
** Returns a pointer to the copied element in the list or NULL
*/
void					*list_set_at(t_list *list, size_t index,
		const void *elem);

/*
** Push an element to the head of the list.
** Returns a pointer to the copied element in the list or NULL
*/
void					*list_push_front(t_list *list, const void *elem);

/*
** Push an element to the tail of the list.
** Returns a pointer to the copied element in the list or NULL
*/
void					*list_push_back(t_list *list, const void *elem);

/*
** Pop the element at the head of the list.
** Returns the list pointer or NULL
*/
t_list					*list_pop_front(t_list *list, void *poped_elem);

/*
** Pop the element at the tail of the list.
** Returns the list pointer or NULL
*/
t_list					*list_pop_back(t_list *list, void *poped_elem);

/*
** Insert an element at the specified index.
** Returns a pointer to the copied element in the list or NULL
*/
void					*list_insert_at(t_list *list, size_t index,
		const void *elem);

/*
** Remove the element at the given index
** If `removed` is not NULL, the removed element data is written inside it
** Returns NULL if the index is out of bounds
*/
t_list					*list_remove_at(t_list *list, size_t index,
		void *removed);

/*
** Set the length of the list to 0
** Returns NULL in case of error
*/
t_list					*list_clear(t_list *list);

/*
** Apply the function `f` to each element of the list and build a list with
** the results.
** Returns a new list or NULL in case of error
*/
t_list					*list_map(const t_list *list, t_list_map f,
		size_t new_elem_size, ...);

/*
** Apply the function `f` to each element of the list.
** The function `f` shall takes 2 parameters of the same type
** and return one of the same type.
** Returns the folding of the list or NULL in case of error
*/
void					*list_fold_left(const t_list *list, t_list_fold f,
		void *init_val, ...);

/*
** Apply the function `f` to each element of the list.
** Can modify elements of the list.
** Generally used for side effect.
** TODO: test
*/
void					list_apply(t_list *list, t_list_apply f, ...);

/*
** Construct a new list with the elements that match the function `f`
** Returns a new list or NULL in case of error
** TODO: test
*/
t_list					*list_filter(const t_list *list, t_list_filter f, ...);

/*
** Swap the 2 elements at index `e1` and `e2`
** TODO: test
*/
t_list					*list_swap(t_list *list, size_t e1, size_t e2);

/*
** Sort the list according to the compare function `f`
** TODO: test
*/
t_list					*list_sort(t_list *list, t_list_compare f);

/*
** Returns a new list which contains each unique members of the list `list`
*/
t_list					*list_uniq_sorted(const t_list *list, t_list_compare f);
t_list					*list_uniq_unsorted(const t_list *list,
		t_list_compare f);

/*
** Returns a copy of the list `list`
** TODO: test
*/
t_list					*list_copy(const t_list *list);

/*
** Returns true if the list contains the data pointed to by `elem`
** TODO: test
*/
bool					list_contains(const t_list *list, const void *elem,
		t_list_compare cmp);

#endif
