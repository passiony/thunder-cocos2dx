#include "Enemy.h"



Enemy* Enemy::createWithSpriteFrameName(const char *frameName)
{
	Enemy* p = new Enemy();
	if (p && p->initWithSpriteFrameName(frameName))
	{
		p->autorelease();
		return p;
	}
	CC_SAFE_DELETE(p);
	return nullptr;
}

Enemy::Enemy()
{
	this->scheduleOnce(schedule_selector(Enemy::onDelay), 8.0f);
}
//update·½·¨
void Enemy::update(float delta)
{

}
void Enemy::Fire()
{

}
void Enemy::onDelay(float a)
{
	this->removeFromParentAndCleanup(true);
}