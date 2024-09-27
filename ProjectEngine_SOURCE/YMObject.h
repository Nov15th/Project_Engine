#pragma once
#include "YMComponent.h"
#include "YMGameObject.h"
#include "YMLayer.h"
#include "YMScene.h"
#include "YMSceneManager.h"
#include "YMTransform.h"
namespace YM::Object
{
	template<typename T>
	static T* Instantiate(YM::enums::eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}
	template<typename T>
	static T* Instantiate(YM::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void DontDestroyOnLoad(GameObject* gameobject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		// 현재 씬에서 게임 오브젝트를 지워준다
		activeScene->EraseGameObject(gameobject);
		// 해당 게임 오브젝트를 DontDestroy씬으로 넣어준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDonDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameobject, gameobject->GetLayerType());
	}
}
