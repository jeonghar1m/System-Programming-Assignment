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


	for (int i = 0; i < 10; i++)
		total += *(nPtr + i);

	return total;
}


int _tmain(int argc, TCHAR* argv[])
{
	ofstream fout;
	ifstream fin;

	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[30] = {};
	DWORD total = 0;
	float average = 0.0f;
	DWORD result = 0;

	int select = 0;

	cout << "메뉴를 선택하세요. 1. 입력, 2. 출력" << endl;
	cout << "입력: ";
	cin >> select;

	switch (select)
	{
	case 1:
	{
		//값 입력
		printf("10개의 값을 입력하시오.\n");
		for (int i = 0; i < NUMBER_AMOUNT; i++)
		{
			printf("%d번째 값: ", i + 1);
			scanf("%d", &paramThread[i]);
		}

		fout.open("data.dat");

		//입력한 숫자들 파일로 내보냄.
		for (int i = 0; i < NUMBER_AMOUNT; i++)
			fout << paramThread[i] << endl;

		fout.close();

		break;
	}
	case 2:
	{
		fin.open("data.dat");

		if (fin.fail())
		{
			cout << "파일을 찾을 수 없습니다." << endl;
			break;
		}
		
		for (int i = 0; i < NUMBER_AMOUNT; i++)
			fin >> paramThread[i];

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
				(LPVOID)(&paramThread[10]),
				0, &dwThreadID[1]
			);

		hThread[2] =
			CreateThread(
				NULL, 0,
				ThreadProc,
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