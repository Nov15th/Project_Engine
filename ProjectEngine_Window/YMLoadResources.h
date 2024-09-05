#pragma once
#include "..\\ProjectEngine_SOURCE\\YMResources.h"
#include "..\\ProjectEngine_SOURCE\\YMTexture.h"
//#include "..\\Resources\\ChickenAlpha.bmp"

namespace YM
{
	void LoadResources()
	{
		//Resources::Load<graphcis::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
		Resources::Load<graphcis::Texture>(L"PacMan", L"..\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphcis::Texture>(L"PM_BG", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
	}
}

