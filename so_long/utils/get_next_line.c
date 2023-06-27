/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:12:58 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/25 19:08:34 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Continue by getting the next line
static char	*ft_next_line(char *save_text)
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
static char	*ft_del_extra(char *text)
{
	char	*lines;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	lines = ft_calloc((i + 2), sizeof(char));
	if (!lines)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		lines[i] = text[i];
		i++;
	}
	if (text[i] == '\n' && text[i])
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
static char	*ft_readline(int fd, char *text)
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
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (text);
}

//Main get_next_line function
char	*get_next_line(int fd)
{
	static char	*text;
	char		*lines;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	text = ft_readline(fd, text);
	if (!text)
		return (NULL);
	lines = ft_del_extra(text);
	text = ft_next_line(text);
	return (lines);
}
