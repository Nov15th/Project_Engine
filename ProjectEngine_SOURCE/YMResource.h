#pragma once
#include "YMEntity.h"
namespace YM
{
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }
	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}


// 게임에서 사용되는 데이터들의 종류

// 이미지, 사운드, 

// 저장 게임 플레이 데이터, HDD, 클라우드 등등 이것도 리소스다.