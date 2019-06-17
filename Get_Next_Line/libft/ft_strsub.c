/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:01:38 by jcope             #+#    #+#             */
/*   Updated: 2018/10/22 23:02:56 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a "fresh" 
** substring from the string given as an argument. The 
** substring begins at indexstart and is of size len.
** If start and len aren't referencing to a valid substring,
** the behavior is undefined. If the allocation fails,
** the function returns NULL. 
** Param 1: The string from which create the substring.
** Param 2: The start index of the substring.
** Param 3: The size of the substring.
** Return: The substring.
*/

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = -1;
	if (!s || !(new = ft_strnew(len)))
		return (NULL);
	while (++i < len)
		new[i] = s[start + i];
	return (new);
}
