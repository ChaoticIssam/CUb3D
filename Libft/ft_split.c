/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:27:54 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/21 12:16:13 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static void	free_all(char **str)
{
	while (*str)
		free(*str++);
	free(str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;
	size_t	y;

	if (!s)
		return (0);
	i = 0;
	y = ft_strlen(s);
	if (len > y - start && y >= start)
		len = y - start;
	if (start >= y)
		len = 0;
	x = malloc(sizeof(char) * (len + 1));
	if (!x)
		return (0);
	if (len == 0 || start > y)
	{
		x[i] = '\0';
		return (x);
	}
	while (s[start] && i < len)
		x[i++] = s[start++];
	x[i] = '\0';
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		x;
	int		l;

	i = 0;
	l = -1;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (words_count((char *)s, c) + 1));
	if (!ptr)
		return (NULL);
	while (++l < words_count((char *)s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		x = i;
		while (s[i] != c && s[i])
			i++;
		ptr[l] = ft_substr(s, x, i - x);
		if (!ptr[l])
			return (free_all(ptr), NULL);
	}
	return (ptr[l] = NULL, ptr);
}
