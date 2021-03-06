/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:36:06 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 15:50:47 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_skipspace(char *line, int *i)
{
	while ((line[*i] == '\f') || (line[*i] == '\r') || (line[*i] == '\n') \
	|| (line[*i] == '\t') || (line[*i] == '\v') || (line[*i] == ' '))
	{
		(*i)++;
	}
}
