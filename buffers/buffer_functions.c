/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:28:45 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "altlib.h"
#define BUFFSIZE 500

bool	buff_flush(uint8_t *buff_ptr)
{
	if (!buff_ptr)
		return (false);
	ft_putstr(buff_ptr);
	ft_bzero(buff_ptr, BUFFSIZE);
	return (true);
}

size_t	buff_get_remainder(const uint8_t *buff_ptr)
{
	size_t leftover;

	if (!buff_ptr)
		return (-1);
	leftover = BUFFSIZE - (ft_strlen(buff_ptr) + 1);
	return (leftover);
}

bool	buff_write(uint8_t *buff_ptr, const uint8_t *data, const size_t size)
{
	size_t buff_len;
	size_t leftover;

	if (!buff_ptr || !data || !size)
		return (false);
	leftover = buff_get_remainder(buff_ptr);
	buff_len = BUFFSIZE - leftover - 1;
	if (leftover >= size)
	{
		ft_strncpy(buff_ptr + buff_len, data, size);
	}
	else
	{
		ft_strncpy(buff_ptr + buff_len, data, leftover);
		buff_flush(buff_ptr);
		buff_write(buff_ptr, data + leftover, size - leftover);
	}
	return (true);
}

char	*buff_init(void)
{
	static char	buff[BUFFSIZE];
	char		*buff_ptr;

	buff_ptr = &buff[0];
	return (buff_ptr);
}
