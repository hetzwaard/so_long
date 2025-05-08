/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 13:24:23 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/08 16:12:41 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	int			fd;

	if (argc != 2)
		error_exit(0);
	map_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(0);
	map.map = map_read(open(argv[1], O_RDONLY), map_line(fd));
	map_init(&map);
	flood_fill(&map);
	map.mlx = mlx_init(map.x * 128, map.y * 128, "so_long", false);
	if (!map.mlx)
		error_exit(2);
	map_build(&map);
	map_depth(&map);
	mlx_key_hook(map.mlx, &move, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	ft_free_arr(map.map);
	return (0);
}
