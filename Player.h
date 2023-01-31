#pragma once

#include "Geometry.h"

class InputState;

class Player
{
public:
	Player();
	virtual ~Player();
	const Position2& GetCenterPosition() const;
	void Update(const InputState& input);
	void Draw();

private:
	Position2 playerPos_;
	bool isLow;
};

