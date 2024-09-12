#include "YMScene.h"


namespace YM
{
	
	Scene::Scene()
		:mLayers{}
	{
		CreatLayers();
		
		
	}

	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		//기존
		//for (size_t i = 0; i < mGameObjects.size(); i++)
		//{
		//	mGameObjects[i]->Updata();
		//}

		//범위기반 for문

		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}
			layer->Update();
		}

	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}
			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::CreatLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::OnEnter()
	{

	}


	void Scene::OnExit()
	{

	}


	

}