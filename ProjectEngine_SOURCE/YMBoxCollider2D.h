#pragma once
#include "YMCollider.h"

namespace YM
{
	class BoxCollider2D : public Collider
	{
	public:

		BoxCollider2D();
		~BoxCollider2D();
	public:

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		Vector2 mSize;

	};
}


