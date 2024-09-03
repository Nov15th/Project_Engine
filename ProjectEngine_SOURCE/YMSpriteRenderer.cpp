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
		pos = renderer::mainCamera->CalulatePosition(pos);
		if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Bmp)
		{
			
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth(), mTexture->GetHeight()
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
		//Gdiplus::Graphics graphcis(hdc);
		//graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

	}

	
}