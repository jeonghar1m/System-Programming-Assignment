#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#pragma warning(disable:4996)

static int total = 0;	//합계
static float average = 0.0f;	//평균

DWORD WINAPI ThreadProc(LPVOID lpParam)		//입력
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD numOne = *nPtr;
	DWORD numTwo = *(nPtr + 1);

	DWORD number[10] = {};

	for (DWORD i = numOne; i <= numTwo; i++)
		scanf("%d", number[i]);

	return *number;
}

DWORD WINAPI ThreadProc2(LPVOID lpParam)	//합계, 평균
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD numOne = *nPtr;
	DWORD numTwo = *(nPtr + 1);

	for (DWORD i = numOne; i <= numTwo; i++)
	{
		total += i;
	}

	average = total / 10.0f;

	return 0; // 정상적 종료.
}


int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadID[3];
	HANDLE hThread1[3];   //입력용
	HANDLE hThread2[3];  //합계용

	DWORD paramThread[10] = {};

	_tprintf(_T("숫자 10개를 입력해주세요. \n"));

	hThread1[0] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[0]),
			0, &dwThreadID[0]
		);

	hThread1[1] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[3]),
			0, &dwThreadID[1]
		);

	hThread1[2] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[6]),
			0, &dwThreadID[2]
		);

	for(int i=0;i<10;i++)
		_tprintf(_T("%d ", number[i]));

	hThread2[0] =
		CreateThread(
			NULL, 0,
			ThreadProc2,
			(LPVOID)(&paramThread[0]),
			0, &dwThreadID[0]
		);

	hThread2[1] =
		CreateThread(
			NULL, 0,
			ThreadProc2,
			(LPVOID)(&paramThread[3]),
			0, &dwThreadID[1]
		);

	hThread2[2] =
		CreateThread(
			NULL, 0,
			ThreadProc2,
			(LPVOID)(&paramThread[6]),
			0, &dwThreadID[2]
		);


	if (hThread1[0] == NULL || hThread1[1] == NULL || hThread1[2] == NULL)
	{
		_tprintf(_T("Thread creation fault! \n"));
		return -1;
	}

	WaitForMultipleObjects(3, hThread1, TRUE, INFINITE);
	WaitForMultipleObjects(3, hThread2, TRUE, INFINITE);

	_tprintf(_T("total: %d \n"), total);
	_tprintf(_T("average: %.3f\n"), average);

	CloseHandle(hThread1[0]);
	CloseHandle(hThread1[1]);
	CloseHandle(hThread1[2]);

	CloseHandle(hThread2[0]);
	CloseHandle(hThread2[1]);
	CloseHandle(hThread2[2]);

	return 0;
}