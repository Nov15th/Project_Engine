#include "YMTime.h"
namespace YM
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PreFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initailize()
	{
		//CPU 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);
		//프로그램이 시작했을때 현재 진동수
		QueryPerformanceCounter(&PreFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PreFrequency.QuadPart);
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PreFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		//static float time = 0.0f;
		//
		//time += DeltaTimeValue;
		//float fps = 1.0f / DeltaTimeValue;
		//
		//wchar_t str[50] = L"";
		//swprintf(str, 50, L"TIME : %f", time);
		//int len = wcsnlen_s(str, 50);
		//
		//
		//
		//TextOut(hdc, 0, 0, str, len);
	}
}

