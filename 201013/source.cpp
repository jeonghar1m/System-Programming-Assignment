#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <time.h>
using namespace std;
#define MAX_USER 5
struct User
{
	string name;
	long long phoneNo;
	char mail[30];
	int saveYr;		//년
	int saveMon;	//월
	int saveDay;	//일
	int saveHr;		//시
	int saveMin;	//분
};
typedef struct Userlist
{
	User User_list[MAX_USER] = {};
}userlist;

int main()
{
	userlist my_userlist;
	ofstream fout;
	ifstream fin;

	time_t now = time(NULL);
	struct tm* lt = localtime(&now);

	int select = 0;
	int userSelect = 0;

	try
	{
		cout << "메뉴를 선택해주세요. 1. 입력, 2. 출력: ";
		cin >> select;
		switch (select)
		{
		case 1:
			for (int i = 0; i < MAX_USER; i++)
			{
				cout << "이름: ";
				cin >> my_userlist.User_list[i].name;
				cout << "전화번호: ";
				cin >> my_userlist.User_list[i].phoneNo;
				cout << "이메일: ";
				cin >> my_userlist.User_list[i].mail;

				if (atoi(my_userlist.User_list[i].name.c_str()) != 0)	//이름에 숫자가 포함되어 있다면
					throw('N');

				if (my_userlist.User_list[i].phoneNo < 0)	//전화번호의 값이 음수일 경우
					throw my_userlist.User_list[i].phoneNo;	//예외처리

				//시간 저장
				my_userlist.User_list[i].saveYr = lt->tm_year + 1900;
				my_userlist.User_list[i].saveMon = lt->tm_mon + 1;
				my_userlist.User_list[i].saveDay = lt->tm_mday;
				my_userlist.User_list[i].saveHr = lt->tm_hour;
				my_userlist.User_list[i].saveMin = lt->tm_min;
				//시간 저장 끝
			}

			fout.open("userinform.dat");
			for(int i=0;i<MAX_USER;i++)
				fout << my_userlist.User_list[i].name << " " << my_userlist.User_list[i].phoneNo << " " << my_userlist.User_list[i].mail << " " << my_userlist.User_list[i].saveYr << " " << my_userlist.User_list[i].saveMon << " " << my_userlist.User_list[i].saveDay << " " << my_userlist.User_list[i].saveHr << " " << my_userlist.User_list[i].saveMin << endl;
			fout.close();
			break;
		case 2:
			fin.open("userinform.dat");

			if (fin.fail())
			{
				throw('E');
			}
			for (int i = 0; i < MAX_USER; i++)
				fin >> my_userlist.User_list[i].name >> my_userlist.User_list[i].phoneNo >> my_userlist.User_list[i].mail >> my_userlist.User_list[i].saveYr >> my_userlist.User_list[i].saveMon >> my_userlist.User_list[i].saveDay >> my_userlist.User_list[i].saveHr >> my_userlist.User_list[i].saveMin;
			cout << "번호\t이름\t전화번호\t메일\t\t\t저장된 일시" << endl;
			for (int i = 0; i < MAX_USER; i++)
				cout << i + 1 << "\t" << my_userlist.User_list[i].name << "\t" << "0"<< my_userlist.User_list[i].phoneNo << "\t" << my_userlist.User_list[i].mail << "\t\t" << my_userlist.User_list[i].saveYr << "년" << my_userlist.User_list[i].saveMon << "월" << my_userlist.User_list[i].saveDay << "일" << my_userlist.User_list[i].saveHr << ":" << my_userlist.User_list[i].saveMin << endl;
			fin.close();
			break;
		}
	}
	catch (long long e)
	{
		if (e < 0)
			cout << "전화번호의 값이 음수입니다." << endl;
		return 0;
	}
	catch (char e)
	{
		if (e == 'E')
			cout << "파일 오픈 실패" << endl;
		else if(e=='N')
			cout << "이름의 값이 숫자로 되어 있습니다." << endl;
		return 0;
	}
	return 0;
}