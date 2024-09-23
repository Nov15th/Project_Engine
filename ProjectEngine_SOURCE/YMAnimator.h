#pragma once
#include "YMComponent.h"
#include "YMAnimation.h"

namespace YM
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
				{
					mEvent();
				}
			}
			std::function<void()> mEvent;
			
		};

		struct Events
		{
			Event StartEvent;
			Event CompleteEvent;
			Event EndEvent;
		};


		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		void CreatAnimation(const std::wstring& name
			, graphcis::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLenght
			, float duration);

		void CreatAnimationByFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset, float duration);


		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);


		bool isComplete() { return mActiveAnimation->IsComplete(); }




	private:

		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
		//Event
		std::map<std::wstring, Events*> mEvents;
	};
}


