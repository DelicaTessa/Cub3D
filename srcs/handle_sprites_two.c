/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_sprites_two.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:35:18 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:39:43 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_spr_vals(t_cub3d *cub)
{
	double	ratio;
	double	size;

	ratio = (double)(cub->text.sptext.width) / (cub->text.sptext.height);
	if (cub->map->height <= cub->map->width)
		size = abs((int)(cub->map->height / (cub->spr.depth)));
	else
		size = abs((int)(cub->map->width / (cub->spr.depth)));
	ft_set_spr_vals(cub, ratio, size);
}

void	ft_set_spr_vals(t_cub3d *cub, double ratio, double size)
{
	if (ratio <= 1)
		cub->spr.height = size;
	else
		cub->spr.height = (size / ratio);
	if (cub->spr.height < 1)
		cub->spr.height = 1;
	cub->spr.ystart = -cub->spr.height / 2 + (cub->map->height - 1) / 2;
	if (cub->spr.ystart < 0)
		cub->spr.ystart = 0;
	cub->spr.yend = cub->spr.height / 2 + (cub->map->height - 1) / 2;
	if (cub->spr.yend > cub->map->height)
		cub->spr.yend = cub->map->height;
	if (ratio >= 1)
		cub->spr.width = size;
	else
		cub->spr.width = (size * ratio);
	if (cub->spr.width < 1)
		cub->spr.width = 1;
	cub->spr.xstart = -cub->spr.width / 2 + cub->spr.mid;
	if (cub->spr.xstart < 0)
		cub->spr.xstart = 0;
	cub->spr.xend = cub->spr.width / 2 + cub->spr.mid;
	if (cub->spr.xend > cub->map->width)
		cub->spr.xend = cub->map->width;
}

void	ft_load_sprite(t_cub3d *cub)
{
	int		cam_x;
	int		y;

	cam_x = cub->spr.xstart;
	while (cam_x < cub->spr.xend)
	{
		cub->spr.tx = (int)(256 * (cam_x - (-cub->spr.width / 2 +
		cub->spr.mid)) * cub->text.sptext.width / cub->spr.width) / 256;
		if (cub->spr.depth > 0 && cub->spr.depth < cub->map->zbuf[cam_x]
			&& cam_x >= 0 && cam_x < cub->map->width)
		{
			y = cub->spr.ystart;
			while (y < cub->spr.yend)
			{
				ft_load_spr_helper(cub, y);
				if (cub->spr.color != 0x00000000)
					ft_put_pixel_img(cub->spr.spr_img, cam_x, y,
					cub->spr.color);
				y++;
			}
		}
		cam_x++;
	}
}

void	ft_load_spr_helper(t_cub3d *cub, int y)
{
	cub->spr.ty = (256 * (y - (int)(-cub->spr.height / 2
	+ (cub->map->height - 1) / 2)) *
	cub->text.sptext.height / cub->spr.height) / 256;
	cub->spr.color = ft_get_sprite_color(cub, cub->spr.tx,
	cub->spr.ty);
}

int		ft_get_sprite_color(t_cub3d *cub, int width, int height)
{
	t_img	texture;
	char	*color;

	if (width >= cub->text.sptext.width)
		width = cub->text.sptext.width - 1;
	if (width <= 0)
		width = 0;
	if (height >= cub->text.sptext.height)
		height = cub->text.sptext.height - 1;
	if (height <= 0)
		height = 0;
	texture = cub->text.sptext;
	color = texture.addr + (height * texture.line_bytes +
	width * (texture.bits_per_pixel / 8));
	return (*(unsigned int*)color);
}
