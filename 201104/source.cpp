#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#pragma warning(disable:4996)

static int total = 0;	//합계
static float average = 0.0f;	//평균

DWORD WINAPI ThreadProc(LPVOID lpParam)		//입력
{
	DWORD number[10] = {};
	printf("숫자를 10개 입력해주세요.\n");
	for (DWORD i = 0; i < 10; i++)
		scanf("%d", number[i]);

	return *number;
}

DWORD WINAPI ThreadProc2(LPVOID lpParam)	//출력
{

}

DWORD WINAPI ThreadProc3(LPVOID lpParam)	//합계, 평균
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
	HANDLE hThread[3];

	DWORD paramThread[] = { 1, 3, 4, 7, 8, 10 };

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
			(LPVOID)(&paramThread[2]),
			0, &dwThreadID[1]
		);

	hThread[2] =
		CreateThread(
			NULL, 0,
			ThreadProc,
			(LPVOID)(&paramThread[4]),
			0, &dwThreadID[2]
		);


	if (hThread[0] == NULL || hThread[1] == NULL || hThread[2] == NULL)
	{
		_tprintf(_T("Thread creation fault! \n"));
		return -1;
	}

	WaitForMultipleObjects(3, hThread, TRUE, INFINITE);

	_tprintf(_T("total: %d \n"), total);
	_tprintf(_T("average: %.3f\n"), average);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	return 0;
}