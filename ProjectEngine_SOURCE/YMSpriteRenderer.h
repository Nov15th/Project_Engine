#pragma once
#include "YMEntity.h"
#include "YMComponent.h"

namespace YM
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImgae;
		UINT mWidth;
		UINT mHeight;

	};
}



