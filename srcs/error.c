/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:29:47 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:31:54 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == 1)
		ft_putstr_fd("Couldn't make bitmap\n", 2);
	else if (error == 2)
		ft_putstr_fd("File descriptor error\n", 2);
	else if (error == 3)
		ft_putstr_fd("No map file\n", 2);
	else if (error == 4)
		ft_putstr_fd("Too many arguments\n", 2);
	else if (error == 5)
		ft_putstr_fd("Can't read file\n", 2);
	else if (error == 6)
		ft_putstr_fd("File doesn't have .cub extension\n", 2);
	else if (error == 7)
		ft_putstr_fd("Problem with map elements\n", 2);
	else if (error == 8)
		ft_putstr_fd("Map is invalid\n", 2);
	else if (error == 9)
		ft_putstr_fd("Maze is invalid\n", 2);
	else if (error == 10)
		ft_putstr_fd("Malloc error\n", 2);
	else if (error == 11)
		ft_putstr_fd("MLX error\n", 2);
	exit(1);
	return (1);
}
