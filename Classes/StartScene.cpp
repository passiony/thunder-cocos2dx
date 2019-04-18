
#include "StartScene.h"
#include "GameScene.h"

USING_NS_CC;//相当于引入cocos2d命名空间

template <typename T> std::string tostr(const T& t) { std::ostringstream os; os << t; return os.str(); }

Sprite* MyBoy;
Sprite* Hello;
Vec2 Center;

Scene* StartScene::createScene()
{
	return StartScene::create();//宏定义定义的create方法
}

//初始化场景的内部逻辑
bool StartScene::init()
{
	// 1.调用父类的初始化方法
	if (!Scene::init())
	{
		return false;
	}

	// 2.获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//获取屏幕中轴点
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//添加背景
	Sprite* beigjing = Sprite::createWithSpriteFrameName("background_2.png");
	beigjing->setPosition(origin + Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(beigjing, 0);

	//开始游戏按钮
	auto startGame = MenuItemFont::create("Start Game",
		CC_CALLBACK_1(StartScene::menuCallback, this));
	startGame->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));


	// 5.创建一个menu，所有的菜单按钮必须都加到这个总menu上，否则不能点击
	auto menu = Menu::create(startGame, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);//添加节点到场景
	return true;
}

//按钮的回调事件
void StartScene::menuCallback(Ref* pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
