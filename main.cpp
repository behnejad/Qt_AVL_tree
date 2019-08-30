#include "widget.h"
#include <QApplication>
#include "node.h"
#include <qDebug>
#include "global.h"
#include "struct.h"
#include "copy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Struct1 s;

    struct node *root = NULL;

//    Form w(s);
//    w.show();
//    root = s.insert(root, 3);
//    root = s.insert(root, 3);
//    root = s.insert(root, 4);
//    root = s.insert(root, 4);
//    root = s.deleteNode(root, 3);

//    s->root = s->insert(s->root, 11);
//    s->root = s->insert(s->root, -1);
//    s->root = s->insert(s->root, 1);
//    s->root = s->insert(s->root, 2);
//    w.draw_tree();
    return a.exec();
}
