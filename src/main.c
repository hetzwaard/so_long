/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 13:24:23 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/10 02:49:00 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long(char *map_ber)
{
	t_map	map;
	int		fd;

	fd = open(map_ber, O_RDONLY);
	if (fd < 0)
		error_exit(0, &map);
	map.map = map_read(open(map_ber, O_RDONLY), map_line(fd));
	if (!map.map)
		error_exit(1, &map);
	map_name(map_ber);
	map_init(&map);
	flood_fill(&map);
	map.mlx = mlx_init(map.x * 96, map.y * 96, "so_long", false);
	if (!map.mlx)
		error_exit(2, &map);
	map_build(&map);
	map_depth(&map);
	mlx_key_hook(map.mlx, &move, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	ft_free_arr(map.map);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(2, "Error\nIncorrect input!\n", 23), 0);
	so_long(argv[1]);
	return (0);
}
