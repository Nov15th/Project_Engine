#pragma once

#include "YMGameObject.h"
namespace YM
{
class Application
{
public:
	Application();
	~Application();

	void Initialize(HWND hwnd, UINT width, UINT height);
	void Run();
	void Update();
	void LateUpdate();
	void Render();
	void Destroy();
	void Release();

	HWND GetHwnd() { return mHwnd; }
	HDC GetHDC() { return mHdc; }
	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }

private:
	HWND mHwnd;
	HDC mHdc;

	HDC mBackHdc;
	HBITMAP mBackBitmap;

	UINT mWidth;
	UINT mHeight;

	

	//�÷��̾�
	//float mX;
	//float mY;
	//
	//GameObject mPlayer;
};

}