/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:59 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/03 16:45:53 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;
	int			n;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((char *)0);
	line = (char *)0;
	len = 0;
	n = BUFFER_SIZE;
	if (buff == (char *)0)
	{
		buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		n = read(fd, buff, BUFFER_SIZE);
	}
	while (n > 0)
	{
		buff[n] = '\0';
		len = ft_strjoin(&line, len, &buff, ft_strlen(buff));
		if (ft_end_of_line(n, line, len, &buff))
			return (line);
		n = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_result(n, &buff, &line));
}
