/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:44:59 by igondra-          #+#    #+#             */
/*   Updated: 2022/11/05 08:36:02 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	ssize_t	read_size;
	char	*tmp;

	tmp = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	read_size = 1;
	while (read_size != 0 && (!ft_strchr(str, '\n')))
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(tmp);
			return (0);
		}
	tmp[read_size] = '\0';
	str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	line = malloc (sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_line(char *str)
{
	char	*tmp;
	int		i;
	int		count;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	tmp = malloc(sizeof (char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (0);
	count = 0;
	while (str[i])
		tmp[count++] = str[++i];
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str_save[FILES_MAX];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FILES_MAX)
		return (0);
	str_save[fd] = ft_read(fd, str_save[fd]);
	if (!str_save[fd])
		return (NULL);
	line = ft_get_line(str_save[fd]);
	str_save[fd] = ft_save_line(str_save[fd]);
	return (line);
}
