/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ray.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 15:47:31 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 16:15:46 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray(t_ray *ray, t_map *info)
{
	double fov;

	fov = 0.66;
	ray->player_xpos = (double)info->posx + 0.5;
	ray->player_ypos = (double)info->posy + 0.5;
	ft_init_dirs(ray, info);
	ft_init_planes(fov, ray);
	info->grid[info->posy][info->posx] = '0';
	info->zbuf = (double *)malloc(sizeof(double) * info->width);
	info->sprites = (t_sprite*)malloc(sizeof(t_sprite) * (info->spritecount));
	if (info->zbuf == NULL || info->sprites == NULL)
		ft_error(10);
}

void	ft_init_dirs(t_ray *ray, t_map *info)
{
	if (info->dir == 'E')
		ray->player_xdir = 1;
	else
		ray->player_xdir = 0;
	if (info->dir == 'S')
		ray->player_ydir = 1;
	else
		ray->player_ydir = 0;
	if (info->dir == 'W')
		ray->player_xdir = -1;
	else
		ray->player_xdir = ray->player_xdir;
	if (info->dir == 'N')
		ray->player_ydir = -1;
	else
		ray->player_ydir = ray->player_ydir;
}

void	ft_init_planes(double fov, t_ray *ray)
{
	if (ray->player_xdir == 1)
		ray->yplane = fov;
	else
		ray->yplane = 0;
	if (ray->player_ydir == 1)
		ray->xplane = (-1 * fov);
	else
		ray->xplane = 0;
	if (ray->player_xdir == -1)
		ray->yplane = (-1 * fov);
	else
		ray->yplane = ray->yplane;
	if (ray->player_ydir == -1)
		ray->xplane = fov;
	else
		ray->xplane = ray->xplane;
}

void	ft_get_text_img(t_cub3d *cub)
{
	cub->text.north = mlx_xpm_file_to_image(cub->mlx, cub->map->no,
	&(cub->text.ntext.width), &(cub->text.ntext.height));
	cub->text.south = mlx_xpm_file_to_image(cub->mlx, cub->map->so,
	&(cub->text.stext.width), &(cub->text.stext.height));
	cub->text.west = mlx_xpm_file_to_image(cub->mlx, cub->map->we,
	&(cub->text.wtext.width), &(cub->text.wtext.height));
	cub->text.east = mlx_xpm_file_to_image(cub->mlx, cub->map->ea,
	&(cub->text.etext.width), &(cub->text.etext.height));
	cub->text.sprite = mlx_xpm_file_to_image(cub->mlx, cub->map->spr,
	&(cub->text.sptext.width), &(cub->text.sptext.height));
	if (cub->text.north == NULL || cub->text.south == NULL ||
	cub->text.west == NULL || cub->text.east == NULL
	|| cub->text.sprite == NULL)
		ft_error(11);
}

void	ft_get_text_adr(t_cub3d *cub)
{
	cub->text.ntext.addr = mlx_get_data_addr(cub->text.north,
	&cub->text.ntext.bits_per_pixel, &cub->text.ntext.line_bytes,
	&cub->text.ntext.endian);
	cub->text.stext.addr = mlx_get_data_addr(cub->text.south,
	&cub->text.stext.bits_per_pixel, &cub->text.stext.line_bytes,
	&cub->text.stext.endian);
	cub->text.wtext.addr = mlx_get_data_addr(cub->text.west,
	&cub->text.wtext.bits_per_pixel, &cub->text.wtext.line_bytes,
	&cub->text.wtext.endian);
	cub->text.etext.addr = mlx_get_data_addr(cub->text.east,
	&cub->text.etext.bits_per_pixel, &cub->text.etext.line_bytes,
	&cub->text.etext.endian);
	cub->text.sptext.addr = mlx_get_data_addr(cub->text.sprite,
	&cub->text.sptext.bits_per_pixel, &cub->text.sptext.line_bytes,
	&cub->text.sptext.endian);
}
