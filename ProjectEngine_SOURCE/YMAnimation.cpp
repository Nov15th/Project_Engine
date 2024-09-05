#include "YMAnimation.h"
#include "YMTime.h"
#include "YMTransform.h"
#include "YMGameObject.h"
#include "YMAnimator.h"
#include "YMRenderer.h"
//#include "YMCamera.h"
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

		if (renderer::mainCamera)
		{
			pos = renderer::mainCamera->CalulatePosition(pos);
		}
		//기본 포멧
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 125; //alpah -> 0(transparent)~255(opaque)

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imHDC = mTexture->GetHdc();
		AlphaBlend(hdc
			, pos.x, pos.y
			, sprite.size.x * 5
			, sprite.size.y * 5
			, imHDC
			, sprite.leftTop.x
			, sprite.leftTop.y
			, sprite.size.x
			, sprite.size.y
			, func);




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