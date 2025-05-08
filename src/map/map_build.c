/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_build.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 18:28:34 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/08 16:27:22 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_window(t_map *map, char c, int y, int x)
{
	int	i;

	x *= 96;
	y *= 96;
	i = -1;
	if (c == '1')
		i = mlx_image_to_window(map->mlx, map->wall, x, y);
	else if (c == '0' || c == 'P' || c == 'E' || c == 'C')
	{
		i = mlx_image_to_window(map->mlx, map->space, x, y);
		if (i < 0)
			return (i);
		if (c == 'C')
			i = mlx_image_to_window(map->mlx, map->collect, x, y);
		else if (c == 'P')
			i = mlx_image_to_window(map->mlx, map->player, x, y);
		else if (c == 'E')
			i = mlx_image_to_window(map->mlx, map->exit, x, y);
	}
	return (i);
}

void	map_image(t_map *map, mlx_image_t **image, const char *png)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png);
	if (!texture)
		error_mlx(map);
	*image = mlx_texture_to_image(map->mlx, texture);
	if (!*image)
		error_mlx(map);
}

void	map_build(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map_image(map, &map->player, "../textures/pete.png");
	map_image(map, &map->space, "../textures/space.png");
	map_image(map, &map->wall, "../textures/wall.png");
	map_image(map, &map->collect, "../textures/collect.png");
	map_image(map, &map->exit, "../textures/exit.png");
	while (map->y > y)
	{
		x = 0;
		while (map->x > x)
		{
			if (map_window(map, map->map[y][x], y, x) < 0)
				error_mlx(map);
			x++;
		}
		y++;
	}
}
