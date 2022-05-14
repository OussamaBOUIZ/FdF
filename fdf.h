/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/14 17:57:13 by obouizga         ###   ########.fr       */
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
# define W_H 1200
# define W_W 1200 
# define B_S 1
# define COLOR 16073446
# define B_OFF 0.8
# define S_OFF 0.2

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

int		ft_atoi(const char *str);
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
int		count_lines(int fd);
char	**read_map(char *file);
void	print_map(char **map);
double	get_slope(double x0, double y0, double x1, double y1);
double	get_const(double m, double x, double y);
double	foo(double x, double y, double m, double b);
t_iso	to_isometric(t_cart cart);
void	swap(double *a, double *b);
void	plot_line(t_iso a, t_iso b, void *mlx_id, void *win_id);

#endif