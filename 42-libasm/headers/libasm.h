// headers/libasm.h
#ifndef LIBASM_H
# define LIBASM_H

# ifdef __cplusplus
extern "C" {
# endif
# include <stddef.h>

size_t		ft_strlen(const char *__s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);


# ifdef __cplusplus
}
# endif

#endif
