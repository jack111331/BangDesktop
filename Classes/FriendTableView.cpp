//
// Created by edge on 2019-09-15.
//
#include "ui/CocosGUI.h"
#include "FriendTableView.h"
#include "ResolutionUtil.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;

bool FriendTableView::init() {
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    //创建一个talbleview 将datasource设置为当前的类的对象 tableview的显示区域大小为 300 * 300
    this->tableView = TableView::create(this, ResolutionUtil::getCorrespondSize(0.3f, 0.3f));
    tableView->setDirection(ScrollView::Direction::VERTICAL);
    tableView->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
    //设置代理对象
    tableView->setDelegate(this);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    //添加tableview到当前layer
    this->addChild(tableView);
    //加载tableview
    tableView->reloadData();

    return true;
}

void FriendTableView::tableCellTouched(TableView *table, TableViewCell *cell) {
    log("cell touched at index: %ld", cell->getIdx());
    // Join room
}

Size FriendTableView::tableCellSizeForIndex(TableView *table, ssize_t idx) {
    return ResolutionUtil::getCorrespondSize(0.3f, 0.1f);
}

//由于tableview是动态获取数据的，该方法在初始化时会被调用一次，之后在每个隐藏的cell显示出来的时候都会调用
TableViewCell *FriendTableView::tableCellAtIndex(TableView *table, ssize_t idx) {
    std::string index = std::to_string(idx);

    // 在重用队列中获取一个cell 然后判断cell是否为空 不为空则创建一个新的
    TableViewCell *cell = table->dequeueCell();

    if (!cell) {
        //创建一个新的cell
        cell = new TableViewCell();
        //加入到自动释放池中
        cell->autorelease();
        cell->setContentSize(ResolutionUtil::getCorrespondSize(0.3f, 0.1f));

        auto cellBackground = Sprite::create("background-layer.png");
        cellBackground->setAnchorPoint(Vec2::ZERO);
        cellBackground->setContentSize(Size(cell->getBoundingBox().size.width, cell->getBoundingBox().size.height));
        cell->addChild(cellBackground);

        //创建一个图片精灵
        Sprite *sprite = Sprite::create("user-icon.png");
        //设置精灵锚点为左下角
        sprite->setAnchorPoint(Vec2::ZERO);
        //设置精灵位置 相当于在cell中的相对位置
        sprite->setPosition(Vec2(0, 0));
        //将精灵加入到cell中
        sprite->setScale(0.1f);
        cell->addChild(sprite);

        //创建一个标签
        auto label = ui::Text::create(friendInfoList[idx].getUsername(), "Helvetica", 20.0);
        //设置标签相对cell的位置
        label->setPosition(Vec2::ZERO);
        //设置标签锚点为左下角
        label->setAnchorPoint(Vec2::ZERO);
        //为标签做一个标记,以便于在cell在重用队列中被取出来时，能够获取的该label并重置label信息
        label->setTag((int)idx);
        //将标签加入到cell中
        cell->addChild(label);
    } else {
        // 如果cell不为空,则根据tag获取到之前cell中存放的元素,并将元素信息重置
        //获取当前cell中的label
        auto label = (ui::Text *) cell->getChildByTag((int)idx);
        //重置label的相关信息
        label->setString(friendInfoList[idx].getUsername());
    }
    return cell;
}

//设置cell的个数 即一个tableview中包含了20个cell
ssize_t FriendTableView::numberOfCellsInTableView(TableView *table) {
    return friendInfoList.size();
}

const std::vector<FriendInfo> &FriendTableView::getFriendInfoList() const {
    return friendInfoList;
}

void FriendTableView::setFriendInfoList(const std::vector<FriendInfo> &friendInfoList) {
    FriendTableView::friendInfoList = friendInfoList;
}
void FriendTableView::reloadData() {
    tableView->reloadData();
}