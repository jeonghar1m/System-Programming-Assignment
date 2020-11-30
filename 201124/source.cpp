#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <windows.h>
#include <tchar.h>
using namespace std;

#define NUMBER_AMOUNT 30

#pragma warning(disable:4996)

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD total = 0;

	int checkNull = 0;

	if (*(nPtr + 4) == '\0')
		checkNull = 4;
	else
		checkNull = 3;

	for (int i = 0; i < checkNull; i++)
		total += *(nPtr + i);

	return total;
}


int _tmain(int argc, TCHAR* argv[])
{
	ofstream fout;
	ifstream fin;

	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[12] = {};	//����° �����带 ����ϱ� ���� �迭�� ũ�⸦ 12�� ��.
	DWORD total = 0;
	float average = 0.0f;
	DWORD result = 0;

	int no[30] = {};

	int select = 0;

	cout << "�޴��� �����ϼ���. 1. �Է�, 2. ���" << endl;
	cout << "�Է�: ";
	cin >> select;

	switch (select)
	{
	case 1:
	{
		//�� �Է�
		printf("10���� ���� �Է��Ͻÿ�.\n");
		for (int i = 0; i < NUMBER_AMOUNT; i++)
		{
			printf("%d��° ��: ", i + 1);
			scanf("%d", &no[i]);
		}

		fout.open("data.dat");

		//�Է��� ���ڵ� ���Ϸ� ������.
		for (int i = 0; i < NUMBER_AMOUNT; i++)
			fout << no[i] << endl;

		fout.close();

		break;
	}
	}

	hThread[0] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[0]),
			0, &dwThreadID[0]
		);

	hThread[1] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[3]),
			0, &dwThreadID[1]
		);

	hThread[2] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[6]),
			0, &dwThreadID[2]
		);


	if (hThread[0] == NULL || hThread[1] == NULL || hThread[2] == NULL)
	{
		_tprintf(_T("Thread creation fault! \n"));
		return -1;
	}

	WaitForMultipleObjects(3, hThread, TRUE, INFINITE);

	GetExitCodeThread(hThread[0], &result);
	total += result;

	GetExitCodeThread(hThread[1], &result);
	total += result;

	GetExitCodeThread(hThread[2], &result);
	total += result;

	average = total / 10.0f;

	_tprintf(_T("total: %d \n"), total);
	_tprintf(_T("average: %f \n"), average);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	return 0;
}