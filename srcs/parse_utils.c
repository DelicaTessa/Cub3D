/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 09:38:39 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 16:05:33 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_gnl_cub3d(t_map *info, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			index;
	int			rd;
	int			res;

	index = 0;
	rd = 1;
	if (line == NULL || info->fd < 0 || BUFFER_SIZE < 0)
		ft_error(5);
	*line = (char *)malloc(sizeof(char) * (1));
	if (*line == NULL)
		return (ft_error(10));
	while (rd != 0)
	{
		if (buff[0] == '\0')
			res = ft_read_line(buff, info->fd, &rd);
		if (res == -1)
			return (ft_error(10));
		if (!(ft_expand(line, index, ft_linelen(buff, '\n'))))
			return (ft_error(10));
		if (buff[0] != '\0')
			res = ft_make_line(line, buff, &index, &rd);
	}
	return (res);
}

int		ft_read_line(char *buff, int fd, int *rd)
{
	int		ret;

	ret = read(fd, buff, BUFFER_SIZE);
	if (ret <= 0)
		*rd = 0;
	return (ret);
}

int		ft_make_line(char **line, char *buff, int *index, int *rd)
{
	int	j;

	j = 0;
	while (buff[j] != '\n' && buff[j] != '\0')
	{
		(*line)[*index] = buff[j];
		*index = *index + 1;
		j++;
	}
	(*line)[*index] = '\0';
	if (buff[j] == '\n')
		*rd = 0;
	ft_remainder(buff, j);
	return (1);
}

void	ft_remainder(char *remainder, int j)
{
	int	k;

	k = 0;
	while (remainder[j] != '\0')
	{
		j++;
		remainder[k] = remainder[j];
		k++;
	}
	while (k < j)
	{
		remainder[k] = '\0';
		k++;
	}
}

void	ft_check_end_line(t_map *info, char c)
{
	if (ft_check_elems(info, '0') != 1)
	{
		if (c == '\0')
			info->error = info->error;
		else
			info->error = 0;
	}
}
