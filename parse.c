/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:14:11 by athirion          #+#    #+#             */
/*   Updated: 2022/01/10 12:04:55 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *file)
{
	int	fd;
	int	height;
	char *line;

	height = 0;
	fd = ft_open(file);
	while ((line = get_next_line(fd)) != NULL)
	{
		height ++;
		free(line);
	}
	close(fd);
	return (height);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
	tab = NULL;
}


int	ft_get_width(char *file)
{
	int		fd;
	char	**tab;
	int		i;

	fd = ft_open(file);
	tab = ft_split(get_next_line(fd), ' ');
	i = 0;
	while (tab[i])
		i ++;
	ft_free_tab(tab);
	close(fd);
	return (i);
}

void	ft_fill(char ***map, char *str, int i, t_data *data)
{
	char	**tab;
	int		j;

	tab = ft_split(str, ' ');
	j = 0;
	while (tab[j])
	{
		map[i][j] = ft_strdup(tab[j]);
		if (ft_atoi(map[i][j]) > data->max_map)
			data->max_map = ft_atoi(map[i][j]);
		if (ft_atoi(map[i][j]) < data->min_map)
			data->min_map = ft_atoi(map[i][j]);	
		j ++;
	}
	ft_free_tab(tab);
}

char ***ft_read(char *file, t_data *data)
{
	int	fd;
	int	i;
	char ***map;

	if (data->height < 1)
	{
		ft_putstr_fd("Invalid height of map", 2);
		exit(0);
	}
	map = (char***)malloc(sizeof(char **) * (data->height));
	if (!map)
		return (NULL);
	i = 0;
	fd = ft_open(file);
	while (i < data->height)
	{	
		map[i] = (char **)malloc(sizeof(char *) * (data->width));
		if (!map[i])
			return (ft_free_map(map, data, i), NULL);
		ft_fill(map, get_next_line(fd), i, data);
		i ++;
	}
	close(fd);
	return (map);
}
