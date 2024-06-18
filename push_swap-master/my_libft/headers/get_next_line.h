/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:19:05 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/23 16:41:40 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
char		*process_buffer(char **rimane, char *buffer);
char		*ft_strdup_with_free(char **s);
char		*handle_read(char **rimane, char *buffer);
int			check_buffer(char *buffer, int *i);
char		*ft_strjoin_with_free(char **s1, char *s2);

#endif
