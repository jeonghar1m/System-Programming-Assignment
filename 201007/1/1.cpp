//1�� 2�� ��ħ.
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
typedef struct Userlist	//���� ����ü
{
	User user_list[4] = {};
}userlist;

int main()
{
	userlist my_userlist;
	ofstream fout;
	ifstream fin;
	int select = 0;
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
		for(int i=0;i<4;i++)	//4�� ���� �����͸� �״�� ���Ϸ� ������.
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
		for(int i=0;i<4;i++)
			cout << "����� id: " << my_userlist.user_list[i].id << endl << "����� �̸�: " << my_userlist.user_list[i].name << endl << "���� �ð�: " << my_userlist.user_list[i].playtime << endl << "���� ���� ����: " << my_userlist.user_list[i].score << endl;

		fin.close();
		break;
	}

	return 0;
}