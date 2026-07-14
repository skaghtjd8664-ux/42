/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:26:45 by honam             #+#    #+#             */
/*   Updated: 2026/07/09 16:13:49 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *backup)
{
	char	*temp;
	int		read_byte;

	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		else if (read_byte == 0)
			break ;
		if (!backup)
			backup = ft_strdup("");
		buf[read_byte] = '\0';
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*extract(char *backup)
{
	char	*line;
	int		i;

	if (!backup || backup[0] == '\0')
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, i + 1);
	return (line);
}

char	*update_backup(char *backup)
{
	char	*new_backup;
	int		i;

	if (!backup)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (backup[i] == '\0' || backup[i + 1] == '\0')
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i));
	if (!new_backup)
	{
		free(backup);
		return (NULL);
	}
	ft_strlcpy(new_backup, backup + i + 1, ft_strlen(backup) - i);
	free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	backup = read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!backup)
		return (NULL);
	line = extract(backup);
	backup = update_backup(backup);
	return (line);
}
