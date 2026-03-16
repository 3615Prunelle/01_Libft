/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schappuy <schappuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:07:11 by schappuy          #+#    #+#             */
/*   Updated: 2026/03/16 17:01:40 by schappuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
# include <stdarg.h>
# include <stdint.h>

# define HEXA_MIN "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"

typedef struct s_list
{
	void *content;
	struct s_list *next;
}		t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(unsigned char c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int constante, size_t taille);
void	ft_bzero(void *str, size_t siz);
void	*ft_memcpy(void *dest, const void *srce, size_t siz);
void	*ft_memmove(void *dest, const void *srce, size_t siz);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *srce, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Bonus functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	del(void *param);

// ft_printf
void			ft_printf(const char *string, ...);
void			ft_dprintf(int fd, const char *string, ...);
int				print_to_fd(int fd, const char *string, va_list ptr_string);
int				specifiers_call(int fd, char c, va_list ptr_string);
int				c_specifier(int fd, char c);
int				s_specifier(int fd, char *c);
int				d_and_i_specifier(int fd, int i);
unsigned int	u_specifier(int fd, unsigned int i);
int				p_specifier(int fd, void *p);
int				x_specifier(int fd, unsigned long long i, char *hexa);

// get_next_line
char	*get_next_line(int fd);
void	read_line(int fd, char **buffer, char **line, char **temp);
void	*ft_calloc_copy(size_t nmemb, size_t size);
void	*ft_memset_copy(void *str, int constante, size_t taille);
size_t	ft_strlen_copy(const char *str);
char	*ft_strchr_mod(const char *s, int c);
char	*ft_strlcpy_copy(char *dst, const char *src, size_t size);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*free_null_three(char **buff, char **line, char **temp);

#endif
