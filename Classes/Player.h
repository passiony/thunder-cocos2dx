
#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
USING_NS_CC;

class Player :public cocos2d::Sprite
{
private:
	float interval = 1;
	float elapse = 0;
public:
	Player();
	static Player* createWithSpriteFrameName(const char *frameName);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onTouchMove(Touch* touch, Event* event);
	//update·½·¨
	virtual void update(float delta);
	void Fire();
};

#endif