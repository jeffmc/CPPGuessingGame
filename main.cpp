#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	for (int i=0;i<100;i++) {
		std::cout << rand();
	}
	std::cout << std::endl;

	int age = -1;
	while (age != 0) {
		std::cout << "What is your age? ";
		std::cin >> age;
		std::cout << std::endl << "You are " << age << " years old!" << std::endl;	
	}
	return 0;
}
