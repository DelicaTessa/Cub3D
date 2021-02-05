/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:27:17 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:20:03 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	ft_set_map_struct(t_map *info)
{
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->spr = NULL;
	info->grid = NULL;
	info->copy = NULL;
	info->zbuf = NULL;
	info->sprites = NULL;
	info->spritecount = 0;
	info->start = 0;
	info->bitmap = 0;
	info->res = 0;
	info->fr = -1;
	info->fg = -1;
	info->fb = -1;
	info->cr = -1;
	info->cg = -1;
	info->cb = -1;
	info->width = -1;
	info->height = -1;
	info->dir = '\0';
	info->rows = 1;
	info->error = 1;
	return (*info);
}

void	ft_set_move_struct(t_cub3d *cub)
{
	cub->map->res = cub->map->width * cub->map->height;
	cub->move.movspeed = 0.05 * (cub->map->res / (1280 * 720));
	if (cub->move.movspeed < 0.05)
		cub->move.movspeed = 0.05;
	if (cub->move.movspeed > 0.2)
		cub->move.movspeed = 0.2;
	cub->move.dir = cub->move.movspeed;
	cub->move.strafe = (sqrt(pow(cub->move.movspeed, 2) +
	pow(cub->move.movspeed, 2))) / 2;
	cub->move.rotspeed = 0.05;
	cub->move.ver = 0;
	cub->move.hor = 0;
	cub->move.rotdir = 0;
	cub->move.newpos_x = cub->ray.player_xpos;
	cub->move.newpos_y = cub->ray.player_ypos;
	cub->fd = -1;
}
