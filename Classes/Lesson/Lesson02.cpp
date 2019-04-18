#include "Lesson02.h"

USING_NS_CC;
#define DRAG_BODYS_TAG 10

Scene* Lesson02::createScene()
{
	auto scene = Scene::createWithPhysics();
	//显示物理引擎调试界面 --- 有红框
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

	// 2.获取屏幕大小
	visibleSize = Director::getInstance()->getVisibleSize();
	//获取屏幕中轴点
	origin = Director::getInstance()->getVisibleOrigin();
	//计算中心点
	center = Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y);


	//创建一个物理世界, 大小和屏幕的尺寸相同, 使用默认材质, debug框的宽度为3个像素
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	//创建一个碰撞图形
	auto edgeShape = Node::create();
	//将图形和刚刚创建的世界绑定
	edgeShape->setPhysicsBody(body);
	//设置图形的位置在屏幕正中间
	edgeShape->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//添加进图层
	this->addChild(edgeShape);


	//create a sprite
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(center);
	sprite->setScale(0.5);
	addChild(sprite);

	//添加中心静态的刚体
	auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(),
		PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setCategoryBitmask(8);//种类
	physicsBody->setCollisionBitmask(16);//碰撞
	physicsBody->setContactTestBitmask(16);//接触
	//把刚体应用给精灵
	sprite->addComponent(physicsBody);

	//添加碰撞事件
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [](PhysicsContact& contact) {
		log("OnCollision");
		//auto nodeA = contact.getShapeA()->getBody()->getNode();
		//auto nodeB = contact.getShapeB()->getBody()->getNode();
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	////开启update
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


		//创建精灵
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

		physicsBody->setCategoryBitmask(16);//种类10000
		physicsBody->setCollisionBitmask(8);//碰撞101000
		physicsBody->setContactTestBitmask(8);//接触

		sprite->addComponent(physicsBody);
		addChild(sprite);
	}
}
