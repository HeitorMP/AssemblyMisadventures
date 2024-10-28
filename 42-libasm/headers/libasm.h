// headers/libasm.h
#ifndef LIBASM_H
# define LIBASM_H

# ifdef __cplusplus
extern "C" {
# endif
# include <unistd.h>

size_t		ft_strlen(const char *__s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);


# ifdef __cplusplus
}
# endif

#endif
