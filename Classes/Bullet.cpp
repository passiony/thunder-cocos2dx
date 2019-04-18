#include "Bullet.h"

const int BULLET_TAG =1;
float speed = 10;

Bullet* Bullet::createWithSpriteFrameName(const char *frameName)
{
	Bullet* p = new Bullet();
	if (p && p->initWithSpriteFrameName(frameName))
	{
		p->autorelease();
		return p;
	}
	CC_SAFE_DELETE(p);
	return nullptr;
}

Bullet::Bullet()
{
	this->scheduleOnce(schedule_selector(Bullet::onDelay), 2.0f);
}

void Bullet::Fly()
{
	//physicsBody->setVelocity(Vec2(0, 1));

}
void Bullet::onDelay(float a)
{
	this->removeFromParentAndCleanup(true);
}