/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvakasir <cvakasir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:55:51 by cvakasir          #+#    #+#             */
/*   Updated: 2022/05/10 08:34:22 by cvakasir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H "get_next_line.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  42
# endif
# include	<stdlib.h>
# include	<string.h>
# include	<stdio.h>
# include	<unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*save_for_next_call(char *buffer);
char	*find_line(char *buffer);
size_t	ft_strlen(const char *s);
char	*read_and_save(int fd, char *saved_text);
char	*ft_strchr(char *s, int c);

#endif