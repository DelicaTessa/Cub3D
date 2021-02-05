/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 13:09:37 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 15:39:21 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;
	size_t	count;

	index = 0;
	if (!needle)
		return ((char *)haystack);
	while (haystack[index])
	{
		count = 0;
		while (haystack[index] == needle[count])
		{
			index++;
			count++;
			if (needle[count] == '\0')
				return ((char *)haystack + index - count);
		}
		if ((count > 0) && !(haystack[index] == needle[count]))
			index = index - count + 1;
		if (count == 0)
			index++;
	}
	return (0);
}
