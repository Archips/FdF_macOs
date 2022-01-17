/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:57:42 by athirion          #+#    #+#             */
/*   Updated: 2022/01/17 16:03:46 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_percent(int min, int max, int current)
{
	double	position;
	double	distance;

	position = current - min;
	distance = max - min;
	if (distance == 0.0)
		return (1.0);
	return (position / distance);
}

int	ft_get_intensity(int min, int max, double percent)
{
	return ((int)((1 - percent) * min + percent * max));
}

int	ft_get_z_color(t_data *data, t_point p)
{
	double	percent;

	percent = ft_percent(data->min_map, data->max_map, p.z);
	if (percent < 0.2)
		return ((data->color == 1) * COLOR_1 + (data->color == 0) * NB_1);
	else if (percent < 0.4)
		return ((data->color == 1) * COLOR_2 + (data->color == 0) * NB_2);
	else if (percent < 0.6)
		return ((data->color == 1) * COLOR_3 + (data->color == 0) * NB_3);
	else if (percent < 0.8)
		return ((data->color == 1) * COLOR_4 + (data->color == 0) * NB_4);
	else
		return ((data->color == 1) * COLOR_5 + (data->color == 0) * NB_5);
}

int	ft_get_color(t_point p1, t_point p2, t_point current, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (current.color == p2.color)
		return (current.color);
	if (delta.x > delta.y)
		percent = ft_percent(p1.x, p2.x, current.x);
	else
		percent = ft_percent(p1.y, p2.y, current.y);
	red = ft_get_intensity((p1.color >> 16) & 0xFF,
			(p2.color >> 16) & 0xFF, percent);
	green = ft_get_intensity((p1.color >> 8) & 0xFF,
			(p2.color >> 8) & 0xFF, percent);
	blue = ft_get_intensity((p1.color & 0xFF), p2.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
