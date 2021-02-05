/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/06 14:09:15 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/12 11:18:30 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *next;

	next = *lst;
	if (del == NULL)
		return ;
	while (next != NULL)
	{
		current = next;
		next = current->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
