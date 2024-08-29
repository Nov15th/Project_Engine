#include "YMGameObject.h"
#include "YMInput.h"
#include "YMTime.h"
namespace YM
{
	GameObject::GameObject()
		:mX(100)
		,mY(100)
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Updata()
	{
		const int speed = 100.0f;
		
		if(Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY-= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY+= speed * Time::DeltaTime();
		}
		
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		//칠하고 싶은 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
		//디폴트 대신 생성한 브러쉬 선택 및 디폴트 색상 저장
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//다시 디폴트 브러쉬로 변경
		SelectObject(hdc, oldBrush);

		//생성한 브러쉬 삭제
		DeleteObject(brush);
	}

}