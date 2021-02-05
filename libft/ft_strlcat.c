/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 10:19:47 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/19 11:16:32 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	len = 0;
	index = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	while (dst[len] != '\0' && len < size)
	{
		len++;
	}
	while ((src[index] != '\0') && ((len + index + 1) < size))
	{
		dst[len + index] = src[index];
		index++;
	}
	if (len < size)
	{
		dst[len + index] = '\0';
	}
	return (len + ft_strlen(src));
}
