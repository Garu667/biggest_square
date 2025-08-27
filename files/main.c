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

int	ft_do(char *filename, int opt)
{
	unsigned long	size;
	char	*file;

	size = 0;
	if (opt == 0)
		file = ft_get_stdin();
	if (opt > 1)
	{
		size = ft_get_size(filename);
		file = ft_get_file(filename, size);
	}
	if (!file || ft_strlen(file) < 9)
	{
		free(file);
		return (ft_ret_val(1));
	}
	ft_do_bsq(file);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		ft_do("", 0);
	else
	{
		while (i < ac)
		{
			ft_do(av[i], ac);
			if (i != (ac - 1))
				write(1, "\n", 1);
			i++;
		}
	}
}
