/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_linelen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 13:13:37 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 15:37:52 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(const char *s, char n)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != n)
		len++;
	return (len);
}
