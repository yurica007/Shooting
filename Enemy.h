#pragma once
#include "Geometry.h" 

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	Position2 GetCenterPosition() const;
	void Update();
	void Draw();

private:
	Position2 enemyPos_;
	float moveSpeed;
};

