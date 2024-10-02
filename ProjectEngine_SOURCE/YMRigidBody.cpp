#include "YMRigidBody.h"
#include "YMTime.h"
#include "YMTransform.h"
#include "YMGameObject.h"

namespace YM
{
	RigidBody::RigidBody()
		:Component(enums::eComponentType::RigidBody)
		, mMass(1.0f)
		, mFriction(200.0f)
		, mForce(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mGravity(Vector2::Zero)
		, mAccelation(Vector2::Zero)
	{
	}
	RigidBody::~RigidBody()
	{
	}
	void RigidBody::Initialize()
	{
	}
	void RigidBody::Update()
	{
		// f= ma
		mAccelation = mForce / mMass;
		mVelocity += mAccelation * Time::DeltaTime();

		if (!(mVelocity == Vector2::Zero))
		{
			// f(힘) = m(질량) x a(가속도)
			// a = f / m;
			mAccelation = mForce / mMass;

			// 속도에 가속도를 더한다.
			mVelocity += mAccelation * Time::DeltaTime();

			if (!(mVelocity == Vector2::Zero))
			{
				//속도에 반대방향으로 마찰력 작용
				Vector2 friction = -mVelocity;
				friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

				// 마찰력으로 인한 속도 감소량이 현재 속도보다 큰 경우
				if (mVelocity.length() <= friction.length())
				{
					// 멈춰
					mVelocity = Vector2::Zero;
				}
				else
				{
					mVelocity += friction;
				}
			}

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos = pos + mVelocity * Time::DeltaTime();
			tr->SetPosition(pos);

			mForce.clear();
		}
	}
	void RigidBody::LateUpdate()
	{
	}
	void RigidBody::Render(HDC hdc)
	{
	}
}