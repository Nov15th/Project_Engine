#pragma once
#include "CommonInclude.h"
#include "YMCollider.h"
namespace YM
{
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, enums::eLayerType left, enums::eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);

	private:
		static std::bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
	};
}


