/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvakasir <cvakasir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:28:40 by cvakasir          #+#    #+#             */
/*   Updated: 2022/05/09 12:56:48 by cvakasir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *rest_text)
{
	char	*text_to_save;
	int		pos;

	pos = 42;
	text_to_save = malloc(BUFFER_SIZE + 1);
	if (!text_to_save)
		return (NULL);
	while ((ft_strchr(rest_text, '\n') == NULL) && pos != 0)
	{
		pos = read(fd, text_to_save, BUFFER_SIZE);
		if (pos == -1)
		{
			free(text_to_save);
			return (NULL);
		}
		text_to_save[pos] = '\0';
		rest_text = ft_strjoin(rest_text, text_to_save);
	}
	free(text_to_save);
	return (rest_text);
}

char	*find_line(char *rest_text)
{
	int		pos;
	char	*return_line;

	pos = 0;
	if (rest_text[pos] == '\0')
		return (NULL);
	while (rest_text[pos] != '\n' && rest_text[pos])
		pos++;
	return_line = malloc(pos + 2);
	if (!return_line)
		return (NULL);
	pos = 0;
	while (rest_text[pos] != '\n' && rest_text[pos])
	{
		return_line[pos] = rest_text[pos];
		pos++;
	}
	if (rest_text[pos] == '\n')
		return_line[pos++] = '\n';
	return_line[pos] = '\0';
	return (return_line);
}

char	*save_for_next_call(char *rest_text)
{
	char	*new_text;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rest_text[i] != '\n' && rest_text[i])
		i++;
	if (rest_text[i] == '\0')
	{
		free(rest_text);
		return (NULL);
	}
	new_text = malloc(ft_strlen(rest_text) - i + 1);
	if (!new_text)
		return (NULL);
	i++;
	while (rest_text[i])
		new_text[j++] = rest_text[i++];
	new_text[j] = '\0';
	free(rest_text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	char		*return_line;
	static char	*rest_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_text = read_and_save(fd, rest_text);
	if (!rest_text)
		return (NULL);
	return_line = find_line(rest_text);
	rest_text = save_for_next_call(rest_text);
	return (return_line);
}
