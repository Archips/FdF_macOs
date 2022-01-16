/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:10:38 by athirion          #+#    #+#             */
/*   Updated: 2022/01/16 18:11:56 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_offset(int key, t_data *data)
{
	if (key == 1)
		data->y_offset += 10;
	else if (key == 13)
		data->y_offset -= 10;
	else if (key == 0)
		data->x_offset -= 10;
	else if (key == 2)
		data->x_offset += 10;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}

void	ft_altitude(int key, t_data *data)
{
	if (key == 43)
		data->altitude -= 0.1;
	else if (key == 47)
		data->altitude += 0.1;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}

void	ft_scale(int key, t_data *data)
{
	if (key == 27)
		data->scale -= 1;
	if (key == 24)
		data->scale += 1;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}

void	ft_rotate(int key, t_data *data)
{
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
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}

void	ft_change_view(t_data *data)
{
	data->iso = (data->iso == 1) * 0 + (data->iso == 0) * 1;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}
