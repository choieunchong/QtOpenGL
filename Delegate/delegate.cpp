#include "delegate.h"
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QSpinBox>


Delegate::Delegate(QObject *parent): QItemDelegate(parent)
{

}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                const QModelIndex &index)const{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex& index)const{
    int value = index.model()->data(index,Qt::EditRole).toInt();

    QSpinBox *spinbox = static_cast<QSpinBox*>(editor);
    spinbox->setValue(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *modle,
                            const QModelIndex &index)const{
    QSpinBox *spinbox = static_cast<QSpinBox*>(editor);
    spinbox->interpretText();
    int value = spinbox->value();
    modle->setData(index, value, Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
