#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	time_t now = time(NULL);
	struct tm *lt = localtime(&now);

	cout << lt->tm_year + 1900 << "년 " << lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 " << lt->tm_hour << "시 " << lt->tm_min << "분 " << lt->tm_sec << "초" << endl;

	return 0;
}