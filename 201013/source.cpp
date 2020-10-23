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
	int saveYr;		//��
	int saveMon;	//��
	int saveDay;	//��
	int saveHr;		//��
	int saveMin;	//��
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
		cout << "�޴��� �������ּ���. 1. �Է�, 2. ���: ";
		cin >> select;
		switch (select)
		{
		case 1:
			for (int i = 0; i < MAX_USER; i++)
			{
				cout << "�̸�: ";
				cin >> my_userlist.User_list[i].name;
				cout << "��ȭ��ȣ: ";
				cin >> my_userlist.User_list[i].phoneNo;
				cout << "�̸���: ";
				cin >> my_userlist.User_list[i].mail;

				if (atoi(my_userlist.User_list[i].name.c_str()) != 0)	//�̸��� ���ڰ� ���ԵǾ� �ִٸ�
					throw('N');

				if (my_userlist.User_list[i].phoneNo < 0)	//��ȭ��ȣ�� ���� ������ ���
					throw my_userlist.User_list[i].phoneNo;	//����ó��

				//�ð� ����
				my_userlist.User_list[i].saveYr = lt->tm_year + 1900;
				my_userlist.User_list[i].saveMon = lt->tm_mon + 1;
				my_userlist.User_list[i].saveDay = lt->tm_mday;
				my_userlist.User_list[i].saveHr = lt->tm_hour;
				my_userlist.User_list[i].saveMin = lt->tm_min;
				//�ð� ���� ��
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
			cout << "��ȣ\t�̸�\t��ȭ��ȣ\t����\t\t\t����� �Ͻ�" << endl;
			for (int i = 0; i < MAX_USER; i++)
				cout << i + 1 << "\t" << my_userlist.User_list[i].name << "\t" << "0"<< my_userlist.User_list[i].phoneNo << "\t" << my_userlist.User_list[i].mail << "\t\t" << my_userlist.User_list[i].saveYr << "��" << my_userlist.User_list[i].saveMon << "��" << my_userlist.User_list[i].saveDay << "��" << my_userlist.User_list[i].saveHr << ":" << my_userlist.User_list[i].saveMin << endl;
			fin.close();
			break;
		}
	}
	catch (long long e)
	{
		if (e < 0)
			cout << "��ȭ��ȣ�� ���� �����Դϴ�." << endl;
		return 0;
	}
	catch (char e)
	{
		if (e == 'E')
			cout << "���� ���� ����" << endl;
		else if(e=='N')
			cout << "�̸��� ���� ���ڷ� �Ǿ� �ֽ��ϴ�." << endl;
		return 0;
	}
	return 0;
}