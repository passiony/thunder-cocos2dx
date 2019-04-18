#ifndef __Enemy_H__
#define __Enemy_H__

#include "cocos2d.h"
USING_NS_CC;

class Enemy :public cocos2d::Sprite
{
public:
	Enemy();
	static Enemy* createWithSpriteFrameName(const char *frameName);

	//update·½·¨
	virtual void update(float delta);
	void Fire();
	void onDelay(float a);
};

#endif