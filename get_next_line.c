/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmachaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:12:28 by kmachaka          #+#    #+#             */
/*   Updated: 2022/09/19 15:35:06 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buf, char *mem)
{
	int		readline;
	char	*temp_mem;

	readline = 1;
	while (readline != '\0')
	{
		readline = read(fd, buf, BUFFER_SIZE);
		if (readline == -1)
			return (0);
		else if (readline == 0)
			break ;
		buf[readline] = '\0';
		if (!mem)
			mem = ft_strdup("");
		temp_mem = mem;
		mem = ft_strjoin(temp_mem, buf);
		free(temp_mem);
		temp_mem = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (mem);
}

static char	*extract_line(char *line)
{
	size_t	count;
	char	*mem;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	mem = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*mem == '\0')
	{
		free(mem);
		mem = NULL;
	}
	line[count + 1] = '\0';
	return (mem);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*mem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = ft_read_line(fd, buf, mem);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	mem = extract_line(line);
	return (line);
}
