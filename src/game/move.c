/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:37:28 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/08 16:27:55 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	set_space(t_map *map, int x, int y)
{
	x /= 96;
	y /= 96;
	map->map[y][x] = '0';
}

static int	check_move(t_map *map, char move, int x, int y)
{
	x += map->player->instances[0].x / 96;
	y += map->player->instances[0].y / 96;
	if (map->map[y][x] == move)
		return (1);
	return (0);
}

static void	collect_exit(t_map *map)
{
	int	i;

	if (map->c_count == 0)
	{
		if (check_move(map, 'E', 0, 0))
		{
			map->player->instances[0].enabled = false;
			mlx_close_window(map->mlx);
		}
	}
	else if (check_move(map, 'C', 0, 0))
	{
		i = 0;
		while (map->player->instances[0].x != map->collect->instances[i].x
			|| map->player->instances[0].y != map->collect->instances[i].y)
			i++;
		map->collect->instances[i].enabled = false;
		set_space(map, map->collect->instances[i].x,
			map->collect->instances[i].y);
		map->c_count--;
	}
}

static void	move_direction(t_map *map, int dx, int dy)
{
	if (check_move(map, '1', dx, dy))
		return ;
	map->player->instances[0].x += dx * 96;
	map->player->instances[0].y += dy * 96;
	map->move++;
	ft_printf("%d\n", map->move);
	collect_exit(map);
}

void	move(mlx_key_data_t key, void *param)
{
	t_map	*map;

	map = param;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
			move_direction(map, 0, -1);
		else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
			move_direction(map, 0, 1);
		else if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
			move_direction(map, 1, 0);
		else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
			move_direction(map, -1, 0);
		else if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(map->mlx);
	}
}
