/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:49:51 by athirion          #+#    #+#             */
/*   Updated: 2022/01/15 15:51:23 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		printf("#1\n");
		ft_check_file(argv[1]);
		printf("#2\n");
		ft_init_struct(&data, argv[1]);
		printf("#3\n");
		ft_draw_map(&data);
		printf("#4\n");
		ft_init_menu(&data);
		printf("#5\n");
		mlx_loop_hook(data.mlx_ptr, handle_no_event, &data);
		mlx_hook(data.win_ptr, 2, 1L << 1, (void *)ft_deal_key, &data);
		mlx_hook(data.win_ptr, 17, 1L << 17, ft_close, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
//		ft_putendl_fd(ERR_0, 2);
//		exit(1);
		ft_exit(1);
	}
	return (0);
}
