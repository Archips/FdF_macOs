/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:49:51 by athirion          #+#    #+#             */
/*   Updated: 2022/01/14 15:46:13 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_data *data)
{
	ft_free_map(data->map, data, data->height - 1);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free(data->name);
	exit(0);
}

char	*ft_title(char *map_name)
{
	char	*map;
	char	*title;
	int		i;

	i = 0;
	while (map_name[i] && map_name[i] != '/')
		i ++;
	map = ft_substr(map_name, i + 1, ft_strlen(map_name) - i + 1);
	map = ft_strtrim(map, ".fdf");
	title = ft_strjoin("fdf - ", map);
	free(map);
	return (title);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_init_struct(&data, argv[1]);
		ft_draw_map(&data);
		ft_init_menu(&data);
		mlx_loop_hook(data.mlx_ptr, handle_no_event, &data);
		mlx_hook(data.win_ptr, 2, 1L << 1, (void *)ft_deal_key, &data);
		mlx_hook(data.win_ptr, 17, 1L << 17, ft_close, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("Error usage\n");
	return (0);
}
