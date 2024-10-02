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
			// f(��) = m(����) x a(���ӵ�)
			// a = f / m;
			mAccelation = mForce / mMass;

			// �ӵ��� ���ӵ��� ���Ѵ�.
			mVelocity += mAccelation * Time::DeltaTime();

			if (!(mVelocity == Vector2::Zero))
			{
				//�ӵ��� �ݴ�������� ������ �ۿ�
				Vector2 friction = -mVelocity;
				friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

				// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
				if (mVelocity.length() <= friction.length())
				{
					// ����
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