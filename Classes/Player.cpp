#include "Player.h"
#include "Bullet.h"

Player* Player::createWithSpriteFrameName(const char *frameName)
{
	Player* p = new Player;
	if (p && p->initWithSpriteFrameName(frameName))
	{
		p->autorelease();
		return p;
	}
	CC_SAFE_DELETE(p);
	return nullptr;
}

Player::Player()
{
	/**触摸事件*/
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);//触摸开始
	listener1->onTouchMoved = CC_CALLBACK_2(Player::onTouchMove,this);
	listener1->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);//触摸结束

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

	////开启update
	this->scheduleUpdate();
}

bool Player::onTouchBegan(Touch* touch, Event* event) {
	return true;
}
void Player::onTouchEnded(Touch* touch, Event* event) {}
void Player::onTouchMove(Touch* touch, Event* event)
{
	Vec2 point = touch->getLocation();
	this->setPosition(point);
}

void Player::update(float delta)
{
	elapse += delta;
	if (elapse > interval)
	{
		elapse = 0;
		this->Fire();
	}
}

void Player::Fire()
{
	//创建子弹
	Bullet* bullet = Bullet::createWithSpriteFrameName("bullet1.png");
	bullet->setPosition(this->getPosition());
	this->getParent()->addChild(bullet,2);

	//创建刚体
	auto physicsBody = PhysicsBody::createBox(bullet->getContentSize(),
		PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setTag(16);

	physicsBody->setCategoryBitmask(16);//种类10000
	physicsBody->setCollisionBitmask(0);//碰撞101000
	physicsBody->setContactTestBitmask(8);//接触

	bullet->addComponent(physicsBody);
	physicsBody->setVelocity(Vec2(0,300));

}