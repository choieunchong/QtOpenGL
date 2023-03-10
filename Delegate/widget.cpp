#include "widget.h"
#include "delegate.h"
#include <QTableView>
#include <QStandardItem>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStandardItemModel* model = new QStandardItemModel(4,2,this);
    Delegate *delegate = new Delegate(this);

    for(int row =0; row<4; ++row)
        for(int column =0; column <2; ++column){
            QModelIndex index = model->index(row, column, QModelIndex());
            model->setData(index, row+column*2);
        }
    QTableView *table = new QTableView(this);
    table->setModel(model);
    table->setItemDelegate(delegate);
}

Widget::~Widget()
{
}

