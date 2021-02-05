/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_expand.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 10:48:16 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 15:38:40 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_expand(char **str, int size, int expand)
{
	int		index;
	char	*copy;

	index = 0;
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (copy == NULL)
		return (0);
	while (index < size)
	{
		copy[index] = (*str)[index];
		index++;
	}
	free(*str);
	*str = (char *)malloc(sizeof(char) * (size + expand + 1));
	while ((index > 0) && !(*str == 0))
	{
		index--;
		(*str)[index] = copy[index];
	}
	free(copy);
	if (*str == 0)
		return (0);
	(*str)[size + index] = '\0';
	return (size + index + 1);
}
