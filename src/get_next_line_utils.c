/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awis <awis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:57 by nipostni          #+#    #+#             */
/*   Updated: 2023/07/02 13:20:02 by awis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char		*str;
// 	size_t		range;
// 	size_t		i;

// 	if (!s || !(*s))
// 		return (NULL);
// 	i = ft_strlen(s);
// 	range = 0;
// 	if (start < i)
// 		range = i - start;
// 	if (range > len)
// 		range = len;
// 	str = (char *)malloc((range + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (i < range)
// 	{
// 		*(str + i) = *(s + start + i);
// 		i++;
// 	}
// 	*(str + i) = '\0';
// 	return (str);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return ((char *)str + i);
// 		i++;
// 	}
// 	if (str[i] == c)
// 		return ((char *)str + i);
// 	return (NULL);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		str[i + j] = s2[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	free(s1);
// 	return (str);
// }
