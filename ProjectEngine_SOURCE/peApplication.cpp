#include "peApplication.h"
#include "YMInput.h"
#include "YMTime.h"
#include "YMCollisionManager.h"
#include "YMSceneManager.h"
#include "YMResources.h"

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
		#pragma region ������ ���� - �����丵 ����
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
		
		#pragma endregion

		//mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initailize();
		CollisionManager::Initialize();
		SceneManager::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		//mPlayer.Updata();
		CollisionManager::Update();
		SceneManager::Update();

	}
	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128,128,128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);
		Rectangle(mBackHdc, -1, -1, 1601, 901);

		SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);

		Time::Render(mBackHdc);
		//mPlayer.Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		//�� ���ۿ� �ִ°��� ���� ���ۿ� ����(�׷��ش�)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}
}