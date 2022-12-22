#include "../Test/Vector_Test.h"
#include "../Test/Stack_Test.h"
#include "../Test/Map_Test.h"
#include "../Test/Set_Test.h"

int main(int argc, char **argv) {
	Vector_Test vectorTest;
	Stack_Test stackTest;
	Map_Test mapTest;
	Set_Test setTest;

	std::cout << "Vector_Test" << std::endl;
	vectorTest.run_all_tests();
	std::cout << "Stack_Test" << std::endl;
	stackTest.run_all_tests();
	std::cout << "Map_Test" << std::endl;
	mapTest.run_all_tests();
	std::cout << "Set_Test" << std::endl;
	setTest.run_all_tests();
}