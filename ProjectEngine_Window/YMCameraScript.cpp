#include "YMCameraScript.h"
#include "YMInput.h"
#include "YMTransform.h"
#include "YMTime.h"
#include "YMGameObject.h"
#include "YMAnimator.h"
#include "YMCat.h"
#include "YMCatScript.h"
#include "YMObject.h"
#include "YMResources.h"
#include "YMCollider.h"

namespace YM
{
	CameraScript::CameraScript()
	{
	}
	CameraScript::~CameraScript()
	{
	}
	void CameraScript::Initialize()
	{
	}
	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}
	void CameraScript::LateUpdate()
	{
	}
	void CameraScript::Render(HDC hdc)
	{
	}
}