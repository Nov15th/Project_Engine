#pragma once
#include "..\\ProjectEngine_SOURCE\\YMSceneManager.h"

#include "YMPlayScene.h"

// #pragma comment(lib, "..\\x64\\Debug\\ProjectEngine_Window.lib")

namespace YM
{
	void LoadScenes()
	{
		SceneManager::CreatScene<PlayScene>(L"PlayScene");
		//SceneManager::CreatScene<EndScene>(L"EndScene");
		//SceneManager::CreatScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");

	}
}

