#include "YMAnimator.h"
#include "YMResources.h"
#include "YMTexture.h"
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
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			
			mActiveAnimation->Update();

			Events* events = FindEvents(mActiveAnimation->GetName());

			if (mActiveAnimation->IsComplete() == true)
	
			{
				if (events)
				{
					events->CompleteEvent();
				}
				
				if (mbLoop == true)
				{
					mActiveAnimation->Reset();
				}
				
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
		animation->SetName(name);
		animation->CreatAnimation(name, spriteSheet, leftTop, size, offset, spriteLenght, duration);
		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));



		mAnimations.insert(std::make_pair(name, animation));
	}
	void Animator::CreatAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
		{
			return;
		}

		int filecount = 0;
		std::filesystem::path fs(path);
		std::vector<graphcis::Texture*> images = {};
		for (auto& p :std::filesystem::recursive_directory_iterator(fs))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path();
			graphcis::Texture* texture = Resources::Load<graphcis::Texture>(fileName, fullName);

			images.push_back(texture);
			filecount++;
		}


		UINT sheetWidth = images[0]->GetWidth() * filecount;
		UINT sheetHeight= images[0]->GetHeight();
		graphcis::Texture* spriteSheet = graphcis::Texture::Create(name, sheetWidth, sheetHeight);

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();

		for (size_t i = 0; i< images.size(); i++)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
				, imageWidth, imageHeight
				, images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreatAnimation(name, spriteSheet
			, Vector2::Zero, Vector2(imageWidth, imageHeight)
			, offset, filecount, duration);

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
		
		if (mActiveAnimation)
		{
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());
			if (currentEvents)
			{
				currentEvents->EndEvent();
			}
		}

		
		

		Events* nextEvents = FindEvents(animation->GetName());
		if (nextEvents)
		{
			nextEvents->StartEvent();
		}

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = mEvents.find(name);
		if (iter == mEvents.end())
		{
			return nullptr;
		}
		return iter->second;
		
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->StartEvent.mEvent;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->CompleteEvent.mEvent;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->EndEvent.mEvent;
	}
}