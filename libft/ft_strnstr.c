/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 19:14:41 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/18 11:10:06 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	count;

	index = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[index] && index < len)
	{
		count = 0;
		while (haystack[index + count] == needle[count] &&
				index + count < len)
		{
			count++;
			if (!needle[count])
				return ((char *)haystack + index);
		}
		index++;
	}
	return (NULL);
}
