/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:15:04 by jcope             #+#    #+#             */
/*   Updated: 2019/01/28 21:15:06 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char  **line)
{
	char	buf[BUFF_SIZE + 1]; // +1 for null terminator

	if (fd < 0 || !line || read(fd, buf, 0) < 0) //fd is an error code || line is null || read returns error
		return (-1); //Error 
	while() //go through linked list
		// if node->fd == fd
			// thats the current fd we're working with


	return (1); // Line was read
	// return (0); // Reading Completed
}
