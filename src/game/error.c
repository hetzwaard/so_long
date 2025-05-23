/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:03:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/10 02:49:23 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	error_fd(int i, int fd)
{
	if (i == 1)
		ft_putstr_fd("Error\nInvalid map!", STDERR_FILENO);
	close(fd);
	write(1, "\n", STDERR_FILENO);
	exit (1);
}

void	error_exit(int i, t_map *map)
{
	if (i == 0)
		ft_putstr_fd("Error\nIncorrect input!", STDERR_FILENO);
	else if (i == 1)
		ft_putstr_fd("Error\nInvalid map!", STDERR_FILENO);
	else if (i == 2)
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	write(1, "\n", STDERR_FILENO);
	if (map->map)
		ft_free_arr(map->map);
	map->map = NULL;
	exit(1);
}

void	error_mlx(t_map *map)
{
	ft_free_arr(map->map);
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	write(1, "\n", STDERR_FILENO);
	exit(1);
}
