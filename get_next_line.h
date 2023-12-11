/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:54:56 by youchen           #+#    #+#             */
/*   Updated: 2023/12/11 16:22:12 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *buff);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_strdup(char *s1);
size_t ft_strlen(char *s1);
char *get_next_line(int fd);
char *ft_strchr(char *s, int c);
#endif
