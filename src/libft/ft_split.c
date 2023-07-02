/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:16:55 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:28:19 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int		i;
	bool	word;

	word = false;
	i = 0;
	while (*s)
	{
		if (*s != c && word == false)
		{
			word = true;
			i++;
		}
		else if (*s == c)
			word = false;
		s++;
	}
	return (i);
}

char	*ft_re_token(char const *s, int start, int end)
{
	char	*token;
	int		i;

	i = 0;
	token = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		token[i] = s[start];
		i++;
		start++;
	}
	token[i] = '\0';
	return (token);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	int		offset;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(((ft_word_count(s, c)) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	offset = -1;
	while (++i <= (int)ft_strlen(s))
	{
		if (s[i] != c && offset < 0)
			offset = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && offset >= 0)
		{
			tab[j++] = ft_re_token(s, offset, i);
			offset = -1;
		}
	}
	tab[j] = NULL;
	return (tab);
}
