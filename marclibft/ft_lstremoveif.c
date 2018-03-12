#include "libft.h"

/*
**	Checks if content_size == i, and removes the node.
*/

void				ft_lstremoveif(t_list **alst, int i)
{
	t_list	*curr;
	t_list	*prev;

	curr = *alst;
	// head
	if ((int)curr->content_size == i)
	{
		*alst = (*alst)->next;
		free(curr->content);
		free(curr);
		return ;
	}
	while (curr)
	{
		prev = curr;
		if ((int)curr->content_size == i)
		{
			prev->next = curr->next;
			free(curr->content);
			free(curr);
			return ;
		}
		curr = curr->next;
	}
}

// int 	main()
// {
// 	t_list	*list;
// 	t_list	*curr;
//
//
// 	list = ft_lstnew("1",1);
// 		ft_lstadd(&list, ft_lstnew("2",2));
// 			ft_lstadd(&list, ft_lstnew("3",3));
// 				ft_lstadd(&list, ft_lstnew("4",4));
// 					ft_lstadd(&list, ft_lstnew("5",5));
// 	curr = list;
// 	ft_lstremoveif(&list, 5);
// 	while (curr)
// 	{
// 		printf("%s", curr->content);
// 		curr = curr->next;
// 	}
// 	while(1)
// 		;
// 	return (0);
// }
