/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/30 17:31:04 by obouizga         ###   ########.fr       */
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
# define W_H  1080
# define W_W 1920
# define B_S 1
# define COLOR 0xfc49dc  
# define B_OFF 0.8
# define S_OFF 0.2

typedef double	t_d;

typedef struct s_mlx
{
	void	*m_id;
	void	*w_id;
}			t_mlx;

typedef struct s_u
{
	t_d	x;
	t_d	y;
}			t_u;

typedef struct s_data
{
	void	*img;
	char	*ad;
	int		bpp;
	int		l_l;
	int		endian;
}				t_data;

typedef struct s_iso
{
	double	x;
	double	y;
	int		clr;
}				t_iso;

typedef struct s_peri
{
	t_d	max_x;
	t_d	max_y;
	t_d	min_x;
	t_d	min_y;
}				t_peri;

typedef struct s_sh
{
	t_iso	**iso;
	t_peri	peri;
}	t_sh;

typedef struct s_off
{
	int	x_off;
	int	y_off;
}	t_off;

typedef struct s_atoi
{
	int		val;
	int		clr;
}				t_atoi;

int		ft_atoi(const char *str);
t_atoi	s_atoi(char *str);
int		hex_to_int(char *s);
void	manage_error(int ac, char **av);
int		check_map(char **map);
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
char	**read_map(char *file);
void	print_map(char **map);
t_iso	to_isom(double x, double y, t_atoi zee, t_u units);
void	plot_line(t_iso a, t_iso b, t_data *img, t_off offset);
void	draw_grid(void *m_id, void *w_id);
char	***get_cords(char **map, int row);
void	print_tri(char ***s);
t_iso	**iso_square(int row, int col);
t_sh	cords_atoi(char ***cords, int *dim, char **map);
void	print_iso_table(t_iso **iso, int col);
void	draw_line(t_iso a, t_iso b, void *m_id, void *w_id);
void	drawing(t_sh sh, int *row_col, t_data *img);
void	put_pixel(t_data *data, int x, int y, int color);
void	free_double_p(char **strings);
void	free_both(char **s1, char **s2);
int		*map_dim(char **map);
void	display(t_data *img, int *dim, char **map);
char	**check_get_map(int ac, char **av);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		find_min_z(int row, char ***cor);
int		find_max_z(int row, char ***cor);
int		find_ext_z(int row, char ***cor);
t_u		def_unit(int *dim, char **map, char ***cor);
void	free_tri_p(char ***ptr);
void	free_double_iso(t_iso **iso);
int		deal_key(int key, void *param);
int		close_window(void);
void	win_id_error(void *w_id);
void	mlx_id_error(void);
void	image_error(void *img);
void	get_data_addr_error(char *ad);

#endif
