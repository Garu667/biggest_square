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

void			ft_search(char **tab, int *line, t_bsq *bsq);
void			ft_do_bsq(char *file);
char			**ft_split(char *str);
int				ft_check(char **tab, t_params params, t_len len);
int				ft_free_tab(char **tab, int opt, int indx);
int				ft_do(char *filename, int opt);
int				ft_strlen(char *str);
int				ft_bsq(char **tab);
int				ft_atoi(char *str);
int				ft_ret_val(int i);
#endif
