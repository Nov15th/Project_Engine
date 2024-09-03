#pragma once
#include "YMGameObject.h"
namespace YM
{
	using namespace YM::math;
	class Camera : public Component
	{
	public:

		Vector2 CalulatePosition(Vector2 pos) { return pos - mDistance; }


		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		//std::vector<GameObject*> mGameObjects;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
		GameObject* mTarget;
	};
}


