/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:06:41 by athirion          #+#    #+#             */
/*   Updated: 2022/01/15 11:15:19 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hex_to_int(char c, char *hex)
{
	int	i;

	i = 0;
	while (hex[i])
	{
		if (ft_toupper(c) == hex[i])
			break ;
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

int	ft_abs(int a)
{
	return (((a <= 0) * -a) + ((a > 0) * a));
}
