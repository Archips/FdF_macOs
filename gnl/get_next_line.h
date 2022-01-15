/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:04:23 by athirion          #+#    #+#             */
/*   Updated: 2022/01/15 15:41:28 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_getlen(const char *s);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_is_nl(char *str);
int		ft_len_newline(char *str);

char	*ft_update_temp(char *temp);
char	*ft_get_line(char *temp);
char	*get_next_line(int fd);

#endif
