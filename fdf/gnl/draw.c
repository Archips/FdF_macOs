/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:48:03 by athirion          #+#    #+#             */
/*																			  */
/*   Updated: 2022/01/03 10:58:20 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*) dst = color;
}

void	deal_key(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	if (key == 1)
		data->y_offset -= 10;
	if (key == 13)	
		data->y_offset += 10;
	if (key == 0)
		data->x_offset -= 10;
	if (key == 2)
		data->x_offset += 10;
	if (key == 43)
		data->altitude -= 0.1;
	if (key == 47)
		data->altitude += 0.1;	
	if (key == 27)
		data->scale += 1;
	if (key == 24)
		data->scale -= 1;
	if (key == 126)
		data->alpha += 0.05;
	if (key == 125)
		data->alpha -= 0.05;
	if (key == 123)
		data->beta -= 0.05;
	if (key == 124)
		data->beta += 0.05;
	if (key == 41)
		data->gamma -= 0.05;
	if (key == 39)
		data->gamma += 0.05;
	if (key == 49)
	{
		data->iso = (data->iso == 1) * 0 + (data->iso == 0) * 1;
		data->para = (data->para == 1) * 0 + (data->para == 0) * 1;
	}
//	ft_bzero(data->img_ptr, sizeof(int) * WIN_WIDTH * WIN_HEIGHT);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
}

void	draw_line(t_data data, t_point begin, t_point end)
{
	t_point	delta;
	t_point pixel;
	int		pixels;
	delta.x = ft_abs(end.x - begin.x);
	delta.y = ft_abs(end.y - begin.y);
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	pixel.x = begin.x;
	pixel.y = begin.y;
	while (pixels)
	{
		my_mlx_pixel_put(&data, pixel.x, pixel.y, ft_get_color(begin, end, pixel, delta));
		if (begin.x < end.x)
			pixel.x += delta.x;
		else
			pixel.x -= delta.x;
		if (begin.y < end.y)
			pixel.y += delta.y;
		else
			pixel.y -= delta.y;
		pixels --;
	}
}

t_point	ft_init_point(int x, int y, t_data data)
{
	t_point p;
	char	*hex;

	p.x = x;
	p.y = y;
	p.z = ft_atoi(data.map[y][x]);
	if (ft_strchr(data.map[y][x], ','))
	{	
		hex = ft_strchr(data.map[y][x], ',');
		p.color = ft_atoi_hex(hex);
	}
	else
		p.color = ft_get_z_color(&data, p);
	return (p);
}

void	ft_draw(t_data data)
{
	int	x;
	int	y;
	t_point p1;
	t_point p2;

	y = -1;
	while (++ y < data.height)
	{
		x = -1;
		while (++ x < data.width)
		{
			if (x < data.width - 1)
			{	
				p1 = ft_init_point(x, y, data);
				p2 = ft_init_point(x + 1, y, data);
				draw_line(data, ft_project(&p1, data), ft_project(&p2, data));
			}
			if (y < data.height - 1)
			{
				p1 = ft_init_point(x, y, data);
				p2 = ft_init_point(x, y + 1, data);
				draw_line(data, ft_project(&p1, data), ft_project(&p2, data));
			}
		}
	}
}

int	ft_draw_map(t_data *data)
{
	// deal_key(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_length, &data->endian);
	ft_draw(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	//mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	return (0);
}
