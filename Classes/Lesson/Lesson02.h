
#ifndef __Lesson02_SCENE_H__
#define __Lesson02_SCENE_H__

#include "cocos2d.h"

class Lesson02 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Lesson02);
	virtual void update(float delta);

	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Vec2 center;
};

#endif 