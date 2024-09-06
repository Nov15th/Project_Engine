#include "YMPlayerScript.h"
#include "YMInput.h"
#include "YMTransform.h"
#include "YMTime.h"
#include "YMGameObject.h"
#include "YMAnimator.h"

namespace YM
{
	PlayerScript::PlayerScript()
		:mState(eState::SitDown)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
		
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case YM::PlayerScript::eState::SitDown:
			SitDown();
			break;
		case YM::PlayerScript::eState::Walk:
			Move();
			break;
		case YM::PlayerScript::eState::Sleep:
			break;
		case YM::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

		
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::SitDown()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mAnimator->PlayAnimation(L"CatRightWalk");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			mAnimator->PlayAnimation(L"CatLeftWalk");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mAnimator->PlayAnimation(L"CatUpWalk");
			mState = eState::Walk;
		}
		if(Input::GetKey(eKeyCode::Down))
		{
			mAnimator->PlayAnimation(L"CatDownWalk");
			mState = eState::Walk;
		}

		
	}
	void PlayerScript::Move()
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

		if (Input::GetKeyUp(eKeyCode::Right)
			||Input::GetKeyUp(eKeyCode::Left)
			||Input::GetKeyUp(eKeyCode::Up)
			||Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eState::SitDown;
			mAnimator->PlayAnimation(L"CatSitDown", false);
		}

	}
}