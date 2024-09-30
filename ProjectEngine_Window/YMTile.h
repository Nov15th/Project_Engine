#pragma once
#include "..\\ProjectEngine_SOURCE\\YMGameObject.h"

namespace YM
{

	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetIndexPosition(int x, int y);
	
	};
}
