
#ifndef __Lesson01_SCENE_H__
#define __Lesson01_SCENE_H__

#include "cocos2d.h"

//¼Ì³Ð×Óscene³¡¾°
class Lesson01 : public cocos2d::Scene
{
private:
	cocos2d::Sprite* MyBoy;
	cocos2d::Sprite* Hello;
	cocos2d::Vec2 Center;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Lesson01);
};

#endif // __HELLOWORLD_SCENE_H__
