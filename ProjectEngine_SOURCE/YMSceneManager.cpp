#include "YMSceneManager.h"
#include "YMDontDestroyOnLoad.h"

namespace YM
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mDontDestroyOnLoad = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
		{
			mActiveScene->OnExit();
		}

		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

		if (iter == mScene.end())
		{
			return nullptr;
		}
		mActiveScene = iter->second;

		mActiveScene->OnEnter();

		return iter->second;
	}

	std::vector<GameObject*> SceneManager::GetGameObject(eLayerType layer)
	{
		std::vector<GameObject*> gameObjects = mActiveScene->GetLayer(layer)->GetGameObject(); 
		std::vector<GameObject*> dontDestroyOnLoad = mDontDestroyOnLoad->GetLayer(layer)->GetGameObject();

		gameObjects.insert(gameObjects.end(), dontDestroyOnLoad.begin(), dontDestroyOnLoad.end());

		return gameObjects;
	}

	void SceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreatScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
		mDontDestroyOnLoad->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;

		}
	}
}