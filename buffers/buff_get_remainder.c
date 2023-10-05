/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:25:43 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "buffers.h"

size_t	buff_get_remainder(const uint8_t *buff_ptr)
{
	size_t leftover;

	if (!buff_ptr)
		return (-1);
	leftover = BUFFSIZE - (strlen((char *)buff_ptr) + 1);
	return (leftover);
}
