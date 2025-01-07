/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:35:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/08 00:35:21 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
/*Includes*/
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>

/*Defining buffer_size and other macros*/

# define NEWL '\n'
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 23
# endif

/*Prototypes*/
char	*get_next_line(int fd);

/*Utils prototypes*/
size_t	ft_strlen(char *line, char specifier);
char	*ft_realloc(char *line, int size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
#endif
