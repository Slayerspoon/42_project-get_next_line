/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 23:28:24 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/25 20:45:10 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

void	init_buffer(char *buffer, int call_number)
{
	int	index;

	index = 0;
	if (call_number == 0)
	{
		while (index < BUFFER_SIZE + 1)
		{
			buffer[index] = '\0';
			index++;
		}
	}
}

int	update_temp(char *temp, char *buffer)
{
	int	temp_index;
	int	buffer_index;

	temp_index = 0;
	buffer_index = 0;
	while (temp[temp_index] != '\0')
		temp_index++;
	while (buffer_index < BUFFER_SIZE)
	{
		if (buffer[buffer_index] != '\n' && buffer[buffer_index] != '\0')
		{
			temp[temp_index] = buffer[buffer_index];
			buffer[buffer_index] = '\0';
			temp_index++;
		}
		else if (buffer[buffer_index] == '\n')
		{
			buffer[buffer_index] = '\0';
			return (1);
		}
		buffer_index++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			read_result;
	static int	call_number = 0;

	if (BUFFER_SIZE > 0 && fd >= 0 && fd <= 999)
	{
		temp = (char *)ft_calloc(1000000, sizeof(char));
		init_buffer(buffer, call_number);
		while (update_temp(temp, buffer) != 1)
		{
			read_result = read(fd, buffer, BUFFER_SIZE);
			if (read_result <= 0)
				break ;
		}
		*line = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
		ft_strlcpy(*line, temp, ft_strlen(temp) + 1);
		free(temp);
		call_number++;
		if (read_result > 0)
			return (1);
		return (read_result);
	}
	return (-1);
}
