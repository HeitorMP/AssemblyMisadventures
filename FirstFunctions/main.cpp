#include <iostream>

extern "C" int		thisFunctionOnlyReturns42();
extern "C" char*	get_message();
extern "C" int*		get_numbers();
extern "C" int		get_string_length(char*);
extern "C" int 		exit_code();
extern "C" void		print_string(char*, size_t);

int main() {
	std::cout << "thisFunctionOnlyReturns42: " << thisFunctionOnlyReturns42() << std::endl;
	std::cout << "message: " << get_message() << std::endl;

	std::cout << "numbers: " << get_numbers() << std::endl;

	int *numbers = get_numbers();

	for (int i = 0; i < 5; i++) {
		std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
	}

	char *my_string = get_message();

	char *test = "Hello World";
	std::cout << "message again: " << my_string << std::endl;
	std::cout << "message size: " << get_string_length(my_string) << std::endl; // fixed string
	print_string(test, get_string_length(test));

	exit (exit_code());
}