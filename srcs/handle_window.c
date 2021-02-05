/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_window.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:38:06 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 20:00:00 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	ft_start_window(t_map *info)
{
	t_cub3d	cub;

	cub.map = info;
	cub.mlx = mlx_init();
	if (cub.mlx == 0)
		ft_error(11);
	ft_get_screen_size(cub.map, cub.mlx);
	if (info->bitmap != 1)
	{
		cub.win = mlx_new_window(cub.mlx, cub.map->width,
		cub.map->height, "Cub3D");
		if (cub.win == 0)
			ft_error(11);
	}
	ft_get_img_adr(cub.map, &(cub.img_one), &(cub.img_two), cub.mlx);
	cub.frame = -1;
	return (cub);
}

void	ft_get_screen_size(t_map *info, void *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (info->bitmap != 1)
	{
		mlx_get_screen_size(mlx, &x, &y);
		if (x < info->width)
			info->width = x;
		if (y < info->height)
			info->height = y;
	}
	if (info->bitmap == 1)
	{
		if (info->width > 16384)
			info->width = 16384;
		if (info->height > 16384)
			info->height = 16384;
	}
}

void	ft_get_img_adr(t_map *info, t_img *img_one, t_img *img_two, void *mlx)
{
	img_one->cont = mlx_new_image(mlx, info->width, info->height);
	img_one->addr = mlx_get_data_addr(img_one->cont, &img_one->bits_per_pixel,
	&img_one->line_bytes, &img_one->endian);
	img_two->cont = mlx_new_image(mlx, info->width, info->height);
	img_two->addr = mlx_get_data_addr(img_two->cont, &img_two->bits_per_pixel,
	&img_two->line_bytes, &img_two->endian);
}

void	ft_put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		pxl_size;

	pxl_size = (img->bits_per_pixel / 8);
	dst = img->addr + (y * img->line_bytes + x * pxl_size);
	if (color >= 0x00000000 && (unsigned int)color <= 0x00FFFFFF)
		*(unsigned int*)dst = color;
	else
		*(unsigned int*)dst = 0x00000000;
}

int		ft_render_window(t_cub3d *cub)
{
	int index;

	index = 0;
	ft_cast_ray(cub);
	ft_get_sprites(cub, index);
	cub->frame++;
	if (cub->frame % 2 == 0)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img_one.cont, 0, 0);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img_two.cont, 0, 0);
	return (0);
}
