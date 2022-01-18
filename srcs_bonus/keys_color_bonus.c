/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:54 by athirion          #+#    #+#             */
/*   Updated: 2022/01/18 08:31:30 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <time.h>

void	ft_change_color(t_data *data)
{
	data->rand_color = 0;
	data->color = (data->color == 1) * 0 + (data->color == 0) * 1;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}

void	ft_rand_color(t_data *data)
{
	srand(time(NULL));
	data->rand_color = rand();
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	ft_draw_map(data);
	ft_init_menu(data);
}
