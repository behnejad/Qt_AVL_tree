#include "widget.h"
#include "ui_form.h"
#include <qDebug>
#include <QStack>
#include <queue>
#include <vector>
#include <QQueue>
#include <stdio.h>
#include <QString>
#include "global.h"
#include "node.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

Form::Form(Struct* in, QWidget *parent)
    : QWidget(parent) , ui(new Ui::Form), inner(in)
{
    ui->setupUi(this);
    list1 = new QList<QGraphicsItem*>();
    list2 = new QList<QGraphicsSimpleTextItem*>();

    this->setGeometry(50,50, 50+470, 50+400);

    this->connect(ui->consoleb, SIGNAL(clicked()), this, SLOT(console()));
    this->connect(ui->testsub, SIGNAL(clicked()), this, SLOT(set_pos()));
    this->connect(ui->delbutton, SIGNAL(clicked()), this, SLOT(call_del_func()));
    this->connect(ui->testdel, SIGNAL(clicked()), this, SLOT(call_del_test()));
    this->connect(ui->addbutton, SIGNAL(clicked()), this, SLOT(call_add_func()));
    this->connect(ui->update, SIGNAL(clicked()), this, SLOT(update_table()));

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->resize(hooman::block*2, hooman::block);
    view->show();
    view->setRenderHint(QPainter::Antialiasing, true);
    view->setFrameStyle(QFrame::NoFrame);
    create_null();
}

void Form::view_in_console(Node * root, int level)
{
    if (root != 0)
    {
        view_in_console(root->right, level+1);
//        fprintf(stderr, "\n");
        string += "\n";
        if (root == inner->root)
//            fprintf(stderr, "Root -> ");
            string += "Root -> ";
        for (int i = 0 ; i < level && root != inner->root ; i++)
//            fprintf(stderr, "           ");
            string += "                 ";
//        fprintf(stderr, "%d",  root->getValue());
        itoa(root->getValue(), temp, 10);
        string += QString(temp);
        view_in_console(root->left, level+1);
    }
}

Form::~Form()
{
    delete ui;
}

void Form::update_table()
{
    this->del_all();
    this->draw_tree();
}

void Form::console()
{
    ui->textEdit->clear();
    string = "";
    view_in_console(inner->root, 0);
//    fprintf(stderr, "\n");
    string += "\n";
    ui->textEdit->setText(string);
}

void Form::create_null()
{
    int a[2] = {hooman::block-30, -(hooman::block-30)};
    int b[2] = {-(hooman::block/2-30), hooman::block/2-30};
    for (int i = 0 ; i < 2 ; i ++)
        for (int j = 0 ; j < 2 ; j++)
        {
            QRadialGradient radialGrad(210, 185, 15);
            radialGrad.setColorAt(0, Qt::black);
            QPixmap pixmap(20, 20);
            pixmap.fill(Qt::transparent);
            QPainter painter(&pixmap);
            painter.setPen(Qt::NoPen);
            painter.setBrush(radialGrad);
            painter.drawEllipse(0, 0, 20, 20);
            painter.end();
            item = scene->addPixmap(pixmap);
            item->setPos(a[i], b[j]);
        }
}

void Form::set_pos()
{
    QRadialGradient radialGrad(30, 30, 30);
    radialGrad.setColorAt(0, Qt::white);
    radialGrad.setColorAt(0.9999, Qt::blue);
    radialGrad.setColorAt(1, Qt::transparent);
//    pixmap.load(":/1.jpg");
    QPixmap pixmap(60, 60);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.setBrush(radialGrad);
    painter.drawEllipse(10, 10, 40, 40);
    painter.end();
    item = scene->addPixmap(pixmap);
    item->setPos(ui->testx->text().toInt(), ui->testy->text().toInt());
    list1->append(item);
    QGraphicsSimpleTextItem* label = scene->addSimpleText(ui->text->text(), QFont("Tahoma",10));
    ui->testy->clear();
    ui->testx->clear();
    ui->text->clear();
    list2->append(label);
    label->setParentItem(item);
    label->moveBy(item->boundingRect().width()/2 - label->boundingRect().width()/2,
                  item->boundingRect().height()/2 - label->boundingRect().height()/2);

}

