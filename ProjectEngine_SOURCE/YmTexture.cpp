#include "YMTexture.h"
#include "peApplication.h"
#include "YMResources.h"

extern YM::Application application;

namespace YM::graphcis
{
	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image != nullptr)
		{
			return image;
		}
		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHDC();
		HWND hwnd = application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(name+ L"Image", image);
		return image;
	}

	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mbAlpha(false)
	{

	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		//BMP 일 경우
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
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32)
			{
				mbAlpha = true;
			}
			else if (info.bmBitsPixel == 24)
			{
				mbAlpha = false;
			}

			HDC mainDC = application.GetHDC();
			mHdc = CreateCompatibleDC(mainDC);
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		//PNG 일 경우
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