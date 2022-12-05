/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:12:58 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/02 16:38:58 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Continue by getting the next line
char	*ft_next_line(char *save_text)
{
	int		i;
	int		j;
	int		len;
	char	*lines;

	i = 0;
	j = 0;
	while (save_text[i] && save_text[i] != '\n')
		i++;
	if (!save_text[i])
	{
		free(save_text);
		return (NULL);
	}
	len = (ft_strlen(save_text) - i + 1);
	lines = ft_calloc(len, sizeof(char));
	i++;
	while (save_text[i])
		lines[j++] = save_text[i++];
	free(save_text);
	return (lines);
}

//delete the extra text collected
char	*ft_del_extra(char *text)
{
	char	*lines;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	i = ft_strlen(text);
	lines = ft_calloc((i + 2), sizeof(char));
	if (!lines)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		lines[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		lines[i] = '\n';
	return (lines);
}

// //function free and join
char	*ft_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

//to read each part of the text
char	*ft_readline(int fd, char *text)
{
	char	*buffer;
	int		read_value;

	read_value = 1;
	if (!text)
	{
		text = ft_calloc(1, sizeof(char));
		text[0] = '\0';
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_value > 0 && !(ft_strrchr(buffer, '\n')))
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_value] = '\0';
		text = ft_free(text, buffer);
	}
	free(buffer);
	return (text);
}

//Main get_next_line function
char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX];
	char		*lines;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	text[fd] = ft_readline(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	lines = ft_del_extra(text[fd]);
	text[fd] = ft_next_line(text[fd]);
	return (lines);
}
