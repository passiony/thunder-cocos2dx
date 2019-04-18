
#ifndef __GameScene_H__
#define __GameScene_H__

#include "cocos2d.h"
USING_NS_CC;

class GameScene :public Layer
{
private:
	int score = 0;//����
	float elapse = 0;//��ʱ��
	Size visibleSize;
	Vec2 origin;
	cocos2d::Label * scoreLabel;	//����
public:
	bool OnCollision(PhysicsContact& contact);
	static cocos2d::Scene* createScene();
	bool init();
	void update(float delta);
	CREATE_FUNC(GameScene);
};

#endif
