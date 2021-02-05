/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_one.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:32:29 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/05 11:06:16 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_map(t_map *info)
{
	int		ret;
	int		index;
	char	*line;
	char	element;

	ret = 1;
	while (ret != 0 && info->error != 0)
	{
		ret = ft_gnl_cub3d(info, &line);
		index = 0;
		ft_set_map_vals(info);
		while (line[index] != '\0' && ft_check_elems(info, '0') == 1)
		{
			ft_skipspace(line, &index);
			element = ft_get_elems(line, &index);
			ft_handle_elems(info, element, line, &index);
			ft_skipspace(line, &index);
			ft_check_end_line(info, line[index]);
		}
	}
	free(line);
	if (info->error == 0 || ft_check_elems(info, '0') == 1)
		ft_error(7);
}

int		ft_check_elems(t_map *info, char flag)
{
	int ret;

	ret = 0;
	if ((flag == '0' || flag == 'r') && info->width == -1)
		ret = 1;
	if ((flag == '0' || flag == 'N') && info->no == NULL)
		ret = 1;
	if ((flag == '0' || flag == 'S') && info->so == NULL)
		ret = 1;
	if ((flag == '0' || flag == 'W') && info->we == NULL)
		ret = 1;
	if ((flag == '0' || flag == 'E') && info->ea == NULL)
		ret = 1;
	if ((flag == '0' || flag == 's') && info->spr == NULL)
		ret = 1;
	if ((flag == '0' || flag == 'f') && info->fr == -1)
		ret = 1;
	if ((flag == '0' || flag == 'c') && info->cr == -1)
		ret = 1;
	return (ret);
}

char	ft_get_elems(char *line, int *i)
{
	if (&(line[*i]) == ft_strstr(&(line[*i]), "R "))
		return ('r');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "NO "))
		return ('N');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "SO "))
		return ('S');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "WE "))
		return ('W');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "EA "))
		return ('E');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "S "))
		return ('s');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "F "))
		return ('f');
	else if (&(line[*i]) == ft_strstr(&(line[*i]), "C "))
		return ('c');
	else
		return ('0');
}

void	ft_handle_elems(t_map *info, char element, char *line, int *i)
{
	if (element == '0' || (ft_check_elems(info, element)) == 0)
	{
		info->error = 0;
		ft_error(7) ;
	}
	while (line[*i] != ' ')
		(*i)++;
	(*i)++;
	while (line[*i] == ' ' && (element == 'r' || element == 'f' ||
		element == 'c'))
		(*i)++;
	if (element == 'N' || element == 'S' || element == 'W' ||
		element == 'E' || element == 's')
		ft_get_path(info, element, line, i);
	else if (element == 'f' || element == 'c')
		ft_get_color(info, element, line, i);
	else if (element == 'r')
		ft_get_resolution(info, line, i);
}

void	ft_set_map_vals(t_map *info)
{
	if (ft_check_elems(info, '0') == 1)
	{
		info->start = info->start + 1;
		info->rows = info->rows;
	}
	else
	{
		info->start = info->start;
		info->rows = info->rows + 1;
	}
}
