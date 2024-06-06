/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:50:58 by imatek            #+#    #+#             */
/*   Updated: 2024/06/06 15:09:42 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	read_char;
	t_list	*temp;
	char	*next_line;

	temp = ft_dup(buf, ); + strjoin
	next_line = copy(temp);// jusqu'au \n 
	read_char = read(fd, buf, buffer_size);
	while (!check_newline)
	{
		read_char;
		copy(buf, temp);
		++;
	}
}

// ft_ (char *buf)

// check_newline(char c);

// size_t	read(int fd, void *buf, size_t buffer_size);

// char	copy(char *buf, t_list temp)