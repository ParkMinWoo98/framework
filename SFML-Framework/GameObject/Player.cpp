#include "Player.h"
#include "../Framework/ResourceMgr.h"
#include "../Framework/Utils.h"
#include <cmath>

Player::Player()
	:axeAngle(0.f)
{
	Init();
	for (int i = 0; i < 10; ++i)
	{
		SpriteObj* axe = new SpriteObj();
		axe->SetTexture(*RESOURCE_MGR->GetTexture("graphics/axe.png"));
		axe->SetOrigin(Origins::MC);
		unusingAxes.push_back(axe);
	}
}

Player::~Player()
{
}

void Player::Init()
{
	Release();
	level = 0;
	exp = 0;
	lvUpExp = 10;
	hp = 10;
}

void Player::Release()
{
	while(!usingAxes.empty())
	{
		SpriteObj* axe = usingAxes.front();
		usingAxes.pop_front();
		unusingAxes.push_back(axe);
	}
}

void Player::Update(float dt)
{
	SpriteObj::Update(dt);
	while (usingAxes.size() < level / 10 + 1)
	{
		SpriteObj* axe = unusingAxes.front();
		unusingAxes.pop_front();
		usingAxes.push_back(axe);
	}
	int i = 0;
	const double PI = 3.141592;
	axeAngle += dt;
	for (auto axes : usingAxes)
	{
		axes->SetPos(Vector2f(position.x + 200 * cos(2 * PI / usingAxes.size() * i + axeAngle * 10 / (2 * PI)), position.y + 200 * sin(2 * PI / usingAxes.size() * i + axeAngle * 10 / (2 * PI))));
		axes->SetRotation(axeAngle * 500);
		axes->Update(dt);
	}
}

void Player::Draw(RenderWindow& window)
{
	SpriteObj::Draw(window);
	for (auto axes : usingAxes)
	{
		axes->Draw(window);
	}
}

bool Player::OnCollision(const FloatRect& rect)
{
	return false;
}

bool Player::OnCollisionAxe(const FloatRect& rect)
{
	return false;
}

bool Player::OnCollisionPlayer(const FloatRect& rect)
{
	return false;
}
