#include "YMTexture.h"
#include "peApplication.h"

extern YM::Application application;

namespace YM::graphcis
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
	{

	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		//BMP 老 版快
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			if (mBitmap == nullptr)
			{
				return S_FALSE;
			}
			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);
			mWidth = info.bmWidth;
			mHeight = info.bmWidth;

			HDC mainDC = application.GetHDC();
			mHdc = CreateCompatibleDC(mainDC);
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		//PNG 老 版快
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr)
			{
				return S_FALSE;
			}

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}


		//mImage = Gdiplus::Image::FromFile(path.c_str());
		//mWidth = mImage->GetWidth();
		//mHeight = mImage->GetHeight();
		
		return S_OK;
	}
}