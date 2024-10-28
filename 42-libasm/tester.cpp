#include <iostream>
#include <string.h>
#include "headers/libasm.h"

int main() {

	std::cout << "=======================================================" << std::endl;
	std::cout << "                        FT_STRLEN                      " << std::endl;
	std::cout << "=======================================================\n" << std::endl;
	char *str = "Assembly";	
	size_t len = ft_strlen(str);
	size_t len_original = strlen(str);
	
	std::cout << "Valid string tester" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "My ft_strlen: " << len << std::endl;
	std::cout << "Original strlen: " << len_original << std::endl;

	char *str_null = NULL;
	len = ft_strlen(str_null);
	// len_original = strlen(str_null);

	std::cout << std::endl;
	std::cout << "Null string tester" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "My ft_strlen: " << len << std::endl;
	// std::cout << "Original strlen: " << len_original << std::endl;
	std::cout << std::endl;

	std::cout << "=======================================================" << std::endl;
	std::cout << "                        FT_STRCPY                      " << std::endl;
	std::cout << "=======================================================" << std::endl;	
	std::cout << std::endl;

	char dest[20];
	char src[] = "Heitor";
	char dest_original[20];
	char src_original[] = "Heitor";

	ft_strcpy(dest, src);
	strcpy(dest_original, src_original);

	std::cout << "Valid string tester" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "My ft_strcpy: String: " << src << " copy into dest: " << dest << std::endl;
	std::cout << "Original strcpy: String: " << src_original << " copy into dest: " << dest_original << std::endl;
	std::cout << "=======================================================\n" << std::endl;

	exit (0);
}