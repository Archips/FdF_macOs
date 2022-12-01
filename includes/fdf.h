/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:29:13 by athirion          #+#    #+#             */
/*   Updated: 2022/03/23 20:14:14 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define BUFFER_SIZE 1

# define WIDTH		1600
# define HEIGHT		1000
# define COLOR_1	0x51578f
# define COLOR_2	0x3B5f8A
# define COLOR_3	0x60839A
# define COLOR_4	0xBF7B4B
# define COLOR_5	0xFF8000

# define NB_1	0x4D4C52
# define NB_2	0x606069
# define NB_3	0x93939D
# define NB_4	0xBAC0C3
# define NB_5	0xFFFFFF

# define ERR_0	"Argument missing: Usage: ./fdf [path/to/map]\n"
# define ERR_1	": Usage: map.[fdf]\n"
# define ERR_2	"Failed to close the map\n"
# define ERR_3	": Failed to open the map\n"
# define ERR_4	"Failed to display the map:\n\
- map's height and width must both be greater than one\n"
# define ERR_5	"Failed to allocate memory\n"
# define ERR_6	"Failed to init the minilibx\n"
# define EXIT	"---------------------> EXIT <---------------------"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	***map;
	char	*name;
	char	*map_name;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		min_map;
	int		max_map;
	int		iso;
	int		color;
	int		rand_color;
	double	altitude;
	double	beta;
	double	gamma;
	double	alpha;
	double	scale;
	double	x_offset;
	double	y_offset;

}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

void	ft_check_file(char *file);

double	ft_percent(int min, int max, int current);
int		ft_get_intensity(int min, int max, double percent);
int		ft_get_z_color(t_data *data, t_point p);
int		ft_get_color(t_point p1, t_point p2, t_point current, t_point delta);

void	ft_change_color(t_data *data);
void	ft_rand_color(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_data *data, t_point begin, t_point end);
void	ft_draw(t_data *data);
int		ft_draw_map(t_data *data);

void	ft_free_tab(char **tab);
void	ft_free_map(char ***map, t_data *data, int max);

char	*ft_update_temp(char *temp);
char	*ft_get_line(char *temp);
char	*get_next_line(int fd);
char	*gnl(int fd, int width);

size_t	ft_getlen(const char *s);
int		ft_len_newline(char *str);
int		ft_is_nl(char *str);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_free(char *s1, char *s2);

void	ft_init_struct(t_data *data, char *file);
t_point	ft_init_point(int x, int y, t_data *data);

void	ft_reset_map(t_data *data);
void	ft_init_menu(t_data *data);

void	ft_deal_key(int key, t_data *data);

int		loop(void *data);

void	ft_offset(int key, t_data *data);
void	ft_altitude(int key, t_data *data);
void	ft_scale(int key, t_data *data);
void	ft_rotate(int key, t_data *data);
void	ft_change_view(t_data *data);

int		ft_atoi_hex(char *hex);
int		ft_min(int a, int b);
int		ft_abs(int a);

int		ft_get_height(char *file, int width);
int		ft_get_width(char *file);
void	ft_fill(char ***map, char *str, int i, t_data *data);
char	***ft_read(char	*file, t_data *data);

t_point	ft_project(t_point *p, t_data *data);

int		ft_open(char *file);
void	ft_exit(int error);
int		ft_close(t_data *data);

char	*ft_get_name(t_data *data);
//double	ft_get_percent(t_point p1, t_point p2, t_point current);
//char	*ft_title(char *map_name);

#endif
