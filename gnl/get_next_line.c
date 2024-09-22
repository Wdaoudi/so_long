/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:11:39 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/22 19:29:28 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_line(char *string)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	tmp = ft_substr(string, 0, i + 1);
	return (tmp);
}

char	*ft_save(char *string)
{
	int		i;
	char	*tmp;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	tmp = ft_substr(string, i + 1, ft_strlen(string));
	free(string);
	return (tmp);
}

char	*ft_read_fd(int fd, char *string)
{
	char	*buffer;
	int		res;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	res = 1;
	while (!ft_strchr(string, '\n') && res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (free(buffer), free(string), NULL);
		buffer[res] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	string = ft_read_fd(fd, string);
	if (!string)
		return (NULL);
	line = ft_line(string);
	string = ft_save(string);
	return (line);
}

// int main()
// {
//     int fd;
//     char *line;

//     // Ouvrir un fichier
//     fd = open("maps.ber", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Erreur lors de l'ouverture du fichier\n");
//         return 1;
//     }

//     // Lire et afficher chaque ligne
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);  // N'oubliez pas de libérer la mémoire allouée par get_next_line
//     }

//     // Fermer le fichier
//     close(fd);

//     return 0;
// }