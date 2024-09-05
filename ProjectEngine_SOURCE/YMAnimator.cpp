#include "YMAnimator.h"


namespace YM
{
	Animator::Animator()
		: Component(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
	{
	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() == true
				&& mbLoop == true)
			{
				mActiveAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(hdc);
		}
	}
	void Animator::CreatAnimation(
		const std::wstring& name
		, graphcis::Texture* spriteSheet
		, Vector2 leftTop, Vector2 size
		, Vector2 offset, UINT spriteLenght
		, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
		{
			return;
		}
		animation = new Animation();
		animation->CreatAnimation(name, spriteSheet, leftTop, size, offset, spriteLenght, duration);
		animation->SetAnimator(this);
		mAnimations.insert(std::make_pair(name, animation));
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end())
		{
			return nullptr;
		}
		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
		{
			return;
		}
		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
}