/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:44:28 by athirion          #+#    #+#             */
/*   Updated: 2022/01/17 16:37:22 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_map(char ***map, t_data *data, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < data->width)
		{
			free(map[i][j]);
			map[i][j] = NULL;
			j ++;
		}
		free(map[i]);
		map[i] = NULL;
		i ++;
	}
	free(map);
	map = NULL;
}
