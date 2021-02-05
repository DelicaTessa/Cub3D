/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 20:20:35 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 20:20:39 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map		info;
	t_cub3d		cub;

	info = ft_set_map_struct(&info);
	info.fd = open(argv[1], O_RDONLY);
	if (argc == 3)
		ft_is_screenshot(argv[2], &info);
	ft_argcheck(argc, argv[1], &info);
	ft_parse_map(&info);
	ft_handle_map(&info, argv[1]);
	cub = ft_start_window(&info);
	ft_start_cub3d(&cub, &info);
	ft_exit();
	return (0);
}
