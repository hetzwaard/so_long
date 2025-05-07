/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 18:01:47 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/07 18:01:47 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**find_next(char **map_d, int x, int y)
{
	if (map_d[y][x] != '1')
	{
		if (map_d[y][x] != '1')
			map_d[y][x] = '1';
		else
			return (map_d);
		find_next(map_d, x + 1, y);
		find_next(map_d, x - 1, y);
		find_next(map_d, x, y + 1);
		find_next(map_d, x, y - 1);
	}
	return (map_d);
}

static int	find_wall(char **map_d)
{
	int	x;
	int	y;

	y = 0;
	while (map_d[y])
	{
		x = 0;
		while (map_d[y][x])
		{
			if (map_d[y][x] != '0' && map_d[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	find_player(char **map_d, int *x, int *y)
{
	*y = 0;
	while (map_d[*y])
	{
		*x = 0;
		while (map_d[*y][*x])
		{
			if (map_d[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	flood_fill(t_map *map)
{
	char	**map_d;
	int		error;
	int		x;
	int		y;

	map_d = map_dup(map);
	find_player(map_d, &x, &y);
	error = find_wall(find_next(map_d, x, y));
	ft_free_arr(map_d);
	if (!error)
		error_exit(1);
}