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
		fout << "����� id: " << my_userlist.user_list[i].id << endl << "����� �̸�: " << my_userlist.user_list[i].name << endl << "���� �ð�: " << my_userlist.user_list[i].playtime << endl << "���� ���� ����: " << my_userlist.user_list[i].score << endl;

	fout.close();

	cout << endl;

	fin.open("userinform.dat");

	if (fin.fail())
	{
		cout << "���� ���� ����" << endl;
		return;
	}

	for(int i=0;i<4;i++)
		cout << "����� id: " << my_userlist.user_list[i].id << endl << "����� �̸�: " << my_userlist.user_list[i].name << endl << "���� �ð�: " << my_userlist.user_list[i].playtime << endl << "���� ���� ����: " << my_userlist.user_list[i].score << endl;

	fin.close();
}