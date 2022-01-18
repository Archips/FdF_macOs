/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:49:51 by athirion          #+#    #+#             */
/*   Updated: 2022/01/18 10:21:37 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_check_file(argv[1]);
		ft_init_struct(&data, argv[1]);
		if (!data.mlx_ptr)
		{
			ft_free_map(data.map, &data, data.height);
			ft_exit(6);
		}
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "-FDF-");
		ft_draw_map(&data);
		mlx_hook(data.win_ptr, 2, 1L << 1, (void *)ft_deal_key, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_exit(0);
	return (0);
}
