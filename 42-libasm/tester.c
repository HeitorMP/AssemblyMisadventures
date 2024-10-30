#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "headers/libasm.h"

int main() {
    printf("=======================================================\n");
    printf("                        FT_STRLEN                      \n");
    printf("=======================================================\n\n");

    char *str = "Assembly";    
    size_t len = ft_strlen(str);
    size_t len_original = strlen(str);
    
    printf("Valid string tester\n");
    printf("-------------------------------------------------------\n");
    printf("My ft_strlen: %zu\n", len);
    printf("Original strlen: %zu\n", len_original);
    printf("\n");

    printf("=======================================================\n");
    printf("                        FT_STRCPY                      \n");
    printf("=======================================================\n\n");    

    char dest[20];
    char src[] = "Heitor";
    char dest_original[20];
    char src_original[] = "Heitor";

    ft_strcpy(dest, src);
    strcpy(dest_original, src_original);

    printf("Valid string tester\n");
    printf("-------------------------------------------------------\n");
    printf("My ft_strcpy: String: %s copy into dest: %s\n", src, dest);
    printf("Original strcpy: String: %s copy into dest: %s\n\n", src_original, dest_original);

    char dest1[2];
    char src1[] = "heitor";
    printf("=======================================================\n\n");

    char dest_original1[2];
    char src_original1[] = "heitor";
    ft_strcpy(dest1, src1);
    strcpy(dest_original1, src_original1);

    printf("No space on dest string tester\n");
    printf("-------------------------------------------------------\n");
    printf("My ft_strcpy: String: %s copy into dest: %s\n", src1, dest1);
    printf("Original strcpy: String: %s copy into dest: %s\n", src_original1, dest_original1);
    printf("\n");


    printf("=======================================================\n");
    printf("                        FT_STRCMP                      \n");
    printf("=======================================================\n\n");    

    char test_ft_strcmp1[] = "aa";
    char test_ft_strcmp2[] = "aaz";
    char test_strcmp_original1[] = "aa";
    char test_strcmp_original2[] = "aaz";

    int ft_strcmp_result = ft_strcmp(test_ft_strcmp1, test_ft_strcmp2);
    int strcmp_origninal_result = strcmp(test_strcmp_original1, test_strcmp_original2);

    printf("Valid string tester\n");
    printf("-------------------------------------------------------\n");
    printf("My ft_strcmp: %i\n", ft_strcmp_result);
    printf("Original strcmp: %i\n", strcmp_origninal_result);


    printf("=======================================================\n");
    printf("                        FT_WRITE                       \n");
    printf("=======================================================\n\n");    

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // to file
    int my_return = ft_write(fd, "This was insert by ft_write\n", 28);
    int original_return =  write(fd, "This was insert by original\n", 28);

    printf("Check output.txt\n");
    printf("my ft_write return: %d\n", my_return);
    printf("original write return: %d\n", original_return);

    // to stdout
    my_return = ft_write(0, "Assembly", 2);
    printf("\n");
    original_return = write(0, "Assembly", 2);
    printf("\n");
    printf("my ft_write return: %d\n", my_return);
    printf("original write return: %d\n", original_return);
    
    // erro invalid fd
    my_return = ft_write(10, "Assembly", 2);
    original_return = write(10, "Assembly", 2);
    if (my_return == -1) {
        perror("ft_write error");
        printf("ft_write errno: %d\n", errno);
    }
    if (original_return == -1) {
        perror("original write error");
        printf("original write errno: %d\n", errno);
    }
    close(fd);

    printf("=======================================================\n");
    printf("                        FT_READ                        \n");
    printf("=======================================================\n\n");    

    char buf[20];
    bzero(buf, 20);
    ft_write(1, "Type for ft_read: ", 18);
    my_return = ft_read(0, buf, 20);
    ft_write(1, "Type for original read: ", 24);
    bzero(buf, 20);
    original_return = read(0, buf, 20);
    printf("my ft_read return: %d\n", my_return);
    printf("original read return: %d\n", original_return);

    // read from file
    fd = open("output.txt", O_RDONLY);
    char file_buf[20];
    bzero(file_buf, 20);
    my_return = ft_read(fd, file_buf, 20);
    printf("my ft_read from file output.txt: %s\nbytes read: %d\n", file_buf, my_return);
    bzero(file_buf, 20);
    close(fd);
    fd = open("output.txt", O_RDONLY);
    original_return = read(fd, file_buf, 20);
    printf("original read from file output.txt: %s\nbytes read: %d\n", file_buf, original_return);
    close(fd);
    // erro invalid fd

    bzero(buf, 20);
    my_return = ft_read(10, buf, 20);
    bzero(buf, 20);
    original_return = read(10, buf, 20);
    if (my_return == -1) {
        perror("ft_read error");
        printf("ft_read errno: %d\n", errno);
    }
    if (original_return == -1) {
        perror("original read error");
        printf("original read errno: %d\n", errno);
    }


    printf("=======================================================\n");
    printf("                        FT_STRDUP                      \n");
    printf("=======================================================\n\n");  


    char *src_strdup = "test";
    char *new_strdup = ft_strdup(src_strdup);


    printf("Original string: %s - address: %p\n", src_strdup, src_strdup);
    printf("New string: %s - address: %p\n", new_strdup, new_strdup);

    free(new_strdup);

    return 0;
}
