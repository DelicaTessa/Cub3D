/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_two.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:32:53 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 16:02:44 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_path(t_map *info, char element, char *line, int *i)
{
	int		fd;
	int		j;
	int		k;
	char	*path;

	k = 0;
	fd = open(&(line[*i]), O_RDONLY);
	if (fd == -1)
		ft_error(7);
	else
		close(fd);
	j = ft_linelen(&(line[*i]), '\0');
	path = (char *)malloc(sizeof(char) * (j + 1));
	if (path == 0)
		ft_error(10);
	while (line[*i] != '\0')
	{
		path[k] = line[*i];
		k++;
		(*i)++;
	}
	path[k] = '\0';
	ft_get_texture(info, element, path);
}

void	ft_get_texture(t_map *info, char element, char *path)
{
	if (element == 'N')
		info->no = path;
	else if (element == 'S')
		info->so = path;
	else if (element == 'W')
		info->we = path;
	else if (element == 'E')
		info->ea = path;
	else if (element == 's')
		info->spr = path;
}

void	ft_get_color(t_map *info, char element, char *line, int *i)
{
	while ((line[*i] >= '0' && line[*i] <= '9'))
	{
		info->col = 0;
		while ((line[*i] >= '0') && (line[*i] <= '9'))
		{
			info->col = (line[*i] - '0') + (info->col * 10);
			(*i)++;
			if (info->col > 255)
				info->error = 0;
		}
		ft_set_rbg(info, element);
		if ((element == 'c' && info->cb != -1) ||
			(element == 'f' && info->fb != -1))
			break ;
		while ((line[*i] == ',' && line[*i - 1] >= '0' && \
		line[*i - 1] <= '9') || line[*i] == ' ')
			(*i)++;
	}
	if ((element == 'f' && info->fb == -1) ||
		(element == 'c' && info->cb == -1))
		ft_error(7);
}

void	ft_set_rbg(t_map *info, char element)
{
	if (element == 'f' && info->fb == -1 && info->fg != -1)
		info->fb = info->col;
	if (element == 'f' && info->fg == -1 && info->fr != -1)
		info->fg = info->col;
	if (element == 'f' && info->fr == -1)
		info->fr = info->col;
	if (element == 'c' && info->cb == -1 && info->cg != -1)
		info->cb = info->col;
	if (element == 'c' && info->cg == -1 && info->cr != -1)
		info->cg = info->col;
	if (element == 'c' && info->cr == -1)
		info->cr = info->col;
}

void	ft_get_resolution(t_map *info, char *line, int *i)
{
	while ((line[*i] >= '0') && (line[*i] <= '9'))
	{
		if (info->width == -1)
			info->width = 0;
		info->width = (line[*i] - '0') + (info->width * 10);
		(*i)++;
	}
	while (line[*i] == ' ')
		(*i)++;
	while ((line[*i] >= '0') && (line[*i] <= '9'))
	{
		if (info->height == -1)
			info->height = 0;
		info->height = (line[*i] - '0') + (info->height * 10);
		(*i)++;
	}
	if ((info->width < 1) || (info->height < 1))
		info->error = 0;
}
