#pragma once

namespace YM::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
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
		Script,
		SpriteRender,
		Animator,
		Camera,
		End,
	};
}