/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_sprites_one.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:34:45 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:16:21 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_count_sprites(t_cub3d *cub)
{
	int y;
	int x;
	int loc;

	loc = 0;
	y = 0;
	while (cub->map->grid[y] != NULL)
	{
		x = 0;
		while (cub->map->grid[y][x] != '\0')
		{
			if (cub->map->grid[y][x] == '2' &&
				cub->map->copy->grid[y][x] == 'x')
			{
				cub->map->sprites[loc].y = y + 0.5;
				cub->map->sprites[loc].x = x + 0.5;
				loc++;
			}
			x++;
		}
		y++;
	}
}

void	ft_get_sprites(t_cub3d *cub, int index)
{
	if (cub->map->spritecount <= 0)
		return ;
	while (index < cub->map->spritecount)
	{
		cub->map->sprites[index].dist = pow((cub->ray.player_xpos -
		cub->map->sprites[index].x), 2) +
		pow((cub->ray.player_ypos - cub->map->sprites[index].y), 2);
		index++;
	}
	ft_get_spr_array(&(cub->map->sprites), cub->map->sprites[0],
	0, cub->map->spritecount - 1);
	index = 0;
	if (cub->frame % 2 == 1)
		cub->spr.spr_img = &(cub->img_one);
	else
		cub->spr.spr_img = &(cub->img_two);
	while (index < cub->map->spritecount)
	{
		ft_set_spr_dims(cub, index);
		ft_get_spr_vals(cub);
		ft_load_sprite(cub);
		index++;
	}
}

void	ft_get_spr_array(t_sprite **sprite, t_sprite spr, int index, int count)
{
	int nmbr;
	int i;
	int k;

	nmbr = index;
	i = 0;
	k = 1;
	while (count > index)
	{
		if ((*sprite)[nmbr].dist * k < (*sprite)[nmbr + k].dist * k)
			i = 0;
		else
			i += 1;
		ft_set_spr_array(&(*sprite), spr, k, nmbr);
		nmbr = nmbr + k;
		if ((k == -1 && nmbr == index) || (k == 1 && nmbr == count))
		{
			k = k * -1;
			nmbr = nmbr + (i + 1) * k;
			if (k == 1)
				index = nmbr;
			if (k == -1)
				count = nmbr;
		}
	}
}

void	ft_set_spr_array(t_sprite **sprite, t_sprite spr, int k, int nmbr)
{
	if ((*sprite)[nmbr].dist * k < (*sprite)[nmbr + k].dist * k)
	{
		spr = (*sprite)[nmbr];
		(*sprite)[nmbr] = (*sprite)[nmbr + k];
		(*sprite)[nmbr + k] = spr;
	}
}

void	ft_set_spr_dims(t_cub3d *cub, int index)
{
	double	val;
	double	x;
	double	y;

	x = cub->map->sprites[index].x - cub->ray.player_xpos;
	y = cub->map->sprites[index].y - cub->ray.player_ypos;
	val = (1.0 / (cub->ray.xplane * cub->ray.player_ydir -
	cub->ray.player_xdir *
	cub->ray.yplane)) * (cub->ray.player_ydir * x - cub->ray.player_xdir * y);
	y = (1.0 / (cub->ray.xplane * cub->ray.player_ydir - cub->ray.player_xdir *
	cub->ray.yplane)) * (-1 * cub->ray.yplane * x + cub->ray.xplane * y);
	x = val;
	cub->spr.mid = (int)(((cub->map->width - 1) / 2) * (1 + x / y));
	cub->spr.depth = y;
}
