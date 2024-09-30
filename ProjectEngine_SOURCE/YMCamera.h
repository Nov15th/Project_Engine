#pragma once
#include "YMGameObject.h"
namespace YM
{
	using namespace YM::math;
	class Camera : public Component
	{
	public:

		Vector2 CalulatePosition(Vector2 pos) { return pos - mDistance; }
		Vector2 CalulateTilePosition(Vector2 pos) { return pos + mDistance; }


		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; }

	private:
		//std::vector<GameObject*> mGameObjects;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
		class GameObject* mTarget;
	};
}


