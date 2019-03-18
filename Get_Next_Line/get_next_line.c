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
	if (fd < 0 || !line)
		return (-1); //Error 
	return (1); // Line was read
	// return (0); // Reading Completed
}
