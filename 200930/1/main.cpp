#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	time_t now = time(NULL);
	struct tm *lt = localtime(&now);

	cout << lt->tm_year + 1900 << "�� " << lt->tm_mon + 1 << "�� " << lt->tm_mday << "�� " << lt->tm_hour << "�� " << lt->tm_min << "�� " << lt->tm_sec << "��" << endl;

	return 0;
}