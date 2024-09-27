#include "YMPlayerScript.h"
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
			assert(false);
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
			Cat* cat = Object::Instantiate<Cat>(enums::eLayerType::Animal);
			CatScript* catSrc = cat->AddComponent<CatScript>();
			catSrc->SetPlayer(GetOwner());


			graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catanimator = cat->AddComponent<Animator>();
			catanimator->CreatAnimation(L"CatDownWalk", catTex
				, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catanimator->CreatAnimation(L"CatRightWalk", catTex
				, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catanimator->CreatAnimation(L"CatUpWalk", catTex
				, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catanimator->CreatAnimation(L"CatLeftWalk", catTex
				, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catanimator->CreatAnimation(L"CatSitDown", catTex
				, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catanimator->CreatAnimation(L"CatGrooming", catTex
				, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catanimator->CreatAnimation(L"CatLayDown", catTex
				, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			catanimator->PlayAnimation(L"CatSitDown", false);

			Transform* tr = GetOwner()->GetComponent<Transform>();


			cat->GetComponent<Transform>()->SetPosition(Vector2(tr->GetPosition()));
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = Input::GetMousePosition();
			catSrc->mDest = mousePos;
			/*mState = eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();*/

		}
		
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
	void PlayerScript::AttackEffect()
	{
		Cat* cat = Object::Instantiate<Cat>(enums::eLayerType::Animal);
		CatScript* catSrc = cat->AddComponent<CatScript>();
		catSrc->SetPlayer(GetOwner());


		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catanimator = cat->AddComponent<Animator>();
		catanimator->CreatAnimation(L"CatDownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatRightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatUpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatLeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatSitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatGrooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatLayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catanimator->PlayAnimation(L"CatSitDown", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();


		cat->GetComponent<Transform>()->SetPosition(Vector2(tr->GetPosition()));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		Vector2 mousePos = Input::GetMousePosition();
		catSrc->mDest = mousePos;

	}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(Vector2(500.0f, 500.0f));
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{
		
	}
	void PlayerScript::OnCollisionExit(Collider* other)
	{
		
	}
}