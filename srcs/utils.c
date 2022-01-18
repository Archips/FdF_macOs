/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:32:55 by athirion          #+#    #+#             */
/*   Updated: 2022/01/18 10:24:24 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	return (fd);
}

void	ft_exit(int error)
{
	ft_putstr_fd("./fdf: ", 2);
	if (error == 0)
		ft_putendl_fd(ERR_0, 2);
	else if (error == 1)
	{
		ft_putstr_fd(strerror(EINVAL), 2);
		ft_putendl_fd(ERR_1, 2);
	}
	else if (error == 2)
		ft_putendl_fd(ERR_2, 2);
	else if (error == 3)
	{
		ft_putstr_fd(strerror(EBADF), 2);
		ft_putendl_fd(ERR_3, 2);
	}
	else if (error == 4)
		ft_putendl_fd(ERR_4, 2);
	else if (error == 5)
		ft_putendl_fd(ERR_5, 2);
	else if (error == 6)
		ft_putendl_fd(ERR_6, 2);
	ft_putendl_fd(EXIT, 2);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *data)
{
	ft_free_map(data->map, data, data->height);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	ft_putendl_fd(EXIT, 0);
	exit(EXIT_SUCCESS);
}
