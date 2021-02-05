/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:30:09 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:28:11 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_floodfill(t_map *copy, int x, int y)
{
	if (ft_check_valid_map(copy, x, y) == 1)
		return ;
	if (copy->grid[y][x] == '2')
		(copy->spritecount)++;
	copy->grid[y][x] = 'x';
	if (ft_find_char(copy->grid[y - 1][x], "02 ") == 1)
		ft_floodfill(copy, x, y - 1);
	if (ft_find_char(copy->grid[y - 1][x + 1], "02 ") == 1)
		ft_floodfill(copy, x + 1, y - 1);
	if (ft_find_char(copy->grid[y][x + 1], "02 ") == 1)
		ft_floodfill(copy, x + 1, y);
	if (ft_find_char(copy->grid[y + 1][x + 1], "02 ") == 1)
		ft_floodfill(copy, x + 1, y + 1);
	if (ft_find_char(copy->grid[y + 1][x], "02 ") == 1)
		ft_floodfill(copy, x, y + 1);
	if (ft_find_char(copy->grid[y + 1][x - 1], "02 ") == 1)
		ft_floodfill(copy, x - 1, y + 1);
	if (ft_find_char(copy->grid[y][x - 1], "02 ") == 1)
		ft_floodfill(copy, x - 1, y);
	if (ft_find_char(copy->grid[y - 1][x - 1], "02 ") == 1)
		ft_floodfill(copy, x - 1, y - 1);
}

int		ft_check_valid_map(t_map *copy, int x, int y)
{
	int above;
	int beyond;

	if (y == 0 || (y + 1) == copy->rows || x == 0 ||
		copy->grid[y][x + 1] == '\0' || copy->error == 0 ||
		copy->grid[y][x] == ' ' || copy->grid[y][x] == '\0')
	{
		copy->error = 0;
		return (1);
	}
	above = ft_linelen(copy->grid[y - 1], '\0');
	beyond = ft_linelen(copy->grid[y + 1], '\0');
	if (x > above || x > beyond)
	{
		copy->error = 0;
		return (1);
	}
	return (0);
}
