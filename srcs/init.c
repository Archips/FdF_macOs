/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:26:40 by athirion          #+#    #+#             */
/*   Updated: 2022/01/18 08:49:16 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_struct(t_data *data, char *file)
{
	data->width = ft_get_width(file);
	data->height = ft_get_height(file, data->width);
	data->x_offset = WIDTH / 2;
	data->y_offset = (HEIGHT + data->height * data->scale) / 2;
	data->altitude = 0.40;
	if (data->height > 400)
	{
		data->scale = 1.6;
		data->altitude = 1;
	}
	else
		data->scale = ft_min(WIDTH / data->width / 2,
				HEIGHT / data->height / 2);
	data->iso = 1;
	data->color = 1;
	data->min_map = 2147483647;
	data->max_map = -2147483648;
	data->map = ft_read(file, data);
	data->name = file;
	data->mlx_ptr = mlx_init();
}

t_point	ft_init_point(int x, int y, t_data *data)
{
	t_point	p;
	char	*hex;

	p.x = x;
	p.y = y;
	p.z = ft_atoi(data->map[y][x]);
	if (ft_strchr(data->map[y][x], ','))
	{
		hex = ft_strchr(data->map[y][x], ',');
		p.color = ft_atoi_hex(hex);
	}
	else
		p.color = ft_get_z_color(data, p);
	return (p);
}
