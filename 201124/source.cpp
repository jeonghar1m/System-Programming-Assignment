#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>
#include <time.h>
using namespace std;

#define NUMBER_AMOUNT 30

#pragma warning(disable:4996)

ofstream fout;
ifstream fin;

HANDLE hSemaphore;

DWORD WINAPI CalculateProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD total = 0;


	for (DWORD i = 0; i < 10; i++)
		total += *(nPtr + i);

	return total;
}

DWORD WINAPI OutputProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;
	DWORD no = 0;

	no = *nPtr;

	return no;
}

int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadID[3];
	HANDLE hThread[3];
	HANDLE hThreadOutput[NUMBER_AMOUNT];

	DWORD paramThread[30] = {};
	DWORD total = 0;
	float average = 0.0f;
	DWORD result = 0;

	int select = 0;

	time_t now = time(NULL);
	struct _stat buf;	//파일 정보 구조체
	struct tm* lt;
	char filename[] = "data.dat";
	_stat(filename, &buf);	//buf에 filename 대입
	lt = localtime(&now);

	// 세마포어 생성.
	hSemaphore = CreateSemaphore(
		NULL,    // 디폴트 보안관리자.
		NUMBER_AMOUNT,      // 세마포어 초기 값.
		NUMBER_AMOUNT,      // 세마포어 최대 값.
		NULL     // unnamed 세마포어 구성.
	);
	if (hSemaphore == NULL)
	{
		_tprintf(_T("CreateSemaphore error: %d\n"), GetLastError());
	}

	cout << "메뉴를 선택하세요. 1. 입력 후 내보냄, 2. 불러오기" << endl;
	cout << "입력: ";
	cin >> select;
	cout << "--------------------------------------------" << endl;

	switch (select)
	{
	case 1:
	{
		//값 입력
		printf("30개의 값을 입력하시오.\n");
		for (int i = 0; i < NUMBER_AMOUNT; i++)
		{
			printf("%d번째 값: ", i + 1);
			scanf("%d", &paramThread[i]);
		}

		fout.open("data.dat");

		for (int i = 0; i < NUMBER_AMOUNT; i++)
		{
			hThreadOutput[i] =
				CreateThread(
				NULL, 0,
				OutputProc,
				(LPVOID)(&paramThread[i]),
				0, 0
			);

			if (hThreadOutput[i] == NULL)
			{
				_tprintf(_T("Thread creation fault! \n"));
				return -1;
			}
		}

		for (int i = 0; i < NUMBER_AMOUNT; i++)
		{
			ResumeThread(hThreadOutput[i]);
		}

		WaitForMultipleObjects(3, hThreadOutput, TRUE, INFINITE);

		for (int i = 0; i < NUMBER_AMOUNT; i++)
		{
			GetExitCodeThread(hThreadOutput[i], &result);
			fout << result << endl;
		}

		for (int i = 0; i < NUMBER_AMOUNT; i++)
			CloseHandle(hThreadOutput[i]);

		CloseHandle(hSemaphore);

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

		average = total / 30.0f;

		cout << "파일 접근 시간: " << lt->tm_year + 1900 << "년 " << lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 " << lt->tm_hour << ":" << lt->tm_min << endl;
		for (int i = 0; i < NUMBER_AMOUNT; i++)
			cout<< paramThread[i] << ' ';
		cout << endl;
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