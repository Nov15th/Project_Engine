#include "YMCatScript.h"
#include "YMInput.h"
#include "YMTransform.h"
#include "YMTime.h"
#include "YMGameObject.h"
#include "YMAnimator.h"
#include "YMObject.h"
namespace YM
{
	CatScript::CatScript()
		:mState(eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDeathTime(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{

	}
	void CatScript::Update()
	{

		mDeathTime += Time::DeltaTime();
		if (mDeathTime > 6.0f)
		{
			//Object::Destroy(GetOwner());
		}
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case YM::CatScript::eState::SitDown:
			SitDown();
			break;
		case YM::CatScript::eState::Walk:
			Move();
			break;
		case YM::CatScript::eState::Sleep:
			break;
		case YM::CatScript::eState::LayDown:
			break;
		case YM::CatScript::eState::Attack:
			break;
		default:
			break;
		}


	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::SitDown()
	{
		
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = CatScript::eState::Walk;
			int diration = rand() % 4;
			mDiration = (eDiration)diration;
			PlayWalkAnimationByDiration(mDiration);
			mTime = 0.0f;
		}


	}
	void CatScript::Move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown == 1)
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"CatSitDown", false);
			}
			else
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"CatLayDown", false);
			}
			
		}


		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr);
	}
	void CatScript::LayDown()
	{

	}

	void CatScript::PlayWalkAnimationByDiration(eDiration dir)
	{
		switch (dir)
		{
		case YM::CatScript::eDiration::Left:
			mAnimator->PlayAnimation(L"CatLeftWalk",true);
			break;
		case YM::CatScript::eDiration::Right:
			mAnimator->PlayAnimation(L"CatRightWalk", true);
			break;
		case YM::CatScript::eDiration::Down:
			mAnimator->PlayAnimation(L"CatDownWalk", true);
			break;
		case YM::CatScript::eDiration::Up:
			mAnimator->PlayAnimation(L"CatUpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::Translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDiration)
		{
		case YM::CatScript::eDiration::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case YM::CatScript::eDiration::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case YM::CatScript::eDiration::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case YM::CatScript::eDiration::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		tr->SetPosition(pos);
	}
}