/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:07 by gsheev            #+#    #+#             */
/*   Updated: 2022/01/03 16:50:33 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
char	*ft_rewrite_buff(char **buff, int a, int b);
int		ft_strjoin(char **s1, int len1, char **s2, int len2);
char	*ft_result(int n, char **buff, char **line);
int		ft_end_of_line(int n, char *line, int len1, char **buff);
char	*get_next_line(int fd);

#endif
