/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 04:26:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/07 04:27:52 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_map_name(char *str)
{
	while (*str != '.')
	{
		str++;
		if (!*str)
			error_exit(0);
	}
	if (ft_strcmp(str, ".ber"))
		error_exit(0);
}