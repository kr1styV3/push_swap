/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:39:56 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/23 16:43:41 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_with_free(char **s)
{
	char	*str_copy;
	size_t	str_len;

	str_len = ft_strlen(*s);
	str_copy = malloc((str_len + 1) * sizeof(char));
	if (!str_copy)
		return (NULL);
	while (str_len--)
		str_copy[str_len] = (*s)[str_len];
	str_len = ft_strlen(*s);
	str_copy[str_len] = '\0';
	free(*s);
	*s = NULL;
	return (str_copy);
}

char	*ft_strjoin_with_free(char **s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;
	int		s1_len;

	if (s2[0] == '\0')
		return (ft_strdup_with_free(s1));
	s1_len = ft_strlen(*s1);
	len = s1_len + ft_strlen(s2) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (*s1 && i < s1_len)
		res[i++] = (*s1)[j++];
	j = 0;
	while (s2 && i < len)
		res[i++] = s2[j++];
	free(*s1);
	*s1 = NULL;
	return (res);
}
