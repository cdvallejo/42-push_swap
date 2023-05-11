/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:56:29 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/08 14:08:23 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 42

char	*ft_read_and_buff(int fd, char *text_asked);
char	*ft_next_text_asked(char *text_asked);
char	*ft_get_line(char *all_txt);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
