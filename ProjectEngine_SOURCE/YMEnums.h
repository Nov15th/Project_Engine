#pragma once

namespace YM::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		//True,
		//Character,
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
		SpriteRender,
		Animator,
		Script,
		Camera,
		End,
	};
}