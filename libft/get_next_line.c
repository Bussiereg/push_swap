/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:51:26 by gbussier          #+#    #+#             */
/*   Updated: 2023/02/27 11:50:12 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*gnl_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*read_till_n;
	char		*line;
	static char	*save = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_till_n = gnl_newline(fd, save);
	save = gnl_free(save, NULL);
	if (gnl_strlen(read_till_n) == 0)
		return (gnl_free(read_till_n, NULL));
	if (check_new_line(read_till_n) == -1)
		return (read_till_n);
	line = gnl_strjoin(NULL, read_till_n, check_new_line(read_till_n) + 1);
	if (gnl_strlen(line) == 0)
		return (gnl_free(line, read_till_n));
	save = gnl_strjoin(NULL, read_till_n + check_new_line(line) + 1,
			gnl_strlen(read_till_n) - gnl_strlen(line) + 1);
	if (gnl_strlen(save) == 0)
		save = gnl_free(save, NULL);
	free(read_till_n);
	return (line);
}
