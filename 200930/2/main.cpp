#include <iostream>
#include <stdlib.h>
//using namespace std;

int main()
{
	char* getenv(const char* name);

	std::cout << "HOSNAME: " << getenv("HOSTNAME") << std::endl;

	return 0;
}