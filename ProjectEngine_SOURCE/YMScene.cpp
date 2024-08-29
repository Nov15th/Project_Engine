#include "YMScene.h"


namespace YM
{
	
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
		
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		//기존
		//for (size_t i = 0; i < mGameObjects.size(); i++)
		//{
		//	mGameObjects[i]->Updata();
		//}

		//범위기반 for문

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Updata();
		}

	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}

}