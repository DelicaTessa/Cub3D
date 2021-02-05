/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:34:07 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 16:01:10 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_delta(t_cub3d *cub)
{
	if (cub->ray.ray_ydir == 0)
		cub->ray.vert_delta = 1;
	else
		cub->ray.vert_delta = 0;
	if (cub->ray.ray_xdir == 0)
		cub->ray.hor_delta = 1;
	else
		cub->ray.hor_delta = 0;
}

void	ft_cast_ray(t_cub3d *cub)
{
	int x;

	x = 0;
	while (x < cub->map->width)
	{
		cub->ray.cam_x = -1 + (x / (double)cub->map->width) * 2;
		cub->ray.ray_xdir = cub->ray.player_xdir +
		cub->ray.xplane * cub->ray.cam_x;
		cub->ray.ray_ydir = cub->ray.player_ydir +
		cub->ray.yplane * cub->ray.cam_x;
		cub->ray.ray_xpos = (int)cub->ray.player_xpos;
		cub->ray.ray_ypos = (int)cub->ray.player_ypos;
		ft_set_delta(cub);
		if (cub->ray.ray_xdir != 0 && cub->ray.ray_ydir != 0)
		{
			cub->ray.hor_delta = sqrt(1 + (cub->ray.ray_ydir *
			cub->ray.ray_ydir) / (cub->ray.ray_xdir * cub->ray.ray_xdir));
			cub->ray.vert_delta = sqrt(1 + (cub->ray.ray_xdir *
			cub->ray.ray_xdir) / (cub->ray.ray_ydir * cub->ray.ray_ydir));
		}
		ft_step_dir(cub);
		ft_find_wall_hit(cub);
		ft_get_wall_values(cub, x);
		x++;
	}
}

void	ft_step_dir(t_cub3d *cub)
{
	if (cub->ray.ray_xdir < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.hor = (cub->ray.player_xpos -
		cub->ray.ray_xpos) * cub->ray.hor_delta;
	}
	else if (cub->ray.ray_xdir >= 0)
	{
		cub->ray.stepx = 1;
		cub->ray.hor = (cub->ray.ray_xpos + 1 -
		cub->ray.player_xpos) * cub->ray.hor_delta;
	}
	if (cub->ray.ray_ydir < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.ver = (cub->ray.player_ypos -
		cub->ray.ray_ypos) * cub->ray.vert_delta;
	}
	else if (cub->ray.ray_ydir >= 0)
	{
		cub->ray.stepy = 1;
		cub->ray.ver = (cub->ray.ray_ypos + 1 -
		cub->ray.player_ypos) * cub->ray.vert_delta;
	}
}

void	ft_set_step_dir(t_cub3d *cub)
{
	cub->ray.stepx = 0;
	cub->ray.stepy = 0;
	cub->ray.hor = 0;
	cub->ray.ver = 0;
}

void	ft_find_wall_hit(t_cub3d *cub)
{
	cub->ray.hit = 0;
	while (cub->ray.hit == 0)
	{
		if (cub->ray.hor < cub->ray.ver)
		{
			cub->ray.dir = 0;
			cub->ray.ray_xpos = cub->ray.ray_xpos + cub->ray.stepx;
			cub->ray.hor = cub->ray.hor + cub->ray.hor_delta;
		}
		else
		{
			cub->ray.dir = 1;
			cub->ray.ray_ypos = cub->ray.ray_ypos + cub->ray.stepy;
			cub->ray.ver = cub->ray.ver + cub->ray.vert_delta;
		}
		if (cub->map->grid[cub->ray.ray_ypos][cub->ray.ray_xpos] == '1')
			cub->ray.hit = 1;
		else
			cub->ray.hit = 0;
	}
}
