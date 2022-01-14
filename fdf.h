/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:29:13 by athirion          #+#    #+#             */
/*   Updated: 2022/01/14 10:26:20 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# define WIN_WIDTH 1280
# define WIN_HEIGHT 800
# define COLOR_1		0x2B9DA2
# define COLOR_2	0x2BD1A2
# define COLOR_3		0xFF52A8
# define COLOR_4		0xFFE504
# define COLOR_5		0xFEA604

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	altitude;
	int iso;
	int para;
	double	beta;
	double	gamma;
	double	alpha;
	double	scale;
	double	x_offset;
	double	y_offset;
	int		width;
	int		height;
	char ***map;
	int	max_map;
	int min_map;

}				t_data;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int	color;
}				t_point;

typedef struct	s_d_point
{
	double x;
	double y;
	int	color;
}				t_d_point;

// GET_NEXT_LINE
char	*ft_update_temp(char *temp);
char	*ft_get_line(char *temp);
char	*get_next_line(int fd);
int		ft_len_newline(char *str);
int		ft_is_nl(char *str);

void	draw_line(t_data data, t_point begin, t_point end);
void		deal_key(int key, t_data *data);
char	***ft_read(char	*file, t_data *data);
void	ft_fill(char ***map, char *str, int i, t_data *data);
void	ft_free_map(char ***map, t_data *data, int index);
int	ft_get_width(char *file);
int	ft_get_height(char *file);
int	ft_open(char *file);
int ft_close(t_data *data);
int ft_get_height(char *file);
int	ft_atoi_hex(char *hex);
t_point 	ft_project(t_point	*p, t_data data);
void	ft_draw(t_data data);
void	ft_error(char *file, char *prog);
t_point	ft_init_point(int x, int y, t_data data);
int		ft_draw_map(t_data *data);
int 	ft_abs(int a);
double	ft_percent(int min, int max, int current);
int	ft_get_intensity(int min, int max, double percent);
double	ft_get_percent(t_point p1, t_point p2, t_point current);
int	ft_get_z_color(t_data *data, t_point p);
int	ft_get_color(t_point p1, t_point p2, t_point current, t_point delta);
int	ft_min(int a, int b);
#endif
