/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:50:58 by imatek            #+#    #+#             */
/*   Updated: 2024/06/10 21:01:29 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		nb_read;

	nb_read = -1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (nb_read != 0 && (!(ft_strchr(buf, '\n'))))
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		buf[nb_read] = '\0';
		printf("buf->%s\n", buf);
		stash = ft_strjoin_free(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_line(char *dest, char *stash)
{
	size_t	i;

	if (!stash && !dest)
		return (NULL);
	dest = ft_calloc((ft_strlen(stash) + 1), sizeof(char));
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
	free (stash);
	return (dest);
}

char	*ft_new(char *stash)
{
	size_t	i;
	char	*dest;

	dest = NULL;
	if (!stash && !dest)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	dest = ft_calloc((ft_strlen(stash) + i + 1), sizeof(char));
	while (stash[i] == '\n' && stash[i + 1] != '\n')
	{
		dest[i] = stash[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*temp;

	temp = NULL;
	stash = ft_read(fd, stash);
	printf("stash->%s\n", stash);
	line = get_line(temp, stash);
	printf("line->%s\n", line);
	stash = ft_new(stash);
	printf("stash->%s\n", stash);
	return (stash);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("file.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("res->%s\n", res);
	res = get_next_line(fd);
	printf("res->%s\n", res);
	return (0);
}

// free stash end of file : eof => '\0'
// if (ft_strchr(buf, '\n'))
	// 	break ;
//nb_read = 0; si fin de fichier
//nb_read != 0; en lecture

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