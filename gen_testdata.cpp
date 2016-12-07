#include <string>
#include <iostream>
#include <cstdlib>

const int LINES = 100000;

int main ()
{
	std::cout << LINES << " " << LINES << std::endl;
	for (int i = 0; i < LINES; i++)
	{
		std::cout << rand() << " " << rand() << std::endl;
	}
	return 0;
}
