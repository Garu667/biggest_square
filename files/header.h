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

t_pos		ft_search(char **grid, char *params, int *line, int *len);
unsigned long	ft_get_size(char *filename);
void			ft_assign(t_pos *pos, int x, int y, int size);
void			ft_print_bsq(char **grid, int len);
void			ft_put_bsq(char **grid, char *params, t_pos pos);
void			ft_putstr(char *str);
void			ft_do_bsq(char *file);
void			ft_init(int *a, int *b, int *c, int *d);
char			**ft_split(char *str);
char			**ft_parse_tab(char **tab, char *str, int line, int i);
char			*ft_get_file(char *filename, unsigned long size);
char			*ft_get_stdin(void);
char			*ft_get_params(char *str);
int				*ft_get_len(char **grid);
int				ft_if(int i, int j, int *line, int prev);
int				ft_free_params(int *len, int *line, char *params);
int				ft_ret_val(int i);
int				ft_check(char **grid, char *params, int *len);
int				ft_bsq(char **grid);
int				ft_free_grid(char **grid, int opt, int indx);
int				ft_strlen(char *str);
int				ft_min(int a, int b, int c);
int				ft_atoi(char *str);
#endif
