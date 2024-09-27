#pragma once
#include "YMResource.h"
#include "YMTexture.h"

namespace YM
{
	class Animation : public Resource
	{
	public:

		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};


		Animation();
		~Animation();

		virtual HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);


		void CreatAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLenght
			, float duration);


		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }

	private:

		class Animator* mAnimator;
		graphics::Texture* mTexture;
		std::vector<Sprite> mAnimationSheet;
		UINT mIndex;
		float mTime;
		bool mbComplete;
	};
}


