/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:39:28 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/03 12:10:57 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Almaceno con buffer_text la cantidad de texto que tiene
que leer, rellenándolo con '\0' como un calloc.*/
char	*ft_read_and_buff(int fd, char *text_asked)
{
	char	*buffer_text;
	int		rd_byte;

	buffer_text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_text)
		return (NULL);
	rd_byte = 1;
	while (!ft_strchr(text_asked, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, buffer_text, BUFFER_SIZE);
		if (rd_byte < 0)
		{
			free(buffer_text);
			return (NULL);
		}
		buffer_text[rd_byte] = '\0';
		if (!text_asked)
		{
			text_asked = (char *)malloc(1 * sizeof(char));
			text_asked[0] = '\0';
		}
		text_asked = ft_strjoin(text_asked, buffer_text);
	}
	free(buffer_text);
	return (text_asked);
}

/*Recorro en un while text_read buscando las líneas '\n'
o el final para guardar y que lo enseñe en mem_line*/
char	*ft_get_line(char *text_asked)
{
	char	*mem_line;
	int		i;

	i = 0;
	if (!text_asked[i])
		return (NULL);
	while (text_asked[i] && text_asked[i] != '\n')
		i++;
	mem_line = malloc(sizeof(char) * (i + 2));
	if (!mem_line)
		return (NULL);
	i = 0;
	while (text_asked[i] != '\n' && text_asked[i])
	{
		mem_line[i] = text_asked[i];
		i++;
	}
	if (text_asked[i] == '\n')
	{
		mem_line[i] = '\n';
		i++;
	}
	mem_line[i] = '\0';
	return (mem_line);
}

/*Si sobraron bytes tenemos que almacenarlo para la
siguiente llamada ya que debe recordar qué había tras
el '\n' (next_text) Para ello next_text será la resta entre
text_asked (que tenía todo
lo que pidieron leer) - la posición donde se quedó el '\n' [i]
+ 1 (para que cuente el '\n')*/

char	*ft_next_text_asked(char *text_asked)
{
	char	*next_text;
	int		i;
	int		j;

	i = 0;
	while (text_asked[i] && text_asked[i] != '\n')
		i++;
	if (!text_asked[i])
	{
		free(text_asked);
		return (NULL);
	}
	next_text = (char *)malloc(sizeof(char) *(ft_strlen(text_asked) - i + 1));
	if (!next_text)
		return (NULL);
	i++;
	j = 0;
	while (text_asked[i] != '\0')
	{
		next_text[j++] = text_asked[i++];
	}
	next_text[j] = '\0';
	free(text_asked);
	return (next_text);
}

/*Al final libero la var estática text_asked y retorno
next_text, ya que tiene el resto de lo que leyó y no mostró*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*text_asked;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text_asked = ft_read_and_buff(fd, text_asked);
	if (!text_asked)
		return (NULL);
	line = ft_get_line(text_asked);
	text_asked = ft_next_text_asked(text_asked);
	return (line);
}
