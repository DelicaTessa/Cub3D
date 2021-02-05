/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 10:19:16 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:25:41 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_start_cub3d(t_cub3d *cub, t_map *info)
{
	ft_init_ray(&(cub->ray), cub->map);
	ft_count_sprites(cub);
	ft_set_move_struct(cub);
	ft_get_text_img(cub);
	ft_get_text_adr(cub);
	if (info->bitmap == 0)
	{
		ft_hooks(cub);
		mlx_loop_hook(cub->mlx, &ft_update_mlx, cub);
		mlx_loop(cub->mlx);
	}
	else if (info->bitmap == 1)
		ft_make_screenshot(cub);
}

void	ft_is_screenshot(char *arg, t_map *info)
{
	int compare;

	compare = ft_strncmp("--save", arg, 7);
	if (compare == 0)
		info->bitmap = 1;
}

void	ft_argcheck(int argc, char *mapfile, t_map *info)
{
	if (argc < 2)
		ft_error(3);
	else if (argc > 2 && info->bitmap != 1)
		ft_error(4);
	else if (info->fd == -1)
		ft_error(5);
	else if (ft_strncmp(mapfile + ft_strlen(mapfile) - 4, ".cub", 5))
		ft_error(6);
}

int		ft_update_mlx(t_cub3d *cub)
{
	if (cub->move.ver != 0 || cub->move.hor != 0)
		ft_set_move_vals_one(cub);
	if (cub->move.rotdir != 0)
		ft_set_rot_vals(cub);
	ft_render_window(cub);
	return (0);
}
