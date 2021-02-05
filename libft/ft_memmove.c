/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 10:27:48 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/13 20:54:15 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*dest;
	unsigned const char	*src;

	dest = (unsigned char*)s1;
	src = (unsigned const char*)s2;
	if (s1 == NULL && s2 == NULL && n > 0)
		return (dest);
	else if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
	}
	return ((char *)s1);
}
