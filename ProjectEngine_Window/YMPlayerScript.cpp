#include "YMPlayerScript.h"
#include "YMInput.h"
#include "YMTransform.h"
#include "YMTime.h"
#include "YMGameObject.h"
#include "YMAnimator.h"

namespace YM
{
	PlayerScript::PlayerScript()
		:mState(eState::Idle)
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
		case YM::PlayerScript::eState::Idle:
			Idle();
			break;
		case YM::PlayerScript::eState::Walk:
			Move();
			break;
		case YM::PlayerScript::eState::Sleep:
			break;
		case YM::PlayerScript::eState::GiveWater:
			GiveWater();
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
	void PlayerScript::Idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{

			mState = eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();

		}
		/*if (Input::GetKey(eKeyCode::Left))
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
		}*/

		
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
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIdle", false);
		}

	}
	void PlayerScript::GiveWater()
	{
		if (mAnimator->isComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIdle", false);
		}
	}
}