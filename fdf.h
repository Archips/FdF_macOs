/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:29:13 by athirion          #+#    #+#             */
/*   Updated: 2022/01/14 16:11:17 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "/usr/local/include/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define WIDTH 2000
# define HEIGHT 1500
# define COLOR_1		0x51578f
# define COLOR_2	0x3B5f8A
# define COLOR_3		0x60839A
# define COLOR_4		0xBF7B4B
# define COLOR_5		0xFF8000

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	char	*name;
	int		endian;
	double	altitude;
	int		iso;
	int		para;
	double	beta;
	double	gamma;
	double	alpha;
	double	scale;
	double	x_offset;
	double	y_offset;
	int		width;
	int		height;
	char	***map;
	int		max_map;
	int		min_map;

}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_data data, t_point begin, t_point end);
void	ft_deal_key(int key, t_data *data);
void	ft_offset(int key, t_data *data);
void	ft_altitude(int key, t_data *data);
void	ft_scale(int key, t_data *data);
void	ft_rotate(int key, t_data *data);
void	ft_change_view(t_data *data);
void	ft_reset_map(t_data *data);
void	ft_init_menu(t_data *data);
char	***ft_read(char	*file, t_data *data);
void	ft_fill(char ***map, char *str, int i, t_data *data);
void	ft_free_tab(char **tab);
void	ft_free_map(char ***map, t_data *data, int max);
int		ft_get_width(char *file);
int		ft_open(char *file);
int		ft_close(t_data *data);
int		ft_get_height(char *file);
int		ft_atoi_hex(char *hex);
void	ft_init_struct(t_data *data, char *file);
t_point	ft_project(t_point *p, t_data data);
void	ft_draw(t_data data);
void	ft_error(char *file, char *prog);
t_point	ft_init_point(int x, int y, t_data data);
int		ft_draw_map(t_data *data);
int		ft_abs(int a);
double	ft_percent(int min, int max, int current);
int		ft_get_intensity(int min, int max, double percent);
double	ft_get_percent(t_point p1, t_point p2, t_point current);
int		ft_get_z_color(t_data *data, t_point p);
int		ft_get_color(t_point p1, t_point p2, t_point current, t_point delta);
int		ft_min(int a, int b);
int		handle_no_event(void *data);
char	*ft_title(char *map_name);

#endif
