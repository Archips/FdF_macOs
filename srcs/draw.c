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

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_line(t_data *data, t_point begin, t_point end)
{
	t_point	d;
	t_point	p;
	int		pixels;

	d.x = ft_abs(end.x - begin.x);
	d.y = ft_abs(end.y - begin.y);
	pixels = sqrt((d.x * d.x) + (d.y * d.y));
	d.x /= pixels;
	d.y /= pixels;
	p.x = begin.x;
	p.y = begin.y;
	while (pixels)
	{
		if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
			my_mlx_pixel_put(data, p.x, p.y, ft_get_color(begin, end, p, d));
		if (begin.x < end.x)
			p.x += d.x;
		else
			p.x -= d.x;
		if (begin.y < end.y)
			p.y += d.y;
		else
			p.y -= d.y;
		pixels --;
	}
}

void	ft_draw(t_data *data)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = -1;
	while (++ y < data->height)
	{
		x = -1;
		while (++ x < data->width)
		{
			if (x < data->width - 1)
			{	
				p1 = ft_init_point(x, y, data);
				p2 = ft_init_point(x + 1, y, data);
				draw_line(data, ft_project(&p1, data), ft_project(&p2, data));
			}
			if (y < data->height - 1)
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr,
			&data->bpp, &data->line_length, &data->endian);
	ft_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