void Form::add_node(int x, int y, int data)
{
    QRadialGradient radialGrad(30, 30, 30);
    radialGrad.setColorAt(0, Qt::white);
    radialGrad.setColorAt(0.999, Qt::blue);
    radialGrad.setColorAt(1, Qt::transparent);
    QPixmap pixmap(60, 60);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.setBrush(radialGrad);
    painter.drawEllipse(10, 10, 40, 40);
    painter.end();
    item = scene->addPixmap(pixmap);
    item->setPos(x, y);
    list1->append(item);
    char temp[5];
    itoa(data, temp, 10);
    QGraphicsSimpleTextItem* label = scene->addSimpleText(QString(temp), QFont("Tahoma",10));
    list2->append(label);
    label->setParentItem(item);
    label->moveBy(item->boundingRect().width()/2  - label->boundingRect().width()/2,
                  item->boundingRect().height()/2 - label->boundingRect().height()/2);

}

void Form::call_del_test()
{
    for (int i = 0 ; i < list2->size() ; i++)
        if(list2->at(i)->text() == ui->del_3->text())
        {
            scene->removeItem(list1->at(i));
            list1->removeAt(i);
            list2->removeAt(i);
            scene->update();
            view->update();
            ui->del_3->clear();
            break;
        }
}

void Form::del_all()
{
    view->close();
    delete scene, view, list1, list2;
    list2 = new QList<QGraphicsSimpleTextItem*>();
    list1 = new QList<QGraphicsItem*>();
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->resize(hooman::block*2, hooman::block);
    view->show();
    view->setRenderHint(QPainter::Antialiasing, true);
    view->setFrameStyle(QFrame::NoFrame);
    create_null();
}

void Form::call_add_func()
{
    inner->root = inner->insert(inner->root, ui->add->text().toInt());
    ui->label_3->setText("     " + ui->add->text() + "   added to AVL tree  ------->");
    ui->add->clear();
//    del_all();
//    console();
//    draw_tree();
//    printf("\n");
//    inner->preOrder(inner->root);
//    printf("\n");
}

void Form::call_del_func()
{
    inner->root = inner->deleteNode(inner->root, ui->del->text().toInt());
    ui->label_3->setText("     " + ui->del->text() + "   deleted from AVL tree  ------->");
    ui->del->clear();
//    del_all();
//    draw_tree();
//    console();
//    printf("\n");
//    inner->preOrder(inner->root);
//    printf("\n");
}

void Form::draw_tree()
{
    QQueue<Node *> q;
    Node* p = inner->root;
    p->setHeight2(0);
    p->setWidth(0);
    q.enqueue(p);
    add_node(hooman::x,hooman::y, p->getValue());
    int a, b;
//    qDebug() << "\n";
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->left != 0)
        {
            q.enqueue(p->left);
//            qDebug() << p->getValue() << "as a father of" << p->left->getValue() << "with this height" << p->getHeight2();
            p->left->setHeight2(p->getHeight2()+1);
            p->left->setWidth(p->getWidth()*2);
            a = (p->left->getWidth()+1)*hooman::block*2/(pow(2, p->left->getHeight2())+1)-hooman::block;
            b = p->left->getHeight2()*60 + hooman::y;
//            qDebug() << p->left->getValue() << p->left->getHeight2() << p->left->getWidth();
            add_node(a, b, p->left->getValue());
        }
        if (p->right != 0)
        {
            q.enqueue(p->right);
//            qDebug() << p->getValue() << "as a father of" << p->right->getValue() << "with this height" << p->getHeight2();
            p->right->setHeight2(p->getHeight2()+1);
            p->right->setWidth(p->getWidth()*2+1);
            a = (p->right->getWidth()+1)*hooman::block*2/(pow(2, p->right->getHeight2())+1)-hooman::block;
            b = p->right->getHeight2()*60 + hooman::y;
//            qDebug() << p->right->getValue() << p->right->getHeight2() << p->right->getWidth();
            add_node(a, b, p->right->getValue());
        }
    }
}
