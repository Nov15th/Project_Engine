#include "peApplication.h"
#include "YMInput.h"


namespace YM
{
	Application::Application() :
		mHwnd(nullptr),
		mHdc(nullptr)
		

	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPosition(0, 0);

		Input::Initailize();

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
		mPlayer.Updata();

	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
	
	}
}