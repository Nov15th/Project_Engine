#include "YMAnimation.h"
#include "YMTime.h"
#include "YMTransform.h"
#include "YMGameObject.h"
#include "YMAnimator.h"
#include "YMRenderer.h"
//#include "YMCamera.h"
#include "YMTexture.h"
namespace YM
{
	Animation::Animation()
		:Resource(enums::eResourceType::Animation)
		,mAnimator(nullptr) 
		,mTexture(nullptr)
		, mAnimationSheet{}
		,mIndex(-1)
		,mTime(0.0f)
		,mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (mbComplete)
		{
			return;
		}
		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0;
			if (mIndex < mAnimationSheet.size()-1)
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
		//알파블랜드 사용조건 : 해당이미지에 알파 채널이 필요
		//AlphaBlend();

		if (mTexture == nullptr)
		{
			return;
		}

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
		{
			pos = renderer::mainCamera->CalulatePosition(pos);
		}


		Sprite sprite = mAnimationSheet[mIndex];
		graphcis::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphcis::Texture::eTextureType::Bmp)
		{
			

			//
			HDC imgHDC = mTexture->GetHdc();

			if (mTexture->IsAlpha())
			{
				//기본 포멧
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; //alpah -> 0(transparent)~255(opaque)
				AlphaBlend(hdc
					, pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHDC
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHDC
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255, 0, 255));
			}
			
			Rectangle(hdc, pos.x, pos.y, pos.x + 10, pos.y + 10);
			


		}
		else if (type == graphcis::Texture::eTextureType::Png)
		{
			//내가 원하는 픽셀을 투명화 시킬때
			Gdiplus::ImageAttributes imgAtt = {};
			//투명화 시킬 픽셀 선택
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));


			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);


			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect
				(
					pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, nullptr
			);
		}
		
	}
	void Animation::CreatAnimation(const std::wstring& name, graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLenght, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i <spriteLenght; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + size.x * i;
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;
			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}