/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:50:58 by imatek            #+#    #+#             */
/*   Updated: 2024/06/13 22:28:34 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		nb_read;

	nb_read = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (nb_read != 0 && (!(ft_strchr(buf, '\n'))))
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
		{
			if (stash)
				free(stash);
			return (free(buf), NULL);
		}
		buf[nb_read] = '\0';
		stash = ft_strjoin_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free (buf);
	if (!nb_read && !stash[0])
		return (free(stash), NULL);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	dest = ft_calloc((i + 2), sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		dest[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		dest[i] = stash[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_new(char *stash)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	dest = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!dest)
		return (NULL);
	if (stash[i])
		i++;
	j = 0;
	while (stash[i])
	{
		dest[j] = stash[i++];
		j++;
	}
	dest[j] = '\0';
	free (stash);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new(stash);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*res;
// 	int		i;

// 	i = 1;
// 	fd = open("read_error.txt", O_RDONLY);
// 	res = get_next_line(fd);
// 	printf("line %d: %s\n", i++, res);
// 	while (res)
// 	{
// 		free(res);
// 		res = get_next_line(fd);
// 		printf("line %d: %s\n", i, res);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }

// free stash end of file : eof => '\0'
// if (ft_strchr(buf, '\n'))
// 		break ;

// nb_read = 0; si fin de fichier
// nb_read != 0; en lecture

// // 1/ read(fd, buf, buffer_size)
// copy de buf dans stash 
// 3/ check_newline
// 4/ si buffer_size > \n 
// 	afficher et clear jusqua \n 
// 5/ si buffer_size < \n
// 	join a chaque tour 
// et revenir a 4
// 6/ gerer si fin de fichier
// 7/ size jusqua \n pour malloc