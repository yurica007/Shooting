#include "Player.h"
#include "InputState.h"
#include "DxLib.h"
#include "GameData.h"

constexpr float kNormalSpeed = 5.0f;
constexpr float kLowSpeed = 3.0f;
constexpr float kPlayerSize = 30.0f;

Player::Player()
{
	playerPos_.x = 400.0f;
	playerPos_.y = 300.0f;
	isLow = false;
}

Player::~Player()
{
}

const Position2& Player::GetCenterPosition() const
{
	Vector2 centerPos_;
	centerPos_.x = kPlayerSize / 2 + playerPos_.x;
	centerPos_.y = kPlayerSize / 2 + playerPos_.y;

	return centerPos_;
}

void Player::Update(const InputState& input)
{
	float speed = 2.0f;
	//Vector2 vel = { 0.0f, 0.0f };
	Vector2 velocity;
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	if (input.isPressed(InputType::lowspeed)) isLow = true;
	else isLow = false;

	if (isLow) speed = kLowSpeed;
	else speed = kNormalSpeed;

	if (input.isPressed(InputType::left)) velocity.x = - speed;
	if (input.isPressed(InputType::right)) velocity.x = speed;
	if (input.isPressed(InputType::up)) velocity. y = - speed;
	if (input.isPressed(InputType::down)) velocity.y = speed;
	
	if (velocity.Length() > 0.0f)
	{
		velocity.Nomalize();
		velocity *= speed;
	}
	playerPos_ += velocity;

	if (playerPos_.x < Data::kGamePlayingLeft) playerPos_.x = Data::kGamePlayingLeft;
	if (Data::kGamePlayingRight < playerPos_.x + kPlayerSize) playerPos_.x = Data::kGamePlayingRight - kPlayerSize;
	if (playerPos_.y < Data::kGamePlayingTop) playerPos_.y = Data::kGamePlayingTop;
	if (Data::kGamePlayingBottom < playerPos_.y + kPlayerSize) playerPos_.y = Data::kGamePlayingBottom - kPlayerSize;
}

void Player::Draw()
{
	DrawBoxAA(playerPos_.x, playerPos_.y, playerPos_.x + kPlayerSize, playerPos_.y + kPlayerSize, 0xffffff, false);
}
