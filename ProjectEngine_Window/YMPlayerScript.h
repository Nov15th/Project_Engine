#pragma once
#include "..\\ProjectEngine_SOURCE\YMScript.h"

namespace YM
{
	class PlayerScript : public Script
	{
	public:

		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};


		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Idle();
		void Move();
		void GiveWater();
		void AttackEffect();

		void OnCollisionEnter(class Collider* other) override ;
		void OnCollisionStay(class Collider* other) override ;
		void OnCollisionExit(class Collider* other) override ;



	private:
		eState mState;
		class Animator* mAnimator;



	};
}


