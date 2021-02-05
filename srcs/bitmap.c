/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:26:00 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:20:48 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_make_screenshot(t_cub3d *cub)
{
	int index;

	index = 0;
	if (cub->img_one.bits_per_pixel <= 8)
		ft_error(1);
	cub->fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cub->fd == -1)
		ft_error(2);
	cub->frame = 1;
	ft_cast_ray(cub);
	ft_get_sprites(cub, index);
	ft_bitmap_data(cub);
	ft_bitmap_file(cub);
}

void	ft_bitmap_data(t_cub3d *cub)
{
	int				index;
	unsigned char	header[54];
	int				size;
	int				res;

	index = 0;
	while (index < 54)
	{
		header[index] = (unsigned char)(0);
		index++;
	}
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	size = 54 + (cub->img_one.bits_per_pixel / 8) *
	cub->map->width * cub->map->height;
	ft_bitshifting(size, &(header[2]));
	ft_bitshifting(54, &(header[10]));
	ft_bitshifting(40, &(header[14]));
	ft_bitshifting(cub->map->width, &(header[18]));
	ft_bitshifting(cub->map->height, &(header[22]));
	ft_bitshifting(1, &(header[26]));
	ft_bitshifting(cub->img_one.bits_per_pixel, &(header[28]));
	res = write(cub->fd, header, 54);
	if (res == -1)
		ft_error(2);
}

void	ft_bitshifting(int bit, unsigned char *dest)
{
	dest[0] = (unsigned char)(bit);
	dest[1] = (unsigned char)(bit >> 8);
	dest[2] = (unsigned char)(bit >> 16);
	dest[3] = (unsigned char)(bit >> 24);
}

void	ft_bitmap_file(t_cub3d *cub)
{
	int size;
	int y;
	int addr;
	int res;

	size = (cub->img_one.bits_per_pixel / 8) * cub->map->width;
	y = cub->map->height - 1;
	while (y >= 0)
	{
		addr = y * (cub->img_one.line_bytes);
		res = write(cub->fd, &(cub->img_one.addr[addr]), size);
		if (res == -1)
			ft_error(2);
		y--;
	}
}
