#include "YMCamera.h"
#include "YMGameObject.h"
#include "YMTransform.h"
#include "peApplication.h"

extern YM::Application application;

namespace YM
{
	Camera::Camera()
		:Component(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPosition(Vector2::Zero)
		,mTarget(nullptr)
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		Transform* cameratr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameratr->GetPosition();
		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}