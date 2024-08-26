#include "peApplication.h"
#include "YMInput.h"
#include "YMTime.h"

namespace YM
{
	Application::Application() :
		mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(NULL),
		mBackBitmap(NULL)

	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);


		RECT rect = {0,0,width,height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth ,mHeight , 0);
		ShowWindow(mHwnd, true);


		//������ �ػ󵵿� �´� ����� ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		//���� ������ ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initailize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		mPlayer.Updata();

	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		//�� ���ۿ� �ִ°��� ���� ���ۿ� ����(�׷��ش�)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}