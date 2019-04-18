
#include "Lesson01.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;//相当于引入cocos2d命名空间

template <typename T> std::string tostr(const T& t) { std::ostringstream os; os << t; return os.str(); }

Scene* Lesson01::createScene()
{
    return Lesson01::create();//宏定义定义的create方法
}


//初始化场景的内部逻辑
bool Lesson01::init()
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


	   // 3.创建一个按钮
	   auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
	   	CC_CALLBACK_1(Lesson01::menuCloseCallback, this));

	   // 4.设置按钮的位置
	   float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
	   float y = origin.y + closeItem->getContentSize().height/2;
	   closeItem->setPosition(Vec2(x,y));
	   

	   // 5.创建一个menu，所有的菜单按钮必须都加到这个总menu上，否则不能点击
	   auto menu = Menu::create(closeItem, NULL);
	   menu->setPosition(Vec2::ZERO);
	   this->addChild(menu, 1);//添加节点到场景

	  
	   //6.创建一个lable（text）文本
	   auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	   label->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y + visibleSize.height - label->getContentSize().height));
	   this->addChild(label, 1);//

	   // 7.创建精灵
	   auto boy = Sprite::create("Character.png");
	   boy->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height / 2 + origin.y));
	   boy->setScale(2);
	   this->addChild(boy,2);
	   MyBoy = boy;

	   /**顺序执行动作*/
	   //auto move1 = MoveTo::create(2, Vec2(visibleSize.width + origin.x, visibleSize.height / 2));
	   //auto move2 = MoveTo::create(2,Vec2(origin.x,visibleSize.height/2));
	   //auto seqence = Sequence::create(move1,move2,nullptr);

	   /**并行执行动作*/
	   //auto moveTo1 = MoveTo::create(2, Vec2(50, 10));
	   //auto moveBy1 = MoveBy::create(2, Vec2(100, 10));
	   //auto moveTo2 = MoveTo::create(2, Vec2(150, 10));
	   //auto sqawn = Spawn::create(moveTo1, moveBy1, moveTo2, nullptr);
	   //boy->runAction(sqawn);

		/**字体描边和外放光*/
	   //auto myLabel = Label::createWithTTF("My Label Text","fonts/Marker Felt.ttf", 100);
	   //myLabel->setPosition(Vec2(origin.x+ visibleSize.width/ 2, visibleSize.height / 2 + origin.y));
	   //this->addChild(myLabel, 2);
	   //myLabel->enableGlow(Color4B::YELLOW);
	   //myLabel->enableOutline(Color4B::YELLOW,5);

	   /**粒子系统*/
	   //auto emitter = ParticleFireworks::create();
	   //emitter->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y));
	   //addChild(emitter, 10);


	   /**触摸事件*/
	   //auto listener1 = EventListenerTouchOneByOne::create();
	   //listener1->onTouchBegan = [](Touch* touch, Event* event) {

	   //	log("Touch Begin");
	   //	return true;
	   //};
	   //listener1->onTouchMoved = [](Touch* touch, Event* event) {
	   //	log("Touch Moved");

	   //	Vec2 point = touch->getLocation();
	   //	std::string str = tostr(point.x) + ":" + tostr(point.y);
	   //	log(str.c_str());

	   //	//我的矩形区域是否包含了鼠标点
	   //	//if (MyBoy->getBoundingBox().containsPoint(touch->getLocation()))
	   //	//{
	   //	//	log("mouse touched boy");
	   //	//}
	   //	MyBoy->setPosition(touch->getLocation());
	   //	//我的举行区域是否包含 另一个矩形//判断两个精灵是否相交
	   //	if (MyBoy->getBoundingBox().intersectsRect(Hello->getBoundingBox())){
	   //		log("boy touched hello");
	   //	}};
	   //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	   

	   /**键盘事件*/
	   //auto listener2 = EventListenerKeyboard::create();
	   //listener2->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
	   //	log("Key with keycode %d pressed", keyCode);
	   //};
	   //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);


	   /**鼠标移动*/
	   //auto _mouseListener = EventListenerMouse::create();
	   //_mouseListener->onMouseMove = [](EventMouse* em) {
		  // em->getLocation();
	   //		log("mouseMove");
	   //};
	   //_mouseListener->onMouseUp = CC_CALLBACK_1(Lesson01::onMouseUp, this);
	   //_mouseListener->onMouseDown = CC_CALLBACK_1(Lesson01::onMouseDown, this);
	   //_mouseListener->onMouseScroll = CC_CALLBACK_1(Lesson01::onMouseScroll, this);
	   //_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	  
	return true;
}

//按钮的回调事件
void Lesson01::menuCloseCallback(Ref* pSender)
{
	log("按钮点击");
}
