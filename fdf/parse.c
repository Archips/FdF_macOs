/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:14:11 by athirion          #+#    #+#             */
/*   Updated: 2022/01/14 11:20:07 by athirion         ###   ########.fr       */
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
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height ++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

void	ft_free_tab(char **tab)
{
	int	i;
	int j;

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
	char	*line;

	fd = ft_open(file);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	free(line);
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
	free(str);
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
