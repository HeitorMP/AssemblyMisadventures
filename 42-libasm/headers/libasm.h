// headers/libasm.h
#ifndef LIBASM_H
# define LIBASM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

# include <unistd.h>

size_t		ft_strlen(const char *__s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t 	ft_read(int fd, void *buf, size_t count);
char 		*ft_strdup(const char *s);
ssize_t	    ft_list_size(t_list *begin_list);

# ifdef __cplusplus
}
# endif

#endif
