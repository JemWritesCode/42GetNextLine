/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:15:13 by jcope             #+#    #+#             */
/*   Updated: 2019/01/28 21:15:14 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32 // needs to be able to be changed for the correction

# include "./libft/libft.h" // my libft
# include <unistd.h> // read();

int				get_next_line(const int fd, char  **line);

typedef struct	s_gnl  //Struct for a Linked List of File Descriptors & their current buffer.
{
	int		fd;
	char	*buf;
	struct s_gnl *next;
}				t_gnl;

#endif 
