/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyhandling.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:30:35 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:17:07 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_hooks(t_cub3d *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, &ft_keypress, cub);
	mlx_hook(cub->win, 3, 1L << 1, &ft_keyrelease, cub);
	mlx_hook(cub->win, 17, 1L << 19, &ft_exit, cub);
	return (0);
}

int		ft_exit(void)
{
	exit(0);
	return (0);
}

int		ft_keypress(int key, t_cub3d *cub)
{
	if (key == 13 || key == 126)
		cub->move.ver = -1;
	else if (key == 1 || key == 125)
		cub->move.ver = 1;
	else if (key == 0)
		cub->move.hor = -1;
	else if (key == 2)
		cub->move.hor = 1;
	else if (key == 123)
		cub->move.rotdir = -1;
	else if (key == 124)
		cub->move.rotdir = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int		ft_keyrelease(int key, t_cub3d *cub)
{
	if (key == 13 || key == 126)
		cub->move.ver = 0;
	else if (key == 1 || key == 125)
		cub->move.ver = 0;
	else if (key == 0)
		cub->move.hor = 0;
	else if (key == 2)
		cub->move.hor = 0;
	else if (key == 123)
		cub->move.rotdir = 0;
	else if (key == 124)
		cub->move.rotdir = 0;
	else if (key == 53)
		exit(0);
	return (0);
}
