#pragma once
#include "YMCollider.h"

namespace YM
{
	class CircleCollider2D : public Collider
	{
	public:

		CircleCollider2D();
		~CircleCollider2D();

	public:

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		float mRadius;
	};
}


