/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screencolor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 15:51:27 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 15:56:08 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_wall_values(t_cub3d *cub, int x, int so_ea)
{
	if (cub->ray.dir == 0)
		cub->ray.len = ((cub->ray.ray_xpos - cub->ray.player_xpos + so_ea)
		/ cub->ray.ray_xdir);
	else
		cub->ray.len = ((cub->ray.ray_ypos - cub->ray.player_ypos + so_ea)
		/ cub->ray.ray_ydir);
	cub->map->zbuf[x] = cub->ray.len;
}

int		ft_get_wall_values(t_cub3d *cub, int x)
{
	int		so_ea;
	int		wall_height;
	int		start;
	int		end;

	if ((cub->ray.dir == 0 && cub->ray.stepx == -1) ||
		(cub->ray.dir == 1 && cub->ray.stepy == -1))
		so_ea = 1;
	else
		so_ea = 0;
	ft_set_wall_values(cub, x, so_ea);
	wall_height = (int)(cub->map->height / cub->ray.len);
	start = cub->map->height / 2 - wall_height / 2;
	if (start < 0)
		start = 0;
	end = cub->map->height / 2 + wall_height / 2;
	if (end >= cub->map->height)
		end = cub->map->height;
	if (cub->frame % 2 == 1)
		cub->curr_frame = &(cub->img_one);
	else
		cub->curr_frame = &(cub->img_two);
	ft_render_wall(cub, start, end, x);
	return (x);
}

void	ft_render_wall(t_cub3d *cub, int start, int end, int x)
{
	int		color;
	int		y;

	color = (cub->map->cb + cub->map->cg * 256 + cub->map->cr * 256 * 256);
	y = 0;
	while (y < start && y < ((cub->map->height - 1) / 2))
	{
		ft_put_pixel_img(cub->curr_frame, x, y, color);
		y++;
	}
	while (y < end && y < cub->map->height)
	{
		color = ft_get_text_color(cub, start, end, y);
		ft_put_pixel_img(cub->curr_frame, x, y, color);
		y++;
	}
	color = (cub->map->fb + cub->map->fg * 256 + cub->map->fr * 256 * 256);
	while (y < cub->map->height)
	{
		ft_put_pixel_img(cub->curr_frame, x, y, color);
		y++;
	}
}

double	ft_set_text_color(t_cub3d *cub, double x)
{
	if (cub->ray.dir == 1)
		x = (double)(cub->ray.player_xpos + cub->ray.len * cub->ray.ray_xdir);
	else
		x = (double)(cub->ray.player_ypos + cub->ray.len * cub->ray.ray_ydir);
	return (x);
}

int		ft_get_text_color(t_cub3d *cub, int start, int end, double y)
{
	t_img	tex;
	char	*tex_col;
	double	x;

	tex = cub->text.wtext;
	x = 0.0;
	if (cub->ray.dir == 1 && cub->ray.ray_ydir < 0)
		tex = cub->text.stext;
	else if (cub->ray.dir == 1 && cub->ray.ray_ydir >= 0)
		tex = cub->text.ntext;
	else if (cub->ray.dir == 0 && cub->ray.ray_xdir < 0)
		tex = cub->text.etext;
	x = ft_set_text_color(cub, x);
	x = (double)((x - floor(x)) * tex.width);
	if ((cub->ray.dir == 0 && cub->ray.ray_xdir < 0) ||
	(cub->ray.dir == 1 && cub->ray.ray_ydir >= 0))
		x = tex.width - x;
	y = (((y - start) / (double)(end - start)) * 2 - 1)
	* (tex.height / 2);
	if (cub->ray.len <= 1)
		y = y * cub->ray.len;
	y = y + (tex.height / 2);
	tex_col = tex.addr + ((int)y * tex.line_bytes +
	(int)x * (tex.bits_per_pixel / 8));
	return (*(unsigned int*)tex_col);
}
