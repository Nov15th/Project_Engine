#pragma once
#include "..\\ProjectEngine_SOURCE\YMScript.h"
#include "..\\ProjectEngine_SOURCE\YMTransform.h"


namespace YM
{
	class CameraScript : public Script
	{
	public:
		

		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


