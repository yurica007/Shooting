#pragma once

#include "Geometry.h"

class InputState;

class PlayerShot
{
public:
	PlayerShot();
	virtual ~PlayerShot();

	void FireNormal(const Position2& playerPos);
	void FireHoming(const Position2& playerPos, const Position2& enemyPos);
	bool IsNormalEneble() const;
	bool IsHomingEneble() const;
	void UpdateNormal();
	void UpdateHoming();
	void DrawNormal();
	void DrawHoming();

private:
	Position2 shotNormalPos_;
	Position2 shotHomingPos_;
	Position2 enemyPos_;
	Vector2 vel_;

	bool isNormalEneble;
	bool isHomingEneble;
};

