/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:03 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/03 16:48:59 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == (char *)0)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_rewrite_buff(char **buff, int a, int b)
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

int	ft_strjoin(char **s1, int len1, char **s2, int len2)
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

char	*ft_result(int n, char **buff, char **line)
{
	free(*buff);
	*buff = (char *)0;
	if (n == 0)
		return (*line);
	if (*line != (char *)0)
		free(*line);
	return ((char *)0);
}

int	ft_end_of_line(int n, char *line, int len1, char **buff)
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
