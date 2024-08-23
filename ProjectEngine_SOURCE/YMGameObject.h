#pragma once
#include "CommonInclude.h"
namespace YM
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		

		void Updata();
		void LateUpdate();
		void Render(HDC hdc);








		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:
		// 게임 오브젝트 좌표
		float mX;
		float mY;
	};
}
