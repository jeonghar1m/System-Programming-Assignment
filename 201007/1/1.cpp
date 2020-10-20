//1번 2번 합침.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
using namespace std;

struct User
{
	char id[20];
	char name[20];
	int playtime;
	int score;
};
typedef struct Userlist	//하위 구조체
{
	User user_list[4] = {};
}userlist;

int main()
{
	userlist my_userlist;
	ofstream fout;
	ifstream fin;

	time_t now = time(NULL);
	struct _stat buf;	//파일 정보 구조체
	struct tm* lt;

	char filename[] = "userinform.dat";
	_stat(filename, &buf);	//buf에 filename 대입

	int select = 0;	//메뉴 선택

	cout << "메뉴를 선택하세요.(1. 파일 입력, 2. 파일 출력): ";
	cin >> select;
	switch (select)
	{
	case 1:
		for (int i = 0; i < 4; i++)	//4명까지 입력 받음.
		{
			cout << "ID: ";
			cin >> my_userlist.user_list[i].id;
			cout << "Name: ";
			cin >> my_userlist.user_list[i].name;
			cout << "Playtime: ";
			cin >> my_userlist.user_list[i].playtime;
			cout << "Score: ";
			cin >> my_userlist.user_list[i].score;
		}

		fout.open("userinform.dat");
		for (int i = 0; i < 4; i++)	//4명에 대한 데이터를 그대로 파일로 내보냄.
			fout << my_userlist.user_list[i].id << " " << my_userlist.user_list[i].name << " " << my_userlist.user_list[i].playtime << " " << my_userlist.user_list[i].score << endl;
		fout.close();
		break;
	case 2:
		fin.open("userinform.dat");

		if (fin.fail())	//해당되는 파일이 없을 경우
		{
			cout << "파일 오픈 실패" << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++)
			fin >> my_userlist.user_list[i].id >> my_userlist.user_list[i].name >> my_userlist.user_list[i].playtime >> my_userlist.user_list[i].score;

		for (int i = 0; i < 4; i++)
			cout << "사용자 id: " << my_userlist.user_list[i].id << endl << "사용자 이름: " << my_userlist.user_list[i].name << endl << "게임 시간: " << my_userlist.user_list[i].playtime << endl << "게임 실행 점수: " << my_userlist.user_list[i].score << endl;
		cout << "---------------------------------------------------------------" << endl;
		lt = localtime(&buf.st_ctime);
		cout << "파일 생성 시간: " << lt->tm_year + 1900 << "년 " << lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 " << lt->tm_hour << ":" << lt->tm_min << endl;
		lt = localtime(&buf.st_mtime);
		cout << "최종 수정 시간: " << lt->tm_year + 1900 << "년 " << lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 " << lt->tm_hour << ":" << lt->tm_min << endl;
		lt = localtime(&now);
		cout << "파일 접근 시간: " << lt->tm_year + 1900 << "년 " << lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 " << lt->tm_hour << ":" << lt->tm_min << endl;
		fin.close();
		break;
	}

	return 0;
}