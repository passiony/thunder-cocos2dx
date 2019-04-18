
#include "Lesson01.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;//�൱������cocos2d�����ռ�

template <typename T> std::string tostr(const T& t) { std::ostringstream os; os << t; return os.str(); }

Scene* Lesson01::createScene()
{
    return Lesson01::create();//�궨�嶨���create����
}


//��ʼ���������ڲ��߼�
bool Lesson01::init()
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


	   // 3.����һ����ť
	   auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
	   	CC_CALLBACK_1(Lesson01::menuCloseCallback, this));

	   // 4.���ð�ť��λ��
	   float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
	   float y = origin.y + closeItem->getContentSize().height/2;
	   closeItem->setPosition(Vec2(x,y));
	   

	   // 5.����һ��menu�����еĲ˵���ť���붼�ӵ������menu�ϣ������ܵ��
	   auto menu = Menu::create(closeItem, NULL);
	   menu->setPosition(Vec2::ZERO);
	   this->addChild(menu, 1);//��ӽڵ㵽����

	  
	   //6.����һ��lable��text���ı�
	   auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	   label->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y + visibleSize.height - label->getContentSize().height));
	   this->addChild(label, 1);//

	   // 7.��������
	   auto boy = Sprite::create("Character.png");
	   boy->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height / 2 + origin.y));
	   boy->setScale(2);
	   this->addChild(boy,2);
	   MyBoy = boy;

	   /**˳��ִ�ж���*/
	   //auto move1 = MoveTo::create(2, Vec2(visibleSize.width + origin.x, visibleSize.height / 2));
	   //auto move2 = MoveTo::create(2,Vec2(origin.x,visibleSize.height/2));
	   //auto seqence = Sequence::create(move1,move2,nullptr);

	   /**����ִ�ж���*/
	   //auto moveTo1 = MoveTo::create(2, Vec2(50, 10));
	   //auto moveBy1 = MoveBy::create(2, Vec2(100, 10));
	   //auto moveTo2 = MoveTo::create(2, Vec2(150, 10));
	   //auto sqawn = Spawn::create(moveTo1, moveBy1, moveTo2, nullptr);
	   //boy->runAction(sqawn);

		/**������ߺ���Ź�*/
	   //auto myLabel = Label::createWithTTF("My Label Text","fonts/Marker Felt.ttf", 100);
	   //myLabel->setPosition(Vec2(origin.x+ visibleSize.width/ 2, visibleSize.height / 2 + origin.y));
	   //this->addChild(myLabel, 2);
	   //myLabel->enableGlow(Color4B::YELLOW);
	   //myLabel->enableOutline(Color4B::YELLOW,5);

	   /**����ϵͳ*/
	   //auto emitter = ParticleFireworks::create();
	   //emitter->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y));
	   //addChild(emitter, 10);


	   /**�����¼�*/
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

	   //	//�ҵľ��������Ƿ����������
	   //	//if (MyBoy->getBoundingBox().containsPoint(touch->getLocation()))
	   //	//{
	   //	//	log("mouse touched boy");
	   //	//}
	   //	MyBoy->setPosition(touch->getLocation());
	   //	//�ҵľ��������Ƿ���� ��һ������//�ж����������Ƿ��ཻ
	   //	if (MyBoy->getBoundingBox().intersectsRect(Hello->getBoundingBox())){
	   //		log("boy touched hello");
	   //	}};
	   //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	   

	   /**�����¼�*/
	   //auto listener2 = EventListenerKeyboard::create();
	   //listener2->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
	   //	log("Key with keycode %d pressed", keyCode);
	   //};
	   //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);


	   /**����ƶ�*/
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

//��ť�Ļص��¼�
void Lesson01::menuCloseCallback(Ref* pSender)
{
	log("��ť���");
}
