#pragma once

enum class InputType
{
	up,			//��
	down,		//��
	left,		//��
	right,		//�E
	shot,		//�V���b�g 
	lowspeed	//�ᑬ
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

