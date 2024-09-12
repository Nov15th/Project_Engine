#pragma once
#include "..\\ProjectEngine_SOURCE\\YMResources.h"
#include "..\\ProjectEngine_SOURCE\\YMTexture.h"
//#include "..\\Resources\\ChickenAlpha.bmp"

namespace YM
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphcis::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}

