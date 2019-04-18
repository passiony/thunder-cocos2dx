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
	//��ʾ����������Խ��� --- �к��
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	scene->addChild(GameScene::create());
	return scene;
}

bool GameScene::init()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//����һ����������, ��С����Ļ�ĳߴ���ͬ, ʹ��Ĭ�ϲ���, debug��Ŀ��Ϊ3������
	//auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	//auto edgeShape = Node::create();
	//edgeShape->setPhysicsBody(body);
	//edgeShape->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	//body->setCategoryBitmask(8);//����10000
	//body->setCollisionBitmask(16);//��ײ101000
	//body->setContactTestBitmask(16);//�Ӵ�
	//this->addChild(edgeShape);

	//������ʾ
	scoreLabel = Label::createWithSystemFont("Score 0", "Arial", 16);
	//scoreLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 24);
	scoreLabel->setPosition(Vec2(origin.x + visibleSize.width/2- scoreLabel->getContentSize().width/2,
		origin.y + visibleSize.height - scoreLabel->getContentSize().height));
	this->addChild(scoreLabel, 5);

	//��ӱ���
	Sprite* beigjing = Sprite::createWithSpriteFrameName("background_2.png");
	beigjing->setPosition(origin + Vec2(visibleSize.width/2,visibleSize.height/2));
	this->addChild(beigjing,0);


	//�������
	Player* player = Player::createWithSpriteFrameName("hero_fly_1.png");
	player->setPosition(origin + Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(player,1);


	//������ײ
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::OnCollision,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//���������
	srand((unsigned)time(nullptr));

	////����update
	this->scheduleUpdate();
	return true;
}

bool GameScene::OnCollision(PhysicsContact& contact)
{
	//��ȡ��ײ����������
	auto body1 = contact.getShapeA()->getBody();
	auto body2 = contact.getShapeB()->getBody();

	//Tag���24��˵�����ӵ����ел�
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
		//������˳���λ��
		float posx= rand() % (int)visibleSize.width;
		enemy->setPosition(posx, visibleSize.height - enemy->getContentSize().height / 2);
		this->addChild(enemy, 2);
		//��������
		auto physicsBody = PhysicsBody::createBox(enemy->getContentSize(),
			PhysicsMaterial(0.1f, 1.0f, 0.0f));
		physicsBody->setGravityEnable(false);
		physicsBody->setTag(8);
		//���ò㼶
		physicsBody->setCategoryBitmask(8);//����10000
		physicsBody->setCollisionBitmask(0);//��ײ101000
		physicsBody->setContactTestBitmask(16);//�Ӵ�

		//�󶨸���
		enemy->addComponent(physicsBody);
		//�л��ķ���
		physicsBody->setVelocity(Vec2(0,-100));

	}
}