#include "YMCollisionManager.h"
#include "YMScene.h"
#include "YMSceneManager.h"
#include "YMGameObject.h"
#include "YMCollider.h"
#include "YMTransform.h"
#include "YMGameObject.h"
namespace YM
{
	std::bitset<(UINT)enums::eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};
	void CollisionManager::Initialize()
	{

	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)enums::eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)enums::eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (enums::eLayerType) row, (enums::eLayerType) col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}

	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
	}

	void CollisionManager::CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}


		mCollisionLayerMatrix[row][col] = enable;


	}
	void CollisionManager::LayerCollision(Scene* scene, enums::eLayerType left, enums::eLayerType right)
	{
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObject(left); 
		const std::vector<GameObject*>& rights = SceneManager::GetGameObject(right);

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
			{
				continue;
			}

			Collider* leftCol = left->GetComponent<Collider>();

			if (leftCol== nullptr)
			{
				continue;
			}

			

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
				{
					continue;
				}

				Collider* rightCol = right->GetComponent<Collider>();

				if (rightCol == nullptr)
				{
					continue;
				}

				if (left == right)
				{
					continue;
				}

				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		//충돌 로직 작성
		//두 충돌체 번호를 가져온 ID를 확인해서 Collision ID값 셋팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();
		// 해당 ID로 충돌체 정보를 검색
		// 만약 없다면 충돌 정보 생성

		auto iter = mCollisionMap.find(id.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 체크

		if (Intersect(left, right))
		{
			//최초 충돌
			if (iter->second == false)
			{
				left->OnColliisionEnter(right);
				right->OnColliisionEnter(left);
				iter->second = true;
			}
			// 충돌 진행중
			else 
			{
				left->OnColliisionStay(right);
				right->OnColliisionStay(left);
			}
		}
		// 충돌상태가 해제되었을때
		else
		{
			if (iter->second == true)
			{
				left->OnColliisionExit(right);
				right->OnColliisionExit(left);
				iter->second = false;
			}
		}

	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffSet();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffSet();

		//기본사이즈가 100픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;


		eColliderType leftType = left->GetColliderType();
		eColliderType rightType = right->GetColliderType();
		//AABB충돌
		//rect-rect 충돌
		if (leftType == eColliderType::Rect2D
			&&rightType == eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}
		//circle - circle
		if (leftType == eColliderType::Circle2D
			&& rightType == eColliderType::Circle2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);

			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}
		//circle - rect
		if (leftType == eColliderType::Circle2D
			&& rightType == eColliderType::Rect2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			
		}
		


		return false;
	}

	
}