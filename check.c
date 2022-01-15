/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:02:47 by athirion          #+#    #+#             */
/*   Updated: 2022/01/15 15:03:19 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_file(char *file)
{
	int	ext_len;
	int cmp;
	
	if (ft_strrchr(file, '.') == NULL)
		ft_exit(1);
	ext_len = ft_strlen(ft_strrchr(file, '.'));
	cmp = ft_strncmp(ft_strrchr(file, '.'), ".fdf", ext_len);
	if (cmp != 0 || ext_len != 4)
		ft_exit(1);
}
