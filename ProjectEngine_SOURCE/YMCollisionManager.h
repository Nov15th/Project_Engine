#pragma once
#include "CommonInclude.h"
#include "YMBoxCollider2D.h"
#include "YMCircleCollider2D.h"
namespace YM
{
	using namespace enums;

	union CollisionID
	{
		struct
		{
			UINT left;
			UINT right;
		};

		UINT64 id;

	};


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
		static bool Intersect(Collider* left, Collider* right);

	private:
		static std::bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}


