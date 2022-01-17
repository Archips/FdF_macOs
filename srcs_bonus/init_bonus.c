/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:26:40 by athirion          #+#    #+#             */
/*   Updated: 2022/01/17 22:43:17 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_struct(t_data *data, char *file)
{
	data->width = ft_get_width(file);
	data->height = ft_get_height(file, data->width);
	data->x_offset = WIDTH / 2;
	data->y_offset = (HEIGHT + data->height * data->scale) / 2;
	data->altitude = 0.1;
	if (data->height > 400)
		data->scale = 1.6;
	else
		data->scale = ft_min(WIDTH / data->width / 2,
				HEIGHT / data->height / 2);
	data->iso = 1;
	data->color = 1;
	data->rand_color = 0;
	data->min_map = 2147483647;
	data->max_map = -2147483648;
	data->map = ft_read(file, data);
	data->mlx_ptr = mlx_init();
	data->name = file;
}

void	ft_reset_map(t_data *data)
{
	data->scale = 1;
	data->x_offset = WIDTH / 2;
	data->y_offset = (HEIGHT + data->height * data->scale) / 2;
	data->altitude = 0.1;
	data->scale = ft_min(WIDTH / data->width / 2, HEIGHT / data->height / 2);
	data->iso = 1;
	data->color = 1;
	data->rand_color = 0;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
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

void	ft_init_menu(t_data *data)
{
	data->map_name = ft_get_name(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 10,
		0xFFFFFF, data->map_name);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30,
		0xFFFFFF, "move : [w s a d]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 50,
		0xFFFFFF, "altitude : [< >]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 70,
		0xFFFFFF, "zoom : [- +]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 90,
		0xFFFFFF, "rotation x : [up / down arrow]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 110,
		0xFFFFFF, "rotation y : [l / r arrow]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 130,
		0xFFFFFF, "rotation z : [; ']");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 150,
		0xFFFFFF, "change view : [space]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 170,
		0xFFFFFF, "change color : [c v]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 190,
		0xFFFFFF, "reset map : [r]");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 210,
		0xFFFFFF, "exit : [esc]");
	free(data->map_name);
}
