/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 13:24:23 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/07 06:10:12 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(int i)
{
	if (i == 0)
		ft_putstr_fd("ERROR: Incorrect input!", STDERR_FILENO);
	else if (i == 1)
		ft_putstr_fd("ERROR: Invalid map!", STDERR_FILENO);
	else if (i == 2)
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	write(1, "\n", STDERR_FILENO);
	exit(1);
}

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
	return (0);
}
