/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:24:37 by ayblin            #+#    #+#             */
/*   Updated: 2021/12/09 03:53:24 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (s + 1);
		else
			s++;
	}
	if (c == '\0')
		return (s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (0);
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

char	*ft_cutline(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
