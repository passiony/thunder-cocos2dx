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
	/**�����¼�*/
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);//������ʼ
	listener1->onTouchMoved = CC_CALLBACK_2(Player::onTouchMove,this);
	listener1->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);//��������

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

	////����update
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
	//�����ӵ�
	Bullet* bullet = Bullet::createWithSpriteFrameName("bullet1.png");
	bullet->setPosition(this->getPosition());
	this->getParent()->addChild(bullet,2);

	//��������
	auto physicsBody = PhysicsBody::createBox(bullet->getContentSize(),
		PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setTag(16);

	physicsBody->setCategoryBitmask(16);//����10000
	physicsBody->setCollisionBitmask(0);//��ײ101000
	physicsBody->setContactTestBitmask(8);//�Ӵ�

	bullet->addComponent(physicsBody);
	physicsBody->setVelocity(Vec2(0,300));

}