/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 13:34:22 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/25 10:02:20 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordcount(const char *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c && s[index + 1] != c && s[index + 1] != '\0')
			count++;
		index++;
	}
	return (count + 1);
}

static char		*split_strings(char const **s, char c)
{
	int		index;
	int		idx;
	char	*str;
	char	*string;

	str = (char*)*s;
	index = 0;
	while (str[index] != '\0' && str[index] != c)
		index++;
	idx = 0;
	string = ft_calloc(index + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	while (idx < index)
	{
		string[idx] = *str;
		str++;
		idx++;
	}
	string[idx] = '\0';
	while (*str != '\0' && *str == c)
		str++;
	*s = str;
	return (string);
}

static char		**clear_strings(char **strings, int idx)
{
	while (idx > 0)
	{
		idx--;
		free(strings[idx]);
	}
	free(strings);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strings;
	int		index;
	int		idx;

	if (s == NULL)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	idx = 0;
	index = wordcount(s, c);
	strings = ft_calloc(index + 1, sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (idx < index && *s != '\0')
	{
		strings[idx] = split_strings(&s, c);
		if (strings[idx] == NULL)
		{
			clear_strings(strings, idx);
			return (NULL);
		}
		idx++;
	}
	strings[idx] = NULL;
	return (strings);
}
