/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:49:22 by asemsey           #+#    #+#             */
/*   Updated: 2023/10/30 09:34:13 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 8188
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

char	*ft_strchr(char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif