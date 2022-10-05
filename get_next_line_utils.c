/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:22:43 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/21 21:34:01 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void		*ptr;
	char		*ptr_modifiable;
	long long	total_bytes;

	total_bytes = nelem * elsize;
	ptr_modifiable = (char *)malloc(total_bytes);
	ptr = ptr_modifiable;
	if (ptr_modifiable != NULL)
	{
		while (total_bytes > 0)
		{
			ptr_modifiable[total_bytes - 1] = 0;
			total_bytes--;
		}
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	if (s != NULL)
	{
		while (s[length] != '\0')
		{
			length++;
		}
	}
	else
		length = 0;
	return (length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	length;

	length = ft_strlen(src);
	index = 0;
	if (!dest || !src)
		return (0);
	if (size > 0)
	{
		while (index < size - 1 && src[index] != '\0')
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (length);
}
