#include "YMSpriteRenderer.h"
#include "YMGameObject.h"
#include "YMTransform.h"
#include "YMTexture.h"
#include "YMRenderer.h"
namespace YM
{
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRender)
		, mTexture(nullptr)
		, mSize(Vector2::One)

	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture==nullptr)
		{
			assert(false);
		}
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalulatePosition(pos);
		if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Bmp)
		{
			
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Png)
		{
			//투명화 시킬 픽셀 선택
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));


			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y
				)
				, 0,0,mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr  /*, &imgAtt*/);

		}
		
	}

	
}