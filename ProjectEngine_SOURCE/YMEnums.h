#pragma once

namespace YM::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Tile,
		//True,
		//Character,
		Animal,
		Player,
		Particle,
		Max=16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,

	};

	enum class eComponentType
	{
		Transform,
		Collider,
		RigidBody,
		Script,
		SpriteRender,
		Animator,
		Camera,
		End,
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};

}