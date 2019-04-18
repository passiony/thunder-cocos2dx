
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"
USING_NS_CC;

class Bullet :public cocos2d::Sprite
{
public:
	cocos2d::PhysicsBody* physicsBody;
	Bullet();
	static Bullet* createWithSpriteFrameName(const char *frameName);
	void Fly();
	void onDelay(float a);
};

#endif