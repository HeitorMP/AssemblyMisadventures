#include <stdio.h>
#include <string.h>
#include <fcntl.h>
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
    ft_write(fd, "Assembly", 8);
    int a = ft_write(1, "Assembly", 2);
    printf("\n");
    int b = write(1, "Assembly", 2);
    printf("\nft_write: %d\n", a);
    printf("\nwrite: %d\n", b);


    printf("=======================================================\n");
    printf("                        FT_READ                        \n");
    printf("=======================================================\n\n");    

    char buf[20];
    ft_write(1, "Type: ", 6);
    int aa = ft_read(0, buf, 20);
    // int aa = read(0, buf, 20);
    printf("\n");
    ft_write(1, "Buffer: ", 8);
    ft_write(1, buf, 20);
    printf("Bytes read: %d", aa);


    return 0;
}
