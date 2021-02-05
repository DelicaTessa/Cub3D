/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 10:28:41 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/11 11:58:52 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*ptr;
	size_t				index;

	ptr = (unsigned const char*)s;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == (unsigned char)c)
		{
			return ((char *)s + index);
		}
		index++;
	}
	return (NULL);
}
