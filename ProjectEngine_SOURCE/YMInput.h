#pragma once
#include "CommonInclude.h"

namespace YM
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		Left, Right, Down, Up,
		LButton, MButton, RButton,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode Keycord;
			eKeyState state;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
		static math::Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void CreatKeys();
		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);
		static void GetMousePositionWindow();
		static void ClearKey();
		
	private:
		//클래스 내부에서 전역변수로 선언하는 방법 -> 정적 변수 static 변수
		static std::vector<Key> Keys;
		static math::Vector2 mMousePosition;
	};

} 