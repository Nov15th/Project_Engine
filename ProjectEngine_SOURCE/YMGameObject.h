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
		// ���� ������Ʈ ��ǥ
		float mX;
		float mY;
	};
}
