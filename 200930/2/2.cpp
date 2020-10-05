#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	cout << "Computer Name: " << getenv("COMPUTERNAME") << endl;

	return 0;
}