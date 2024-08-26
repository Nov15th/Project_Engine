#include "YMGameObject.h"
#include "YMInput.h"

namespace YM
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Updata()
	{
		
		
		if(Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY-= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY+= 0.01f;
		}
		
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		//칠하고 싶은 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		//디폴트 대신 생성한 브러쉬 선택 및 디폴트 색상 저장
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//다시 디폴트 브러쉬로 변경
		SelectObject(hdc, oldBrush);

		//생성한 브러쉬 삭제
		DeleteObject(brush);
	}

}