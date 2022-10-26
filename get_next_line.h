/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:44:59 by igondra-          #+#    #+#             */
/*   Updated: 2022/10/26 22:44:59 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* # define BUFFER_SIZE 5 */

/* get_next_line.c */
char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif

// Cosas para hacer antes de entregar:
//  Si queremos, cambiar las funciones del utils a nuestras funciones de libft
//  Chequear con valgrind que no hay leaks de memoria
//  Hacer un último chequeo, por supuesto
//  No hace falta Makefile
//  Animo y a por el Black Hole!!