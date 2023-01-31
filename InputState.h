#pragma once

enum class InputType
{
	up,			//上
	down,		//下
	left,		//左
	right,		//右
	shot,		//ショット 
	lowspeed	//低速
};

class InputState
{
public:
	bool isTriggered(InputType type) const;
	bool isPressed(InputType type)const;
	void Update();
private:
	int keypadState;
	int lastKeypadState;
	char keyState[256];
	char lastKeyState[256];
};

