#pragma once
#include "CommonInclude.h"
#include "YMComponent.h"


namespace YM
{
	class GameObject
	{
	public:
		

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End,
		};

		GameObject();
		~GameObject();
		
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;
			

			return comp;
		}

		template< typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
				{
					break;
				}
			}
			return component;
		}

		eState GetActive() { return mState; }
		void SetActive(bool power)
		{
			if (power == true)
			{
				mState = eState::Active;
			}
			else
			{
				mState = eState::Paused;
			}
		}
		bool IsActive() { return mState == eState::Active; }
		bool IsDead() { return mState == eState::Dead; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }
	private:
		eState mState;
		std::vector<Component*> mComponents;
	};

	
}