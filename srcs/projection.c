/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:58:12 by athirion          #+#    #+#             */
/*   Updated: 2022/01/16 17:47:03 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iso(t_point *point)
{
	int	temp_x;
	int	temp_y;

	temp_x = point->x;
	temp_y = point->y;
	point->x = ((temp_x - temp_y) * cos(30 * (M_PI / 180)));
	point->y = -point->z + ((temp_x + temp_y) * sin(30 * (M_PI / 180)));
}

void	ft_rotate_x(t_point *point, t_data *data)
{
	int	temp_y;

	temp_y = point->y;
	point->y = temp_y * cos(data->alpha) + point->z * sin(data->alpha);
	point->z = -temp_y * sin(data->alpha) + point->z * cos(data->alpha);
}

void	ft_rotate_y(t_point *point, t_data *data)
{
	int	temp_x;

	temp_x = point->x;
	point->x = temp_x * cos(data->beta) + point->z * sin(data->beta);
	point->z = -temp_x * sin(data->beta) + point->z * cos(data->beta);
}

void	ft_rotate_z(t_point *point, t_data *data)
{
	int	temp_x;
	int	temp_y;

	temp_x = point->x;
	temp_y = point->y;
	point->x = temp_x * cos(data->gamma) - temp_y * sin(data->gamma);
	point->y = temp_x * sin(data->gamma) + temp_y * cos(data->gamma);
}

t_point	ft_project(t_point *p, t_data *data)
{
	p->x = p->x * data->scale;
	p->y = p->y * data->scale;
	p->z = p->z * ((data->scale * data->altitude) / 2);
	p->x -= (data->width * data->scale) / 2;
	p->y -= (data->height * data->scale) / 2;
	ft_rotate_x(p, data);
	ft_rotate_y(p, data);
	ft_rotate_z(p, data);
	if (data->iso == 1)
		ft_iso(p);
	p->x = p->x + data->x_offset;
	p->y = p->y + data->y_offset;
	return (*p);
}
