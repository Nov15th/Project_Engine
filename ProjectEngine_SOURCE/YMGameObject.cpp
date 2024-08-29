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
		//ĥ�ϰ� ���� �귯�� ����
		HBRUSH brush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
		//����Ʈ ��� ������ �귯�� ���� �� ����Ʈ ���� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//�ٽ� ����Ʈ �귯���� ����
		SelectObject(hdc, oldBrush);

		//������ �귯�� ����
		DeleteObject(brush);
	}

}