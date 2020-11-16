#include <stdio.h>
#include <windows.h>
#include <tchar.h>

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
	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[12] = {};	//세번째 쓰레드를 사용하기 위해 배열의 크기를 12로 둠.
	DWORD total = 0;
	DWORD result = 0;

	printf("10개의 값을 입력하시오.\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 값: ", i + 1);
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

	GetExitCodeThread(hThread[0], &result);
	total += result;

	GetExitCodeThread(hThread[1], &result);
	total += result;

	GetExitCodeThread(hThread[2], &result);
	total += result;

	_tprintf(_T("total: %d \n"), total);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	return 0;
}