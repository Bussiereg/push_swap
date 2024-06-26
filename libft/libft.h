/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:50:42 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 13:20:21 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);	
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_atoi(const char *str);
char			*ft_strdup(char *src);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(int));
void			ft_lstclear(t_list **lst, void (*del)(int));
void			ft_lstiter(t_list *lst, void (*f)(int));
t_list			*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));

int				ft_printf(const char *format, ...);
int				pf_put_u(unsigned int nb);
int				pf_put_x(unsigned int nb, char *base);
int				pf_put_xmaj(unsigned int nb, char *base);
int				pf_put_char(char c);
int				pf_put_str(char *str);
int				pf_put_nbr(int nb);
int				pf_put_ptr(void *ptr, char *base);

char			*get_next_line(int fd);
unsigned int	gnl_strlen(const char *str);
int				check_new_line(char	*str);
char			*gnl_newline(int fd, char *save);
char			*gnl_strjoin(char const *s1, char const *s2,
					unsigned int size_add);
char			*gnl_read(char *read_save, char *result, int fd);
void			*gnl_free(char *str1, char *str2);

#endif
