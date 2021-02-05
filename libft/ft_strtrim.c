/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 13:33:22 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/20 11:07:41 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

static int		ltrim(char const *s1, const char *set)
{
	int	len;
	int	start;

	start = 0;
	len = ft_strlen(s1);
	while (start < len && ft_strchr(set, s1[start]) != NULL)
		start++;
	return (start);
}

static int		rtrim(char const *s1, const char *set)
{
	int stop;

	stop = ft_strlen(s1);
	while (stop >= 0 && ft_strchr(set, s1[stop]) != NULL)
		stop--;
	return (stop);
}

static char		*copystring(char const *s1, int start, int stop)
{
	char *str;

	if (start > stop)
		return (ft_strdup(""));
	str = ft_calloc(stop - start + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s1 + start, (stop - start) + 1);
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		stop;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = ltrim(s1, set);
	stop = rtrim(s1, set);
	str = copystring(s1, start, stop);
	if (str == NULL)
		return (NULL);
	return (str);
}
