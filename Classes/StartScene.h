
#ifndef __StartScene_SCENE_H__
#define __StartScene_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(StartScene);
};

#endif // __HELLOWORLD_SCENE_H__
