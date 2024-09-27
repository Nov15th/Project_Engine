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
		// ���� ������ ���� ������Ʈ�� �����ش�
		activeScene->EraseGameObject(gameobject);
		// �ش� ���� ������Ʈ�� DontDestroy������ �־��ش�.
		Scene* dontDestroyOnLoad = SceneManager::GetDonDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameobject, gameobject->GetLayerType());
	}
}
