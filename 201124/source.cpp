#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <windows.h>
#include <tchar.h>
using namespace std;

#define NUMBER_AMOUNT 30

#pragma warning(disable:4996)

ofstream fout;
ifstream fin;

DWORD WINAPI CalculateProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD total = 0;


	for (DWORD i = 0; i < 10; i++)
		total += *(nPtr + i);

	return total;
}

DWORD WINAPI InputProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;
	DWORD no[10] = {};

	for (DWORD i = 0; i < 10; i++)
	{
		printf("%d��° ��: ", i + 1);
		scanf("%d", no[i]);
		*(nPtr + i) = no[i];
	}

	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[30] = {};
	DWORD total = 0;
	float average = 0.0f;
	DWORD result = 0;

	int select = 0;

	cout << "�޴��� �����ϼ���. 1. �Է� �� ������, 2. �ҷ�����" << endl;
	cout << "�Է�: ";
	cin >> select;

	switch (select)
	{
	case 1:
	{
		//�� �Է�
		//printf("10���� ���� �Է��Ͻÿ�.\n");
		//for (int i = 0; i < NUMBER_AMOUNT; i++)
		//{
		//	printf("%d��° ��: ", i + 1);
		//	scanf("%d", &paramThread[i]);
		//}

		hThread[0] =
			CreateThread(
				NULL, 0,
				InputProc,
				(LPVOID)(&paramThread[0]),
				0, &dwThreadID[0]
			);

		hThread[1] =
			CreateThread(
				NULL, 0,
				InputProc,
				(LPVOID)(&paramThread[10]),
				0, &dwThreadID[1]
			);

		hThread[2] =
			CreateThread(
				NULL, 0,
				InputProc,
				(LPVOID)(&paramThread[20]),
				0, &dwThreadID[2]
			);

		fout.open("data.dat");

		//�Է��� ���ڵ� ���Ϸ� ������.
		for (int i = 0; i < NUMBER_AMOUNT; i++)
			fout << paramThread[i] << endl;

		fout.close();


		if (hThread[0] == NULL || hThread[1] == NULL || hThread[2] == NULL)
		{
			_tprintf(_T("Thread creation fault! \n"));
			return -1;
		}

		CloseHandle(hThread[0]);
		CloseHandle(hThread[1]);
		CloseHandle(hThread[2]);

		break;
	}
	case 2:
	{
		fin.open("data.dat");

		if (fin.fail())
		{
			cout << "������ ã�� �� �����ϴ�." << endl;
			break;
		}
		
		for (int i = 0; i < NUMBER_AMOUNT; i++)
			fin >> paramThread[i];

		hThread[0] =
			CreateThread(
				NULL, 0,
				CalculateProc,
				(LPVOID)(&paramThread[0]),
				0, &dwThreadID[0]
			);

		hThread[1] =
			CreateThread(
				NULL, 0,
				CalculateProc,
				(LPVOID)(&paramThread[10]),
				0, &dwThreadID[1]
			);

		hThread[2] =
			CreateThread(
				NULL, 0,
				CalculateProc,
				(LPVOID)(&paramThread[20]),
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

		break;
	}
	}

	return 0;
}