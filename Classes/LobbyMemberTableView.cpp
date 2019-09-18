//
// Created by edge on 2019-09-15.
//
#include "ui/CocosGUI.h"
#include "ResolutionUtil.h"
#include "LobbyMemberTableView.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;

using std::string;


const string stateIcon[2] = {
        "green-dot.png",
        "gray-dot.png"
};

LobbyMemberTableView::LobbyMemberTableView() {
    this->tableView = TableView::create(this, ResolutionUtil::getCorrespondSize(0.3f, 0.3f));
    tableView->setDirection(ScrollView::Direction::VERTICAL);
    tableView->setDelegate(this);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    tableView->reloadData();
    this->setContentSize(tableView->getBoundingBox().size);
    this->addChild(tableView);
}

LobbyMemberTableView *LobbyMemberTableView::create() {
    LobbyMemberTableView *widget = new(std::nothrow) LobbyMemberTableView();
    if (widget && widget->init()) {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

void LobbyMemberTableView::tableCellTouched(TableView *table, TableViewCell *cell) {
    ssize_t idx = cell->getIdx();
    log("cell touched at index: %ld", idx);

}

Size LobbyMemberTableView::tableCellSizeForIndex(TableView *table, ssize_t idx) {
    return ResolutionUtil::getCorrespondSize(0.3f, 0.1f);
}

//由于tableview是动态获取数据的，该方法在初始化时会被调用一次，之后在每个隐藏的cell显示出来的时候都会调用
TableViewCell *LobbyMemberTableView::tableCellAtIndex(TableView *table, ssize_t idx) {
    std::string index = std::to_string(idx);

    // 在重用队列中获取一个cell 然后判断cell是否为空 不为空则创建一个新的
    TableViewCell *cell = table->dequeueCell();

    if (!cell) {
        cell = new TableViewCell();
        cell->autorelease();
        cell->setContentSize(ResolutionUtil::getCorrespondSize(0.3f, 0.1f));

        auto cellBackground = Sprite::create("background-layer.png");
        cellBackground->setAnchorPoint(Vec2::ZERO);
        cellBackground->setContentSize(Size(cell->getBoundingBox().size.width, cell->getBoundingBox().size.height));
        cell->addChild(cellBackground);

        auto iconSprite = Sprite::create("user-icon.png");
        iconSprite->setPosition(ResolutionUtil::getCorrespondPosition(0.02f, 0.05f));
        iconSprite->setScale(0.1f);
        cell->addChild(iconSprite);

        auto usernameText = ui::Text::create(std::to_string(loungeInfoList[idx].getId()), "fonts/arial.ttf", 20.0);
        usernameText->setPosition(ResolutionUtil::getCorrespondPosition(0.07f, 0.05f));
        //为标签做一个标记,以便于在cell在重用队列中被取出来时，能够获取的该label并重置label信息
        usernameText->setTag((int) idx);
        //将标签加入到cell中
        cell->addChild(usernameText);

        string stateIconFilename = stateIcon[loungeInfoList[idx].isReady()];
        auto stateSprite = Sprite::create(stateIconFilename);
        stateSprite->setScale(0.1f);
        stateSprite->setPosition(ResolutionUtil::getCorrespondPosition(0.28f, 0.05f));
        cell->addChild(stateSprite);

    } else {
        // 如果cell不为空,则根据tag获取到之前cell中存放的元素,并将元素信息重置
        //获取当前cell中的label
        auto usernameText = (ui::Text *) cell->getChildByTag((int) idx);
        usernameText->setString(std::to_string(loungeInfoList[idx].getId()));
    }
    return cell;
}

ssize_t LobbyMemberTableView::numberOfCellsInTableView(TableView *table) {
    return loungeInfoList.size();
}

void LobbyMemberTableView::reloadData() {
    tableView->reloadData();
}

const std::vector<LoungeInfo> &LobbyMemberTableView::getLoungeInfoList() const {
    return loungeInfoList;
}

void LobbyMemberTableView::setLoungeInfoList(const std::vector<LoungeInfo> &loungeInfoList) {
    LobbyMemberTableView::loungeInfoList = loungeInfoList;
}

bool LobbyMemberTableView::init() {
    if (Widget::init()) {
        return true;
    }
    return false;
}