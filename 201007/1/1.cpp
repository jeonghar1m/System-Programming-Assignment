#include <iostream>
#include <fstream>
using namespace std;

struct User
{
	char id[20];
	char name[20];
	int playtime;
	int score;
};
typedef struct Userlist
{
	User user_list[4];
}userlist;

void main()
{
	userlist my_userlist;
	ofstream fout;
	ifstream fin;
	for (int i = 0; i < 4; i++)
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
	for(int i=0;i<4;i++)
		fout << "사용자 id: " << my_userlist.user_list[i].id << endl << "사용자 이름: " << my_userlist.user_list[i].name << endl << "게임 시간: " << my_userlist.user_list[i].playtime << endl << "게임 실행 점수: " << my_userlist.user_list[i].score << endl;

	fout.close();

	cout << endl;

	fin.open("userinform.dat");

	if (fin.fail())
	{
		cout << "파일 오픈 실패" << endl;
		return;
	}

	for(int i=0;i<4;i++)
		cout << "사용자 id: " << my_userlist.user_list[i].id << endl << "사용자 이름: " << my_userlist.user_list[i].name << endl << "게임 시간: " << my_userlist.user_list[i].playtime << endl << "게임 실행 점수: " << my_userlist.user_list[i].score << endl;

	fin.close();
}