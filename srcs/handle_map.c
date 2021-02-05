/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:31:04 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:34:32 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_handle_map(t_map *info, char *cub)
{
	t_map copy;

	ft_get_grid(info, cub);
	ft_get_dir_pos(info);
	if (info->error == 0)
		ft_error(8);
	ft_copy_grid(info, &copy);
	ft_floodfill(info->copy, info->posx, info->posy);
	if (info->copy->error == 0)
		ft_error(9);
	info->spritecount = info->copy->spritecount;
}

void	ft_get_grid(t_map *info, char *cub)
{
	char	*line;
	int		i;

	i = close(info->fd);
	info->fd = open(cub, O_RDONLY);
	if (i == -1 || info->fd == -1)
		ft_error(2);
	while (info->start > 0)
	{
		ft_gnl_cub3d(info, &line);
		info->start--;
		free(line);
	}
	info->grid = (char **)malloc(sizeof(char *) * (info->rows + 1));
	if (info->grid == 0)
		ft_error(10);
	i = info->rows;
	info->rows = 0;
	while (info->rows < i)
	{
		ft_gnl_cub3d(info, &(info->grid[info->rows]));
		info->rows++;
	}
	info->grid[info->rows] = NULL;
}

void	ft_get_dir_pos(t_map *info)
{
	int i;
	int j;

	i = 0;
	if (info->rows < 1)
		info->error = 0;
	while (info->grid[i] != NULL)
	{
		j = 0;
		while (info->grid[i][j] != '\0')
		{
			ft_set_dir_pos(info, i, j);
			j++;
		}
		i++;
	}
	if (info->dir == '\0')
		info->error = 0;
}

void	ft_set_dir_pos(t_map *info, int i, int j)
{
	if (info->dir == '\0' && (info->grid[i][j] == 'N' ||
		info->grid[i][j] == 'S' || info->grid[i][j] == 'W' ||
		info->grid[i][j] == 'E'))
	{
		info->dir = info->grid[i][j];
		info->posy = i;
		info->posx = j;
	}
	else if (info->grid[i][j] != ' ' && info->grid[i][j] != '0'
	&& info->grid[i][j] != '1' && info->grid[i][j] != '2')
		info->error = 0;
}

void	ft_copy_grid(t_map *info, t_map *copy)
{
	copy = (t_map *)malloc(sizeof(t_map));
	if (copy == NULL)
		ft_error(10);
	info->copy = copy;
	*copy = ft_set_map_struct(copy);
	copy->grid = (char **)malloc(sizeof(char *) * (info->rows + 1));
	if (copy->grid == 0)
		ft_error(10);
	copy->grid[info->rows] = NULL;
	copy->rows = 0;
	while (info->grid[copy->rows] != NULL)
	{
		copy->col = ft_linelen(info->grid[copy->rows], '\0');
		copy->grid[copy->rows] = (char *)malloc(sizeof(char) * (copy->col + 1));
		if (copy->grid[copy->rows] == 0)
			ft_error(10);
		info->col = 0;
		while (info->col <= copy->col)
		{
			copy->grid[copy->rows][info->col] =
			info->grid[copy->rows][info->col];
			info->col++;
		}
		(copy->rows)++;
	}
}
