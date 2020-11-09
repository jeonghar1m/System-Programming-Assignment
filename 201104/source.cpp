#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#pragma warning(disable:4996)

static int total = 0;
static float average = 0.0f;

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD numOne = *nPtr;
	DWORD numTwo = *(nPtr + 1);

	total = numOne + numTwo;

	average = total / 10.0f;

	return 0; // 정상적 종료.
}


int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[10] = {};

	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 숫자: ", i + 1);
		scanf("%d", &paramThread[i]);
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

	_tprintf(_T("total: %d \n"), total);
	_tprintf(_T("average: %f \n"), average);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	return 0;
}

