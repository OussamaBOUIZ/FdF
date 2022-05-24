/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/24 19:20:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
//2880x1620
# define W_H 1620 
# define W_W 2500
# define B_S 1
# define COLOR 0xeb3461  
# define B_OFF 0.8
# define S_OFF 0.2
# define U 50
typedef struct s_data
{
	void	*img;
	char	*ad;
	int		bpp;
	int		l_l;
	int		endian;
}				t_data;

typedef struct t_cart
{
	double	x;
	double	y;
	double	z;
}			t_cart;
typedef struct s_point
{
	double	x;
	double	y;
}		t_point;

typedef t_point	t_iso;

typedef struct s_sqr
{
	t_point	t_l;
	t_point	t_r;
	t_point	b_l;
	t_point	b_r;
}			t_sqr;

typedef struct s_peri
{
	int	s_x;
	int	s_y;
	int	e_x;
	int	e_y;
}				t_peri;

typedef double	t_d;

int		ft_atoi(const char *str);
void	manage_error(int ac, char **av);
int		check_map(char **map);
void	check_neg(double *x0, double *y0, double *x1, double *y1);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int nb);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		count_lines(int fd);
char	**read_map(char *file);
void	print_map(char **map);
double	get_slope(double x0, double y0, double x1, double y1);
double	get_const(double m, double x, double y);
t_iso	to_isom(double x, double y, double z);
double	slope(t_iso a, t_iso b);
void	swap(double *a, double *b);
// void	plot_line(t_iso a, t_iso b, void **mlx);
void	plot_line(t_iso a, t_iso b, t_data *img);
void	draw_grid(void *m_id, void *w_id);
int		*get_map_dim(char **map);
char	***get_cords(char **map, int row);
void	print_tri(char ***s);
int		ptr_str_len(char **s);
t_iso	**iso_square(int row, int col);
t_iso	**cords_atoi(char ***cords, int *dim);
void	print_iso_table(t_iso **iso, int col);
void	draw_line(t_iso a, t_iso b, void *m_id, void *w_id);
// void	drawing(t_iso **iso_tb, int *row_col, void **mlx);
void	drawing(t_iso **iso_tb, int *row_col, t_data *img);
void	sharp_line(void *m, void *w);
// void	put_pixel(void **mlx, int x, int y);
void	put_pixel(t_data *data, int x, int y);
void	free_double_p(char **strings);
void	free_both(char **s1, char **s2);
int		*map_dim(char **map);
// void	display(void **mlx, int *dim, char **map);
void	display(t_data *img, int *dim, char **map);
char	**check_get_map(int ac, char **av);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		find_max_z(char **map, int row);
t_d		def_unit(int *dim, char **map);
t_d	max(t_d a, t_d b);

#endif
