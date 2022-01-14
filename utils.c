/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:32:55 by athirion          #+#    #+#             */
/*   Updated: 2022/01/10 12:10:40 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Failed to open the file", 2);
		exit(0);
	}
	return (fd);
}

void	ft_free_map(char ***map, t_data *data, int i)
{
	int index;
	int j;

	index = 0;
	while (index <= i)
	{
		j = 0;
		while (j < data->width)
		{
			free(map[index][j]);
			j ++;
		}
		free(map[index]);
		i ++;
	}
	free(map);
}
/*
void	*ft_free_map(char ***map, t_data &data, int index)
{
	int	i;
	int	j;

	i = index;
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
}*/

int	ft_hex_to_int(char c, char *hex)
{
	int	i;
	
	i = 0;
	while (hex[i])
	{
		if (ft_toupper(c) == hex[i])
			break;
		i ++;
	}
	return (i);
}

int	ft_atoi_hex(char *hex)
{
	int	i;
	int	nb;

	i = 3;
	nb = 0;
	while (hex[i])
	{
		nb = nb * 16 + ft_hex_to_int(hex[i], "0123456789ABCDEF");
		i ++;
	}
	return (nb);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_abs(int	a)
{
	return (((a <= 0) * - a) + ((a > 0) * a));
}
