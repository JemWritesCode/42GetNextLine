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

static t_list	*gnl_add(t_list **files, int fd)
{
	t_list	*tmp;

	tmp = *files;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(files, tmp);
	return (*files);
}

static void		gnl_del(t_list *cur)
{
	char	*tmp;

	if ((tmp = ft_strchr(cur->content, '\n')))
	{
		tmp = ft_strdup(tmp + 1);
		free(cur->content);
		cur->content = tmp;
	}
	else
		ft_strclr(cur->content);
}

static char		*ft_copytil(char *dst, const char *src, char c)
{
	int		i;

	i = -1;
	while (src[++i] && src[i] != c)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				check;
	static t_list	*files;
	t_list			*cur;

	EXIST_CHECK(fd < 0 || !line || read(fd, buf, 0) < 0);
	cur = gnl_add(&files, fd);
	while ((check = read(fd, buf, BUFF_SIZE)))
	{
		buf[check] = '\0';
		EXIST_CHECK(!(tmp = ft_strjoin(cur->content, buf)));
		free(cur->content);
		cur->content = tmp;
		if (ft_strchr(cur->content, '\n'))
			break ;
	}
	if (!check && !ft_strlen(cur->content))
		return (0);
	EXIST_CHECK(!(*line = ft_strnew(ft_strlen(cur->content))));
	*line = ft_copytil(*line, cur->content, '\n');
	gnl_del(cur);
	return (1);
}
