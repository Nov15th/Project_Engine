#include "YMInput.h"

namespace YM
{

	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W','E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		//MK_LBUTTON, '0', VK_NUMPAD0
	};

	void Input::Initailize()
	{
		CreatKeys();
	}
	void Input::CreatKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.Keycord = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	
	
	void Input::Update()
	{
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) ->void
			{
				UpdateKeys();
			});
		
	}

	void Input::UpdateKey(Input::Key& key)
	{
		if (IsKeyDown(key.Keycord))
		{
			UpdateKeyDown(key);
		}
		else
		{
			UpdateKeyUp(key);
		}
	}

	bool Input::IsKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	
	void Input::UpdateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			key.state = eKeyState::Down;
		}
		key.bPressed = true;
	}
	void Input::UpdateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Up;
		}
		else
		{
			key.state = eKeyState::None;
		}
		key.bPressed = false;
	}
	
}