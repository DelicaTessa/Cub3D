/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:32:05 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:24:36 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_move_vals_one(t_cub3d *cub)
{
	if (cub->move.ver != 0 && cub->move.hor != 0)
		cub->move.movspeed = cub->move.strafe;
	else
		cub->move.movspeed = cub->move.dir;
	if (cub->move.ver == -1)
	{
		cub->move.newpos_x = cub->ray.player_xpos +
		(cub->ray.player_xdir * cub->move.movspeed);
		cub->move.newpos_y = cub->ray.player_ypos +
		(cub->ray.player_ydir * cub->move.movspeed);
	}
	ft_check_wall_spr_coll(cub);
	if (cub->move.ver == 1)
	{
		cub->move.newpos_x = cub->ray.player_xpos -
		(cub->ray.player_xdir * cub->move.movspeed);
		cub->move.newpos_y = cub->ray.player_ypos -
		(cub->ray.player_ydir * cub->move.movspeed);
	}
	ft_check_wall_spr_coll(cub);
	ft_set_move_vals_two(cub);
}

void	ft_set_move_vals_two(t_cub3d *cub)
{
	if (cub->move.hor == 1)
	{
		cub->move.newpos_x = cub->ray.player_xpos +
		(cub->ray.player_ydir * cub->move.movspeed * -1);
		cub->move.newpos_y = cub->ray.player_ypos +
		(cub->ray.player_xdir * cub->move.movspeed);
	}
	ft_check_wall_spr_coll(cub);
	if (cub->move.hor == -1)
	{
		cub->move.newpos_x = cub->ray.player_xpos +
		(cub->ray.player_ydir * cub->move.movspeed);
		cub->move.newpos_y = cub->ray.player_ypos +
		(cub->ray.player_xdir * cub->move.movspeed * -1);
	}
	ft_check_wall_spr_coll(cub);
}

void	ft_check_wall_spr_coll(t_cub3d *cub)
{
	if (cub->map->grid[(int)cub->ray.player_ypos][(int)(2 * cub->move.newpos_x
		- cub->ray.player_xpos)] == '0')
		cub->ray.player_xpos = cub->move.newpos_x;
	if (cub->map->grid[(int)(2 * cub->move.newpos_y -
		cub->ray.player_ypos)][(int)cub->ray.player_xpos] == '0')
		cub->ray.player_ypos = cub->move.newpos_y;
}

void	ft_set_rot_vals(t_cub3d *cub)
{
	if (cub->move.rotdir != 0)
	{
		cub->move.previous_x = cub->ray.player_xdir;
		cub->ray.player_xdir = (cub->ray.player_xdir * cos(cub->move.rotspeed))
		- ((cub->ray.player_ydir * sin(cub->move.rotspeed)) * cub->move.rotdir);
		cub->ray.player_ydir = (cub->ray.player_ydir * cos(cub->move.rotspeed))
		+ ((cub->move.previous_x * sin(cub->move.rotspeed)) * cub->move.rotdir);
		cub->move.previous_x = cub->ray.xplane;
		cub->ray.xplane = (cub->ray.xplane * cos(cub->move.rotspeed))
		- ((cub->ray.yplane * sin(cub->move.rotspeed)) * cub->move.rotdir);
		cub->ray.yplane = (cub->ray.yplane * cos(cub->move.rotspeed))
		+ ((cub->move.previous_x * sin(cub->move.rotspeed)) * cub->move.rotdir);
	}
}
