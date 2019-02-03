/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:55:01 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/03 12:26:34 by cedricmpa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 4096
# define BASE_MAX 66
# include <string.h>

typedef struct		s_list{
	void			*data;
	size_t			data_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buffer{
	char			*buffer;
	unsigned int	index;
	unsigned int	room;
}					t_buffer;

typedef struct		s_file{
	int				fd;
	int				status;
	char			*str;
}					t_file;

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_llitoa(long long n);
char				*ft_ullitoa(unsigned long long int n);
long long			ft_atoll_base(char *str, char *base);
unsigned long long	ft_atoull_base(char *str, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_abs(int c);

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strupper(char *str);

void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);

void				ft_strclr(char *c);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char *c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strinsert(char **str, char c, size_t index);
size_t				ft_strcspn(const char *s, const char *charset);
size_t				ft_strspn(const char *s, const char *charset);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrev(char *str);
char				*ft_strnstr(const char *haystack, const char *needle,\
					size_t len);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *str);
void				ft_putnstr(char *str, size_t n);
int					ft_putstr_fd(char const *str, int fd);
int					ft_ringbuffer(char *str, int fd);

void				ft_mergesort(t_list **lst, int (*cmp)(void *, void *));
t_list				*ft_lstnew(void const *data, size_t data_size);
void				ft_lstdelone(t_list **alst, void (*del)(void **));
void				ft_lstdelnext(t_list *current, void f(void **));
void				*ft_lstdel(t_list **alst, void (*del)(void **));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstmerge(t_list **alst, t_list *blst);
void				ft_lstpop(t_list **lst, void (*f)(void **));
void				ft_lstrev(t_list **alst);
int					ft_lstaddback(t_list **alst, t_list *new);
t_list				*ft_tabtolst(char **tab);
t_list				*ft_lstfilter(t_list **lst, void *filter,\
					int (*f)(void *, void *));
t_list				*ft_lstfind(t_list *alst, void *to_find,\
					int (*f)(t_list *, void *));
int					ft_lstremove_if(t_list **lst, void *data,\
					int (*tst)(void *, void *), void (*del)(void **));

void				ft_freetab(char ***tab);

char				**ft_getargstab(int ac, char **av);
t_list				*ft_getargslst(int ac, char **av);
int					ft_getopt(int ac, char **av, const char *optstr);
int					ft_getdelim(const int fd, char **line, char delim);

#endif
