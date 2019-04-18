#include "Lesson02.h"

USING_NS_CC;
#define DRAG_BODYS_TAG 10

Scene* Lesson02::createScene()
{
	auto scene = Scene::createWithPhysics();
	//��ʾ����������Խ��� --- �к��
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto layer = Lesson02::create();
	scene->addChild(layer);
	return scene;
}

bool Lesson02::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// 2.��ȡ��Ļ��С
	visibleSize = Director::getInstance()->getVisibleSize();
	//��ȡ��Ļ�����
	origin = Director::getInstance()->getVisibleOrigin();
	//�������ĵ�
	center = Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y);


	//����һ����������, ��С����Ļ�ĳߴ���ͬ, ʹ��Ĭ�ϲ���, debug��Ŀ��Ϊ3������
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	//����һ����ײͼ��
	auto edgeShape = Node::create();
	//��ͼ�κ͸ոմ����������
	edgeShape->setPhysicsBody(body);
	//����ͼ�ε�λ������Ļ���м�
	edgeShape->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//��ӽ�ͼ��
	this->addChild(edgeShape);


	//create a sprite
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(center);
	sprite->setScale(0.5);
	addChild(sprite);

	//������ľ�̬�ĸ���
	auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(),
		PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setCategoryBitmask(8);//����
	physicsBody->setCollisionBitmask(16);//��ײ
	physicsBody->setContactTestBitmask(16);//�Ӵ�
	//�Ѹ���Ӧ�ø�����
	sprite->addComponent(physicsBody);

	//�����ײ�¼�
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [](PhysicsContact& contact) {
		log("OnCollision");
		//auto nodeA = contact.getShapeA()->getBody()->getNode();
		//auto nodeB = contact.getShapeB()->getBody()->getNode();
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	////����update
	this->scheduleUpdate();
	return true;
}

float startTime = 0;
void Lesson02::update(float delta)
{
	startTime += delta;
	if (startTime > 1)
	{
		log("Create");
		startTime = 0;


		//��������
		auto sprite = Sprite::create("HelloWorld.png");
		sprite->setPosition(Vec2(center.x + cocos2d::random(-300, 300),
			center.y + cocos2d::random(-300, 300)));
		sprite->setScale(0.5);


		auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(),
			PhysicsMaterial(0.1f, 1.0f, 0.0f));
		physicsBody->setGravityEnable(false);
		physicsBody->setVelocity(Vec2(cocos2d::random(-500, 500),
			cocos2d::random(-500, 500)));
		physicsBody->setTag(DRAG_BODYS_TAG);

		physicsBody->setCategoryBitmask(16);//����10000
		physicsBody->setCollisionBitmask(8);//��ײ101000
		physicsBody->setContactTestBitmask(8);//�Ӵ�

		sprite->addComponent(physicsBody);
		addChild(sprite);
	}
}
