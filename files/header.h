/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:30:06 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 19:45:00 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_pos
{
	int	x;
	int	y;
	int	size;
}	t_pos;

typedef struct	s_len
{
	int	x;
	int	y;
}	t_len;

typedef struct	s_params
{
	char	empty;
	char	wall;
	char	square;
}	t_params;

typedef	struct	s_bsq
{
	t_params	params;
	t_len		len;
	t_pos		pos;
}	t_bsq;

void			ft_search(char **grid, int *line, t_bsq *bsq);
unsigned long	ft_get_size(char *filename);
void			ft_assign(t_pos *pos, int x, int y, int size);
void			ft_print_bsq(char **grid, int len);
void			ft_put_bsq(char **grid, char square, t_pos pos);
void			ft_putstr(char *str);
void			ft_do_bsq(char *file);
void			ft_init(int *a, int *b, int *c, int *d);
char			**ft_split(char *str);
char			**ft_parse_tab(char **tab, char *str, int line, int i);
char			*ft_get_file(char *filename, unsigned long size);
char			*ft_get_stdin(void);
void			ft_get_params(char *str, t_params *params);
int				ft_get_len(char **grid, t_len *len);
int				ft_if(int i, int j, int *line, int prev);
int				ft_ret_val(int i);
int				ft_check(char **grid, t_params params, t_len len);
int				ft_bsq(char **grid);
int				ft_free_grid(char **grid, int opt, int indx);
int				ft_strlen(char *str);
int				ft_min(int a, int b, int c);
int				ft_atoi(char *str);
#endif
