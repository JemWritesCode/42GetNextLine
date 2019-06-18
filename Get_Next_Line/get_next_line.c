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
#include <stdio.h> // printf() for tests. REMOVE

t_gnl		*gnl_new(int fd)
{
	t_gnl *new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->buf = "\0";
	new->fd = fd;
	new->next = NULL;
	return (new);
}

/*
** Delete the
*/

//void gnl_del(t_gnl **lst)
//{
//	if ((*lst)->next)
//		gnl_del(&(*lst)->next);
//	ft_strdel(&(lst->buf));
//	ft_memdel((&(lst->fd));
//	ft_memdel((void **)lst);
//}

/*
** Get the GNL struct of the current file descriptor.
** If it doesn't exist make a new one with gnl_new().
*/

t_gnl	*get_cur_file(int fd, t_gnl **files)
{
	t_gnl	*temp;

	temp = *files;
	while (temp) // go through the list of files and see if the fd matches any we have so far. 
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = gnl_new(fd); // if it doesn't match anything in the list already make a new file
	temp->next = *files; // add the new gnl struct to the begining of the files list.
	*files = temp; // then set the head of the files list to now be the newest gnl struct.
	return (temp);
}

/*
** First parameter is the file descriptor that will be used to read.
** Second parameter is the address of a pointer to a character that will be used
** to save the line read from the file descriptor.
*/

int		get_next_line(const int fd, char  **line)
{
	char	buf[BUFF_SIZE + 1]; // +1 for null terminator
	static t_gnl	*files; // The linked list of all the files the application is currently reading from. Has to stay at the head of list so you can always go through the whole list when you come back to this function.
	t_gnl			*cur;	// a pointer to the current file we're reading from.
	int		 		ret;
	int				newlinePos;

	newlinePos = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buf, 0) < 0) //fd is an error code || line is null || Bad Buff Size || nothing to read
		return (-1); //Error
	cur = get_cur_file(fd, &files);
	while ((ret = read(fd, buf, BUFF_SIZE))) //reading through the file buff_size bytes at a time. While any bytes are being read.
	{
		buf[ret] = '\0'; // null terminator for the end of buff since read returns number of bytes actually read as ret.
		MALLOC_CHECK((cur->buf = ft_strjoin(cur->buf, buf))); // add to the gnl struct's buff...cur->buf is at begining of what's all thats been read.  
		if (ft_strchr(buf, '\n')) // until you hit a newline somewhere in the buf.
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(cur->buf)){ //no bytes read or the length of that file's buffer is 0.
		// ft_strdel(&(cur->buf)); pointer being freed was not allocated *** set a breakpoint in malloc_error_break to debug // I think I'm supposed to free the whole thing?
		while (1); //for valgrind testing.
		return (0); // File Reading Completed
	}
	while (cur->buf[newlinePos] != '\0' && cur->buf[newlinePos] != '\n')
		newlinePos++;
	*line = ft_strsub(cur->buf, 0, newlinePos); //make a a new stringsub from buf[0] to buf[newLinePos]
	(newlinePos < (int)ft_strlen(cur->buf)) ? cur->buf += (newlinePos + 1): ft_bzero(cur->buf, ft_strlen(cur->buf)); // you'll potentially have some characters after the /n in the buf and will need to set them to null. If not then move the current file's buf position to right after the newline.
	return (1); // Line was read
}
