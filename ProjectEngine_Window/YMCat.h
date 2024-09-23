#pragma once
#include "..\\ProjectEngine_SOURCE\\YMGameObject.h"

namespace YM
{
	class Cat : public GameObject
	{
	public:

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		
	};

}



