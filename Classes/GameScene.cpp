#include "GameScene.h"
#include "Player.h"
#include "Enemy.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	//显示物理引擎调试界面 --- 有红框
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	scene->addChild(GameScene::create());
	return scene;
}

bool GameScene::init()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//创建一个物理世界, 大小和屏幕的尺寸相同, 使用默认材质, debug框的宽度为3个像素
	//auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	//auto edgeShape = Node::create();
	//edgeShape->setPhysicsBody(body);
	//edgeShape->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	//body->setCategoryBitmask(8);//种类10000
	//body->setCollisionBitmask(16);//碰撞101000
	//body->setContactTestBitmask(16);//接触
	//this->addChild(edgeShape);

	//分数显示
	scoreLabel = Label::createWithSystemFont("Score 0", "Arial", 16);
	//scoreLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 24);
	scoreLabel->setPosition(Vec2(origin.x + visibleSize.width/2- scoreLabel->getContentSize().width/2,
		origin.y + visibleSize.height - scoreLabel->getContentSize().height));
	this->addChild(scoreLabel, 5);

	//添加背景
	Sprite* beigjing = Sprite::createWithSpriteFrameName("background_2.png");
	beigjing->setPosition(origin + Vec2(visibleSize.width/2,visibleSize.height/2));
	this->addChild(beigjing,0);


	//添加主角
	Player* player = Player::createWithSpriteFrameName("hero_fly_1.png");
	player->setPosition(origin + Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(player,1);


	//开启碰撞
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::OnCollision,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//随机数种子
	srand((unsigned)time(nullptr));

	////开启update
	this->scheduleUpdate();
	return true;
}

bool GameScene::OnCollision(PhysicsContact& contact)
{
	//获取碰撞的两个刚体
	auto body1 = contact.getShapeA()->getBody();
	auto body2 = contact.getShapeB()->getBody();

	//Tag相加24，说明是子弹打中敌机
	if (body1->getTag() + body2->getTag() == 24)
	{
		body1->getNode()->removeFromParentAndCleanup(true);
		body2->getNode()->removeFromParentAndCleanup(true);
	}

	score++;
	CCString* cs = CCString::createWithFormat("Score %d",score);
	this->scoreLabel->setString(cs->getCString());
	return true;
}

void GameScene::update(float delta)
{
	elapse += delta;
	if (elapse > 2)
	{
		elapse = 0;

		Enemy* enemy = Enemy::createWithSpriteFrameName("enemy1_blowup_1.png");
		//随机敌人出现位置
		float posx= rand() % (int)visibleSize.width;
		enemy->setPosition(posx, visibleSize.height - enemy->getContentSize().height / 2);
		this->addChild(enemy, 2);
		//创建刚体
		auto physicsBody = PhysicsBody::createBox(enemy->getContentSize(),
			PhysicsMaterial(0.1f, 1.0f, 0.0f));
		physicsBody->setGravityEnable(false);
		physicsBody->setTag(8);
		//设置层级
		physicsBody->setCategoryBitmask(8);//种类10000
		physicsBody->setCollisionBitmask(0);//碰撞101000
		physicsBody->setContactTestBitmask(16);//接触

		//绑定刚体
		enemy->addComponent(physicsBody);
		//敌机的飞行
		physicsBody->setVelocity(Vec2(0,-100));

	}
}