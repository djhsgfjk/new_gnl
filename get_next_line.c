/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:59 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/02 17:52:44 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rewrite_buff(char **buff, int a, int b)
{
	char	*new_buff;
	int 	i;

	if ((*buff) == (char *)0 || a >= b)
	{
		if ((*buff) != (char *)0)
		{
			free((*buff));
			(*buff) = (char *)0;
		}
		return ((*buff));
	}
	new_buff = (char *)malloc(b - a + 1);
	i = 0;
	while (a < b)
	{
		new_buff[i] = (*buff)[a];
		i++;
		a++;
	}
	new_buff[i] = '\0';
	free((*buff));
	(*buff) = new_buff;
	return ((*buff));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	ft_strjoin(char **s1, int len1, char **s2, int len2)
{
	char	*new_str;
	int		i;

	if ((*s2) == (void *)0)
		return (-1);
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;
	static int 	n;
	int 		len;
	int 		buff_len;

	buff = (char *)0;
	line = (char *)0;
	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((char *)0);
	if (buff == (char *)0)
	{
		buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		n = read(fd, buff, BUFFER_SIZE);
	}
	while (n > 0)
	{
		buff[n] = '\0';
		buff_len = ft_strlen(buff);
		len = ft_strjoin(&line, len, &buff, buff_len);
		if (line[len-1] == '\n')
		{
			ft_rewrite_buff(&buff, buff_len, n);
			return (line);
		}
		n = read(fd, buff, BUFFER_SIZE);
	}
	free (buff);
	buff = (char *)0;
	if (n == 0)
		return (line);
	return ((char *)0);

}
