/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:18:22 by msanabi           #+#    #+#             */
/*   Updated: 2018/10/30 12:38:48 by msanabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lettre(char *s, size_t i, char c)
{
	size_t		j;

	j = i;
	while (s[j] != c && s[j])
		j++;
	return (j - i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**n;
	size_t		i;
	size_t		w;
	size_t		j;
	size_t		k;

	if (!s || !(n = (char **)malloc(sizeof(n) * (n_word((char *)s, c) + 1))))
		return (NULL);
	w = 0;
	i = 0;
	while (w < n_word((char *)s, c))
	{
		while (s[i] == c && s[i])
			i++;
		n[w] = (char *)malloc(sizeof(char) *
				(lettre((char *)s, i, c) + 1));
		j = 0;
		k = lettre((char *)s, i, c);
		while (j < k && s[i])
			n[w][j++] = s[i++];
		n[w][j] = '\0';
		w++;
	}
	n[w] = 0;
	return (n);
}
