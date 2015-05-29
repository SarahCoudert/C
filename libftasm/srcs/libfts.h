/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:48:12 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/28 13:50:25 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_bzero(char *s, int size);
char	*ft_strcat(char *s, char *s2);
void	ft_puts(char *s);
size_t	ft_strlen(char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strdup(char *s1);
void	ft_cat(int fd);
int		ft_isxdigit(int c);
char*	ft_strnew(int size);
int		ft_islower(int c);
int		ft_isupper(int c);

#endif
