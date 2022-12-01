/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:58:44 by athirion          #+#    #+#             */
/*   Updated: 2022/03/23 20:10:32 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_update_temp(char *temp)
{
	int		len;
	/* int		i; */
	char	*new_temp;

	/* i = 0; */
	len = ft_len_newline(temp);
	if (temp[len] == '\0')
		return (free(temp), NULL);
	new_temp = ft_substr_gnl(temp, len, ft_getlen(temp) - len);
	if (!new_temp)
		return (free(temp), NULL);
	free(temp);
	temp = NULL;
	return (new_temp);
}

char	*ft_get_line(char *temp)
{
	int		len;
	char	*line;

	if (temp[0] == '\0')
		return (NULL);
	len = ft_len_newline(temp);
	line = ft_substr_gnl(temp, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*line;
	char		*buf;
	int			ret;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret && !ft_is_nl(temp))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (free(buf), NULL);
		buf[ret] = '\0';
		temp = ft_strjoin_free(temp, buf);
	}
	free(buf);
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);
	temp = ft_update_temp(temp);
	return (line);
}

char	*gnl(int fd, int width)
{
	static char	*temp = NULL;
	char		*line;
	char		*buf;
	int			ret;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (width + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret && !ft_is_nl(temp))
	{
		ret = read(fd, buf, width);
		if (ret == -1)
			return (free(buf), NULL);
		buf[ret] = '\0';
		temp = ft_strjoin_free(temp, buf);
	}
	free(buf);
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);
	temp = ft_update_temp(temp);
	return (line);
}
