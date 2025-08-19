/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:08 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 19:42:42 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	ft_get_size(char *filename)
{
	unsigned long	count;
	char			c[4096];
	int				read_value;
	int				fd;

	count = 0;
	read_value = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	read_value = read(fd, c, 4096);
	while (read_value > 0)
	{
		count += read_value;
		read_value = read(fd, c, 4096);
	}
	close(fd);
	return (count);
}

char	*ft_get_file(char *filename, unsigned long size)
{
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		close(fd);
		return (NULL);
	}
	read(fd, str, size);
	str[size] = 0;
	close(fd);
	return (str);
}

char	*ft_realloc(char *str, int size, int new_capacity)
{
	char	*new_str;
	int		i;

	new_str = malloc(new_capacity);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}

char	*ft_get_stdin(void)
{
	long	bytes_read;
	char	*str;
	int		size;
	int		capacity;

	size = 0;
	bytes_read = 1;
	capacity = 1024;
	str = malloc(capacity + 1);
	if (!str)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(0, (str + size), 1024);
		size += bytes_read;
		if (size + 1024 > capacity)
		{
			capacity += 1024;
			str = ft_realloc(str, size, capacity + 1);
			if (!str)
				return (NULL);
		}
	}
	str[size] = '\0';
	return (str);
}

int	ft_free_params(int *len, int *pos, int *line, char *params)
{
	free(len);
	free(pos);
	if (!line)
	{
		free(line);
		free(params);
		return (EXIT_FAILURE);
	}
	free(line);
	free(params);
	return (EXIT_SUCCESS);
}
