/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:01:41 by imatek            #+#    #+#             */
/*   Updated: 2024/06/17 10:40:47 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int set)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == set)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_free(char *stash, char *buf)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	i = -1;
	j = 0;
	len = ft_strlen(buf) + ft_strlen(stash);
	join = ft_calloc(len + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (stash && stash[++i])
	{
		join[j] = stash[i];
		j++;
	}
	i = -1;
	while (buf[++i])
	{
		join[j] = buf[i];
		j++;
	}
	join[j] = '\0';
	free(stash);
	return (join);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	sum;
	size_t	i;

	if (nmemb != 0 && nmemb * size / nmemb != size)
		return (NULL);
	sum = nmemb * size;
	str = malloc(sum);
	if (!str)
		return (NULL);
	i = 0;
	while (i < sum)
		str[i++] = '\0';
	return (str);
}
