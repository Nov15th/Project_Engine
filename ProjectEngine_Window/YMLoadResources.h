#pragma once
#include "..\\ProjectEngine_SOURCE\\YMResources.h"
#include "..\\ProjectEngine_SOURCE\\YMTexture.h"

// #pragma comment(lib, "..\\x64\\Debug\\ProjectEngine_Window.lib")

namespace YM
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG"
			, L"C:\\Users\\Choi_young ming\\source\\repos\\ProjectEngine\\Resources\\CloudOcean.png");
	}
}

