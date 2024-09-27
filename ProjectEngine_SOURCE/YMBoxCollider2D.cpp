#include "YMBoxCollider2D.h"
#include "YMTransform.h"
#include "YMGameObject.h"

YM::BoxCollider2D::BoxCollider2D()
	: Collider(eColliderType::Rect2D)
{
}

YM::BoxCollider2D::~BoxCollider2D()
{
}

void YM::BoxCollider2D::Initialize()
{
}

void YM::BoxCollider2D::Update()
{
}

void YM::BoxCollider2D::LateUpdate()
{
}

void YM::BoxCollider2D::Render(HDC hdc)
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	Vector2 offset = GetOffSet();

	HBRUSH transparentBrash = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrash);

	HPEN greenPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);


	Rectangle(hdc, pos.x+ offset.x
		, pos.y + offset.y
		, pos.x + offset.x + 100
		, pos.y + offset.y + 100);


	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(greenPen);

}
