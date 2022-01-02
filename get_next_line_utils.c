/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:03 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/01 14:10:26 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_create_elem(int fd, char *s, int len)
{
	t_line	*new_elem;

	new_elem = (t_line *)malloc(sizeof(t_line));
	new_elem->fd = fd;
	new_elem->s = s;
	new_elem->len = len;
	return (new_elem);
}

void	ft_clear_line(t_line *line)
{
	if (line == (void *)0)
		return ;
	if (line->s != (void *)0)
		free(line->s);
	free(line);
}