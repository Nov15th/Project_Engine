#pragma once
#include "..\\ProjectEngine_SOURCE\YMScript.h"

namespace YM
{
	class PlayerScript : public Script
	{
	public:

		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			Attack,
		};


		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SitDown();
		void Move();



	private:
		eState mState;
		class Animator* mAnimator;
	};
}


