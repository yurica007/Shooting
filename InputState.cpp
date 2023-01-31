#include "InputState.h"
#include <DxLib.h>

bool InputState::isTriggered(InputType type) const
{
	if (type == InputType::up)
	{
		return !lastKeyState[KEY_INPUT_UP] &&
			keyState[KEY_INPUT_UP];
	}
	else if (type == InputType::down)
	{
		return !lastKeyState[KEY_INPUT_DOWN] &&
			keyState[KEY_INPUT_DOWN];
	}
	else if (type == InputType::left)
	{
		return !lastKeyState[KEY_INPUT_LEFT] &&
			keyState[KEY_INPUT_LEFT];
	}
	else if (type == InputType::right)
	{
		return !lastKeyState[KEY_INPUT_RIGHT] &&
			keyState[KEY_INPUT_RIGHT];
	}
	else if (type == InputType::shot)
	{
		return !lastKeyState[KEY_INPUT_Z] &&
			keyState[KEY_INPUT_Z];
	}
    return false;
}

bool InputState::isPressed(InputType type) const
{
	if (type == InputType::up)
	{
		return keyState[KEY_INPUT_UP];
	}
	if (type == InputType::down)
	{
		return keyState[KEY_INPUT_DOWN];
	}
	if (type == InputType::left)
	{
		return keyState[KEY_INPUT_LEFT];
	}
	if (type == InputType::right)
	{
		return keyState[KEY_INPUT_RIGHT];
	}
	if (type == InputType::shot)
	{
		return keyState[KEY_INPUT_Z];
	}
	if (type == InputType::lowspeed)
	{
		return keyState[KEY_INPUT_SPACE];
	}
	return false;
}

void InputState::Update()
{
	//前のフレームのキー状況をコピー
	for (int i = 0; i < _countof(lastKeyState); i++)
	{
		lastKeyState[i] = keyState[i];
	}
	GetHitKeyStateAll(keyState);
}
