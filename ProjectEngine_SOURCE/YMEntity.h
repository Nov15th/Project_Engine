#pragma once
#include "CommonInclude.h"

using namespace YM::math;

namespace YM
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }
	private:
		std::wstring mName;

			
	};
}


