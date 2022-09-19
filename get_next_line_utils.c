/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmachaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:14:07 by kmachaka          #+#    #+#             */
/*   Updated: 2022/09/19 15:33:42 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	remain;

	if (start > ft_strlen(str))
		remain = 0;
	else
		remain = ft_strlen(&str[start]);
	if (remain < len)
		len = remain;
	result = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		s_len;
	char	*cast_dup;

	i = 0;
	s_len = ft_strlen(str);
	cast_dup = (char *)malloc(sizeof(*cast_dup) * (i + 1));
	while (i < s_len)
	{
		cast_dup[i] = str[i];
		i++;
	}
	cast_dup[i] = '\0';
	return (cast_dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*j_str;

	i = 0;
	j = 0;
	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (j_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		j_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		j_str[i + j] = s2[j];
		j++;
	}
	j_str[i + j] = '\0';
	return (j_str);
}
