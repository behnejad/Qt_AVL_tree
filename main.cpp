#include "widget.h"
#include <QApplication>
#include "node.h"
#include <qDebug>
#include "global.h"
#include "struct.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Struct *s;
    s = new Struct();
    Form w(s);
    w.show();
//    s->root = s->insert(s->root, 9);
//    s->root = s->insert(s->root, 3);
//    s->root = s->insert(s->root, 10);
//    s->root = s->insert(s->root, 6);
//    s->root = s->insert(s->root, 11);
//    s->root = s->insert(s->root, -1);
//    s->root = s->insert(s->root, 1);
//    s->root = s->insert(s->root, 2);
    w.draw_tree();
    return a.exec();
}
