/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:57:42 by athirion          #+#    #+#             */
/*   Updated: 2022/01/10 14:58:42 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		return (COLOR_1);
	else if (percent < 0.4)
		return (COLOR_2);
	else if (percent < 0.6)
		return (COLOR_3);
	else if (percent < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
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
