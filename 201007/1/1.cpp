//1�� 2�� ��ħ.
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
typedef struct Userlist	//���� ����ü
{
	User user_list[4] = {};
}userlist;

int main()
{
	userlist my_userlist;
	ofstream fout;
	ifstream fin;

	time_t now = time(NULL);
	struct _stat buf;	//���� ���� ����ü
	struct tm* lt;

	char filename[] = "userinform.dat";
	_stat(filename, &buf);	//buf�� filename ����

	int select = 0;	//�޴� ����

	cout << "�޴��� �����ϼ���.(1. ���� �Է�, 2. ���� ���): ";
	cin >> select;
	switch (select)
	{
	case 1:
		for (int i = 0; i < 4; i++)	//4����� �Է� ����.
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
		for (int i = 0; i < 4; i++)	//4�� ���� �����͸� �״�� ���Ϸ� ������.
			fout << my_userlist.user_list[i].id << " " << my_userlist.user_list[i].name << " " << my_userlist.user_list[i].playtime << " " << my_userlist.user_list[i].score << endl;
		fout.close();
		break;
	case 2:
		fin.open("userinform.dat");

		if (fin.fail())	//�ش�Ǵ� ������ ���� ���
		{
			cout << "���� ���� ����" << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++)
			fin >> my_userlist.user_list[i].id >> my_userlist.user_list[i].name >> my_userlist.user_list[i].playtime >> my_userlist.user_list[i].score;

		for (int i = 0; i < 4; i++)
			cout << "����� id: " << my_userlist.user_list[i].id << endl << "����� �̸�: " << my_userlist.user_list[i].name << endl << "���� �ð�: " << my_userlist.user_list[i].playtime << endl << "���� ���� ����: " << my_userlist.user_list[i].score << endl;
		cout << "---------------------------------------------------------------" << endl;
		lt = localtime(&buf.st_ctime);
		cout << "���� ���� �ð�: " << lt->tm_year + 1900 << "�� " << lt->tm_mon + 1 << "�� " << lt->tm_mday << "�� " << lt->tm_hour << ":" << lt->tm_min << endl;
		lt = localtime(&buf.st_mtime);
		cout << "���� ���� �ð�: " << lt->tm_year + 1900 << "�� " << lt->tm_mon + 1 << "�� " << lt->tm_mday << "�� " << lt->tm_hour << ":" << lt->tm_min << endl;
		lt = localtime(&now);
		cout << "���� ���� �ð�: " << lt->tm_year + 1900 << "�� " << lt->tm_mon + 1 << "�� " << lt->tm_mday << "�� " << lt->tm_hour << ":" << lt->tm_min << endl;
		fin.close();
		break;
	}

	return 0;
}