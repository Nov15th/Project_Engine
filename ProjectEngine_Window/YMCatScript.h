#pragma once
#include "..\\ProjectEngine_SOURCE\YMScript.h"
#include "..\\ProjectEngine_SOURCE\YMTransform.h"


namespace YM
{
	class CatScript : public Script
	{
	public:

		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDiration
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(GameObject* player) { mPlayer = player; }
		Vector2 mDest;
	private:

		void SitDown();
		void Move();
		void LayDown();
		void PlayWalkAnimationByDiration(eDiration dir);
		void Translate(Transform* tr);
		
		

	private:
		eState mState;
		class Animator* mAnimator;
		eDiration mDiration;
		float mTime;
		float mDeathTime;

		GameObject* mPlayer;
		
	};
}


