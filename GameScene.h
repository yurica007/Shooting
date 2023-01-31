#pragma once
#include "InputState.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerShot.h"
#include <memory>
#include <array>

class GameScene
{
public:
	GameScene();
	virtual ~GameScene();
	void Update();
	void Draw();

private:
	int shotIntervalCount;

	Player player;
	Enemy enemy;
	std::array<std::shared_ptr<PlayerShot>, 32> normalShot_;
	std::array<std::shared_ptr<PlayerShot>, 32> homingShot_;
	InputState input = {};
};

