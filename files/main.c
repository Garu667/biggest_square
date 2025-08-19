/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:53:55 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 20:11:33 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_do(char *file)
{
	if (ft_strlen(file) < 9)
		return (ft_ret_val(1));
	file = ft_get_stdin();
	if (!file)
	{
		free(file);
		return (ft_ret_val(1));
	}
	ft_do_bsq(file);
	return (0);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	unsigned long	size;
	char			*file;
	int				i;

	i = 0;
	file = NULL;
	if (ac == 1)
		ft_do(file);
	while (i++ < ac - 1)
	{
		size = ft_get_size(av[i]);
		file = ft_get_file(av[i], size);
		if (ft_strlen(file) < 9)
			return (ft_ret_val(1));
		if (!file)
		{
			free(file);
			return (ft_ret_val(1));
		}
		ft_do_bsq(file);
		if (i != (ac - 1))
			write(1, "\n", 1);
	}
}
