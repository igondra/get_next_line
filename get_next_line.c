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

#include "get_next_line.h"

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
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc (sizeof(char) * (i + 2));
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
		free(str);
		return (0);
	}
	tmp = (char *)malloc(sizeof (char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (0);
	i++;
	count = 0;
	while (str[i])
		tmp[count++] = str[i++];
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str_save;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	str_save = ft_read(fd, str_save);
	if (!str_save)
		return (NULL);
	line = ft_get_line(str_save);
	str_save = ft_save_line(str_save);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*file;
	int		i;

	fd = open("file2.txt", O_RDONLY);

	while(i++ < 7)
	{	
		file = get_next_line(fd);
		printf("%s", file);
	}	
	free(file);
	close(fd);
	return (0);
} */
