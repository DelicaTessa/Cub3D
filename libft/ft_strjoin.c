/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 13:31:44 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/13 20:36:59 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		counter;
	char	*new;

	index = 0;
	counter = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		new[index] = s1[index];
		index++;
	}
	while (s2[counter] != '\0')
	{
		new[index + counter] = s2[counter];
		counter++;
	}
	new[index + counter] = '\0';
	return (new);
}
