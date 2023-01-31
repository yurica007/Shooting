#include "PlayerShot.h"
#include "GameData.h"
#include "DxLib.h"

constexpr float kShotSize = 5.0f;
constexpr float kNormalShotSpeed = - 10.0f;
constexpr float kHomingShotSpeed = - 8.0f;

PlayerShot::PlayerShot()
{
	shotNormalPos_.x = 0.0f;
	shotNormalPos_.y = 0.0f;
	shotHomingPos_.x = 0.0f;
	shotHomingPos_.y = 0.0f;

	vel_.x = 0.0f;
	vel_.y = 0.0f;
	isNormalEneble = true;
	isHomingEneble = true;
}

PlayerShot::~PlayerShot()
{
}

void PlayerShot::FireNormal(const Position2& playerPos)
{
	shotNormalPos_ = playerPos;
	isNormalEneble = true;
}

void PlayerShot::FireHoming(const Position2& playerPos, const Position2& enemyPos)
{
	enemyPos_ = enemyPos;
	shotHomingPos_ = playerPos;
	isHomingEneble = true;
}

bool PlayerShot::IsNormalEneble() const
{
	return isNormalEneble;
}

bool PlayerShot::IsHomingEneble() const
{
	return isHomingEneble;
}

void PlayerShot::UpdateNormal()
{
	vel_.y = kNormalShotSpeed;
	shotNormalPos_ += vel_;

	if (shotNormalPos_.y < kShotSize || Data::kDisplayHeight + kShotSize < shotNormalPos_.y) isNormalEneble = false;
}

void PlayerShot::UpdateHoming()
{
	Vector2 vec;

	vec.x = 0.0f;
	vec.y = 0.0f;

	vec.x = enemyPos_.x - shotHomingPos_.x;
	vec.y = enemyPos_.y - shotHomingPos_.y;

	DrawFormatStringF(600.0f, 0.0f, 0xffffff, L"%f", enemyPos_.x);
	DrawFormatStringF(600.0f, 30.0f, 0xffffff, L"%f", enemyPos_.y);
	DrawFormatStringF(600.0f, 60.0f, 0xffffff, L"%f", shotHomingPos_.x);
	DrawFormatStringF(600.0f, 90.0f, 0xffffff, L"%f", shotHomingPos_.y);

	DrawFormatStringF(600.0f, 300.0f, 0xffffff, L"%f", vec.x);
	DrawFormatStringF(600.0f, 330.0f, 0xffffff, L"%f", vec.y);


	vel_.y = kHomingShotSpeed;
	
	if (vec.Length() > 0.0f)
	{
		vec.Nomalize();
	}
	//vec.x *= vel_.x;
	//vec.y *= vel_.y;

	shotHomingPos_ += vec;

	if (shotHomingPos_.y < kShotSize || Data::kDisplayHeight + kShotSize < shotHomingPos_.y) isHomingEneble = false;
}

void PlayerShot::DrawNormal()
{
	DrawCircle(shotNormalPos_.x, shotNormalPos_.y, kShotSize, 0xff0000, false);
}

void PlayerShot::DrawHoming()
{
	DrawCircle(shotHomingPos_.x, shotHomingPos_.y, kShotSize, 0x00ff00, false);
}