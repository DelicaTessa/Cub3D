/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 14:51:04 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 15:37:59 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_find_char(char c, char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (c == str[index])
			return (1);
		index++;
	}
	if (c == '\0')
		return (1);
	return (0);
}
