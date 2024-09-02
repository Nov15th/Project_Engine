#pragma once
#include "..\\ProjectEngine_SOURCE\\YMSceneManager.h"

#include "YMPlayScene.h"
#include "YMTitleScene.h"

// #pragma comment(lib, "..\\x64\\Debug\\ProjectEngine_Window.lib")

namespace YM
{
	void LoadScenes()
	{




		SceneManager::CreatScene<PlayScene>(L"Play Scene");
		SceneManager::CreatScene<TitleScene>(L"Title Scene");
		//SceneManager::CreatScene<EndScene>(L"EndScene");
		//SceneManager::CreatScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"Play Scene");

	}
}

