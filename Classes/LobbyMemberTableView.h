//
// Created by edge on 2019-09-15.
//

#ifndef BANG_LOBBYMEMBERTABLEVIEW_H
#define BANG_LOBBYMEMBERTABLEVIEW_H

#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
#include <vo/LoungeInfo.h>

class LobbyMemberTableView
        : public ui::Widget, cocos2d::extension::TableViewDataSource, cocos2d::extension::TableViewDelegate {
public:
    LobbyMemberTableView();
    static LobbyMemberTableView *create();
    /* 必须实现的函数 */
    // 当滑动tableview时触发该方法 参数为当前的tableview对象
    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView *view) { }

    // 当tableview被放大或缩小时触发该方法  参数为当前tableview对象
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView *view) { }

    // 当cell被点击时调用该方法 参数为当前的tableview对象与被点击的cell对象
    virtual void tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell);

    // 设置tableview的Cell大小
    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx);

    // 获取编号为idx的cell
    virtual cocos2d::extension::TableViewCell *tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);

    // 设置tableview中cell的个数
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

    void reloadData();

    const std::vector<LoungeInfo> &getLoungeInfoList() const;

    void setLoungeInfoList(const std::vector<LoungeInfo> &loungeInfoList);

CC_CONSTRUCTOR_ACCESS:
    virtual bool init() override;

protected:
    cocos2d::extension::TableView *tableView;
private:
    std::vector<LoungeInfo> loungeInfoList;
};


#endif //BANG_LOBBYMEMBERTABLEVIEW_H
