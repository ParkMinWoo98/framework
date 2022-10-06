#pragma once
#include "SpriteObj.h"
#include <list>

using namespace std;

class Player : public SpriteObj
{
protected:
	int level;
	float exp;
	float lvUpExp;
	float hp;

	float axeAngle;
	list<SpriteObj*> usingAxes;
	list<SpriteObj*> unusingAxes;

public:
	Player();
	virtual ~Player();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	bool OnCollision(const FloatRect& rect);
	bool OnCollisionAxe(const FloatRect& rect);
	bool OnCollisionPlayer(const FloatRect& rect);
};

