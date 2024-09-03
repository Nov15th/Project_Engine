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
		Max=16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,

	};

	enum class eComponentType
	{
		Transform,
		SpriteRender,
		Script,
		Camera,
		End,
	};
}