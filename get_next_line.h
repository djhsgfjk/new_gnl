/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:07 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/02 16:40:51 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_line
{
	int 	fd;
	char	*s;
	int		len;
}	t_line;

char	*get_next_line(int fd);
t_line	*ft_create_elem(int fd, char *s, int len);
void	ft_clear_line(t_line *line);



#endif
