//
//  Controller.cpp
//  proto1
//
//  Created by yy on 13/07/02.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

using namespace cocos2d;

CCScene *Controller::scene() {
    CCScene *scene = CCScene::create();
    Controller *layer = Controller::create();
    scene->addChild(layer);
    
    return scene;
}

bool Controller::init() {
    if (!CCLayer::init()) {
        return false;
    }
    this->setTouchMode(kCCTouchesAllAtOnce);
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    this->mSprite = pSprite;
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    this->addChild(pSprite, 0);
    
    return true;
}

void Controller::onEnter() {
    //デリゲートの設定
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}

void Controller::onExit() {
    //デリゲートの解除
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

/*
bool Controller::ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ開始
    this->mSprite->initWithFile("Icon-72.png");

    CCPoint point = ptouch->getLocationInView();
    this->displayTouchPoint(0, 0);
    this->startPoint = point;
    return true;
}

void Controller::ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ中
    CCPoint point = ptouch->getLocationInView();
    
    this->displayTouchPoint(point.x - this->startPoint.x, point.y - this->startPoint.y);
    
}

void Controller::ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
        //タッチ終了
        removeChild(this->pointLabel);
    }

void Controller::ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
        puts("touch cancel");
        //タッチキャンセル
    }
*/
// /*
void Controller::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *pEvent) {
    CCTouch* touch;
    for (CCSetIterator it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if (!touch)
            break;
        this->mSprite->initWithFile("Icon-72.png");
        this->displayTouchPoint(0, 0);
        CCPoint point = touch->getLocationInView();
        this->startPoint = point;
    }
}

void Controller::ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *pEvent) {
    CCTouch* touch;
    for (CCSetIterator it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if (!touch)
            break;
        CCPoint point = touch->getLocationInView();
        this->displayTouchPoint(point.x - this->startPoint.x, point.y - this->startPoint.y);
    }
}

void Controller::ccTouchesEnded(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent) {
    removeChild(this->pointLabel);
}

void Controller::ccTouchesCancelled(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent) {
}

void Controller::displayTouchPoint(float point_x, float point_y) {
    // 座標を取得して文字列に格納
    char str[100];
    sprintf(str, "(%3.0f, %3.0f)", point_x, point_y);
    
    removeChild(this->pointLabel);
    this->pointLabel = CCLabelTTF::create(str, "Thonburi", 34);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    this->pointLabel->setPosition( ccp(size.width / 2, size.height - 20) );
    
    this->addChild(this->pointLabel, 1);
}

