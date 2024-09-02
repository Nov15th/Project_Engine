#include "YMPlayer.h"
#include "YMInput.h"
#include "YMTransform.h"
#include "YMTime.h"
namespace YM
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::Right))
		{
			Transform *tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}


	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}