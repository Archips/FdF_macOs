/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:49:51 by athirion          #+#    #+#             */
/*   Updated: 2022/01/14 10:40:37 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_struct(t_data *data, char *file)
{
	data->width = ft_get_width(file);
	data->height = ft_get_height(file);
	data->x_offset = WIN_WIDTH / 2;
	data->y_offset = (WIN_HEIGHT + (data->height * data->scale)) / 2;
	data->scale = ft_min(WIN_WIDTH / data->width / 2, WIN_HEIGHT / data->height / 2);
	data->altitude = 0.1;
	data->iso = 1;
	data->para = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->endian = 0;
	data->min_map = 2147483647;
	data->max_map = -2147483648;
}

int	handle_no_event(void *data)
{
	(void)data;
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int ft_close(t_data *data)
{
	int	i;
	int	j;

	j = data->height - 1;;
	while (j >= 0)
	{
		i = data->width - 1;
		while (i >= 0)
		{
			free(data->map[j][i]);
			i --;
		}
		free(data->map[j]);
		j --;
	}
	free(data->map);
	data->map = NULL;
	ft_bzero(data->addr, WIN_WIDTH * WIN_HEIGHT * (data->bpp / 8));
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
//	free(data);
	while (1);
	exit(0);
}

char	*ft_title(char *map_name)
{
	char	*map;

	map = ft_strjoin("fdf - ", ft_strtrim(map_name, "test_map/.fdf"));
	return (map);
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_data	data;

//	data = malloc(sizeof(t_data));
	ft_init_struct(&data, argv[1]);
	data.map = ft_read(argv[1], &data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, ft_title(argv[1]));
	
	ft_draw_map(&data);
//	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
//	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_loop_hook(data.mlx_ptr, handle_no_event, &data);
	mlx_hook(data.win_ptr, 2, 1L<<1, (void *)deal_key, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, ft_close, &data);
	//mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
//	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
//	mlx_destroy_display(data.mlx_ptr);
//	free(data.mlx_ptr);
	return (0);
}
