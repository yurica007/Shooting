#include "Enemy.h"
#include "GameData.h"
#include "DxLib.h"

constexpr float kEnemySize = 50.0f;

Enemy::Enemy()
{
	enemyPos_.x = 400;
	enemyPos_.y = 50;
	moveSpeed = 3.0f;
}

Enemy::~Enemy()
{
}

Position2 Enemy::GetCenterPosition() const
{
	Vector2 centerPos_;
	centerPos_.x = kEnemySize / 2 + enemyPos_.x;
	centerPos_.y = kEnemySize / 2 + enemyPos_.y;

	return centerPos_;
}

void Enemy::Update()
{
	enemyPos_.x += moveSpeed;
	if (enemyPos_.x < Data::kGamePlayingLeft ||  Data::kGamePlayingRight < enemyPos_.x + kEnemySize)
	{
		moveSpeed *= -1;
	}
}

void Enemy::Draw()
{
	DrawBoxAA(enemyPos_.x, enemyPos_.y, enemyPos_.x + kEnemySize, enemyPos_.y + kEnemySize, 0x00ff00, false);
}