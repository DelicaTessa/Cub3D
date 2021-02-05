/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 21:08:12 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/19 10:18:14 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != (char)c)
	{
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return ((char *)s + index);
}
