/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:04:23 by athirion          #+#    #+#             */
/*   Updated: 2022/01/14 10:54:30 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_is_nl(char *str);
int		ft_len_newline(char *str);

char	*ft_update_temp(char *temp);
char 	*ft_get_line(char *temp);
char	*get_next_line(int fd);

#endif
