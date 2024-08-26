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
		//ĥ�ϰ� ���� �귯�� ����
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		//����Ʈ ��� ������ �귯�� ���� �� ����Ʈ ���� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//�ٽ� ����Ʈ �귯���� ����
		SelectObject(hdc, oldBrush);

		//������ �귯�� ����
		DeleteObject(brush);
	}

}