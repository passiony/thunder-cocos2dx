
#include "StartScene.h"
#include "GameScene.h"

USING_NS_CC;//�൱������cocos2d�����ռ�

template <typename T> std::string tostr(const T& t) { std::ostringstream os; os << t; return os.str(); }

Sprite* MyBoy;
Sprite* Hello;
Vec2 Center;

Scene* StartScene::createScene()
{
	return StartScene::create();//�궨�嶨���create����
}

//��ʼ���������ڲ��߼�
bool StartScene::init()
{
	// 1.���ø���ĳ�ʼ������
	if (!Scene::init())
	{
		return false;
	}

	// 2.��ȡ��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//��ȡ��Ļ�����
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��ӱ���
	Sprite* beigjing = Sprite::createWithSpriteFrameName("background_2.png");
	beigjing->setPosition(origin + Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(beigjing, 0);

	//��ʼ��Ϸ��ť
	auto startGame = MenuItemFont::create("Start Game",
		CC_CALLBACK_1(StartScene::menuCallback, this));
	startGame->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));


	// 5.����һ��menu�����еĲ˵���ť���붼�ӵ������menu�ϣ������ܵ��
	auto menu = Menu::create(startGame, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);//��ӽڵ㵽����
	return true;
}

//��ť�Ļص��¼�
void StartScene::menuCallback(Ref* pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
