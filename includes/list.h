/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmpassi <cempassi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:36:31 by cedricmpa         #+#    #+#             */
/*   Updated: 2019/02/17 20:44:37 by cedricmpa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <string.h>

typedef struct		s_list{
	void			*data;
	size_t			data_size;
	struct s_list	*next;
}					t_list;

void				ft_mergesort(t_list **lst, int (*cmp)(void *, void *));
t_list				*ft_lstnew(void const *data, size_t data_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *));
void				ft_lstdelnext(t_list *current, void f(void *));
void				*ft_lstdel(t_list **alst, void (*del)(void *));
void				ft_lstpop(t_list **lst, void (*f)(void *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstmerge(t_list **alst, t_list *blst);
void				ft_lstrev(t_list **alst);
int					ft_lstaddback(t_list **alst, t_list *new);
t_list				*ft_tabtolst(char **tab);
t_list				*ft_lstfilter(t_list **lst, void *filter,\
					int (*f)(void *, void *));
t_list				*ft_lstfind(t_list *alst, void *to_find,\
					int (*f)(t_list *, void *));
int					ft_lstremove_if(t_list **lst, void *data,\
					int (*tst)(void *, void *), void (*del)(void *));
t_list				*ft_getargslst(int ac, char **av);
#endif
