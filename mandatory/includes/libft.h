/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/12/10 13:57:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_append_char(char *str, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
bool	ft_isblank(unsigned char c);
int		ft_isprint(int arg);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Linked list oriented functions */
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Libft extended additional functions */
int		ft_isempty(const char *str);
int		ft_checkext(const char *str, const char *ext);
int		ft_checkfile(const char *file);
int		ft_getfile_size(int fd);
int		ft_chr_in_set(char c, const char *set);
char	**ft_doublestrdup(char **str);
int		ft_doublestrlen(char **str);
int		ft_doublefree(char **str);
void	ft_doubleprint(char **str);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split_in_set(char const *s, char *set);
char	*ft_str_replace(char *src, char const *replace);

//Get Next Line
char	*get_next_line(int fd);
char	*ft_read_static(int fd, char *final);
char	*ft_final_rtn(char *final);
char	*ft_clean_final(char *final);
char	*ft_strjoin_gnl(char *final, char *rd);
char	*ft_strchr_gnl(char *str, int c);

size_t	ft_strlen_gnl(char *str);
//Printf
void	ft_type(char t, va_list args, int *num);
void	ft_putchar_c(char c, int *num);
void	ft_putstr_s(char *str, int *num);
void	ft_putnbr_di(int nb, int *num);
void	ft_putnbr_u(unsigned int nb, int *num);
void	ft_puthexa_x(unsigned long int n, int *num);
void	ft_puthexa_xx(unsigned long int n, int *num);
int		printerr(const char *str, ...);
#endif
