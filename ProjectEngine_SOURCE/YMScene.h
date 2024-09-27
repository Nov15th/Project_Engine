#pragma once
#include "YMEntity.h"
#include "YMGameObject.h"
#include "YMLayer.h"

namespace YM
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		
		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		void EraseGameObject(GameObject* gameObj);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }


	private:
		void CreatLayers();
	private:
		std::vector<Layer*> mLayers;
	};
}


