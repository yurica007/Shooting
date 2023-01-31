#include "GameScene.h"
#include "DxLib.h"
#include "GameData.h"

constexpr int shotInterval = 5;

GameScene::GameScene()
{
	shotIntervalCount = 0;
	for (auto& normalShot : normalShot_)
	{
		normalShot = std::make_shared<PlayerShot>();
	}
	for (auto& homingShot : homingShot_)
	{
		homingShot = std::make_shared<PlayerShot>();
	}
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	input.Update();
	if (shotIntervalCount == 0)
	{
		for (auto& normalShot : normalShot_)
		{
			if (!normalShot->IsNormalEneble())
			{
				normalShot->FireNormal(player.GetCenterPosition());
				break;
			}
		}
		if (input.isPressed(InputType::shot))
		{
			for (auto& homingShot : homingShot_)
			{
				if (!homingShot->IsHomingEneble())
				{
					auto playerPos = player.GetCenterPosition();
					auto enemyPos = enemy.GetCenterPosition();
					homingShot->FireHoming(playerPos, enemyPos);
					break;
				}
			}
		}
	}
	shotIntervalCount = (shotIntervalCount + 1) % shotInterval;

	for (auto& normalShot : normalShot_)
	{
		if (normalShot->IsNormalEneble())
		{
			normalShot->UpdateNormal();
		}
	}
//	if (input.isPressed(InputType::shot))
//	{
		for (auto& homingShot : homingShot_)
		{
			if (homingShot->IsHomingEneble())
			{
				homingShot->UpdateHoming();
			}
		}
//	}
	player.Update(input);
	enemy.Update();
}

void GameScene::Draw()
{
	DrawBoxAA(Data::kGamePlayingLeft, Data::kGamePlayingTop, Data::kGamePlayingRight, Data::kGamePlayingBottom, 0x888888, true);

	for (auto& normalShot : normalShot_)
	{
		if (normalShot->IsNormalEneble()) normalShot->DrawNormal();
	}
	for (auto& homingShot : homingShot_)
	{
		if (homingShot->IsHomingEneble()) homingShot->DrawHoming();
	}
	player.Draw();
	enemy.Draw();
}