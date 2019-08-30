#ifndef WIDGET_H
#define WIDGET_H

#include <QPicture>
#include <QWidget>
#include <QPainter>
#include <QGraphicsEffect>
#include <QGraphicsView>
#include <QList>
#include <QString>
#include "node.h"
#include "struct.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

private:
    Ui::Form *ui;
    Struct1 *inner;

public:
    explicit Form(Struct1*, QWidget *parent = 0);
    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsItem* item;
    QList<QGraphicsSimpleTextItem*>* list2;
    QList<QGraphicsItem*>* list1;
    QString string;
    char temp[3];
    ~Form();
    void create_null();
    void draw_tree();
    void add_node(int, int, int);
    void del_all();
    void view_in_console(Node*, int);

private slots:
    void set_pos();
    void call_del_func();
    void call_del_test();
    void call_add_func();
    void update_table();
    void console();

};

#endif // WIDGET_H
