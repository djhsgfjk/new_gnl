/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:59 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/03 16:44:51 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_rewrite_buff(char **buff, int a, int b)
{
	int	i;

	if ((*buff) == (char *)0)
		return ((*buff));
	i = 0;
	while (a < b)
	{
		(*buff)[i] = (*buff)[a];
		i++;
		a++;
	}
	while (i < b)
	{
		(*buff)[i] = '\0';
		i++;
	}
	return ((*buff));
}

static int	ft_strjoin(char **s1, int len1, char **s2, int len2)
{
	char	*new_str;
	int		i;

	if ((*s2) == (char *)0 || len2 <= 0)
		return (len1);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (new_str == (void *)0)
		return (-1);
	i = 0;
	while (i < len1)
	{
		new_str[i] = (*s1)[i];
		i++;
	}
	while (i - len1 < len2)
	{
		new_str[i] = (*s2)[i - len1];
		i++;
	}
	new_str[i] = '\0';
	if (*s1 != (char *)0)
		free(*s1);
	*s1 = new_str;
	return (i);
}

static char	*ft_result(int n, char **buff, char **line)
{
	free(*buff);
	*buff = (char *)0;
	if (n == 0)
		return (*line);
	if (*line != (char *)0)
		free(*line);
	return ((char *)0);
}

static int	ft_end_of_line(int n, char *line, int len1, char **buff)
{
	int	len2;

	len2 = ft_strlen(*buff);
	if (len1 > 0 && line[len1 - 1] == '\n')
	{
		ft_rewrite_buff(buff, len2, n);
		return (1);
	}
	return (0);
}

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
