#pragma once
#include "..\\ProjectEngine_SOURCE\\YMResources.h"
#include "..\\ProjectEngine_SOURCE\\YMTexture.h"
//#include "..\\Resources\\ChickenAlpha.bmp"

namespace YM
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
	}
}

