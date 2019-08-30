#ifndef NODE_H
#define NODE_H

class Node
{
private:
   int data;
   int height;
   int height2;
   int width = 0;

public:
    Node():data(0){left = 0; right = 0;}
    Node(int in) : data(in) {left = 0; right = 0;}
    Node* left;
    Node* right;
    int getValue() const
    {return data;}
    void setValue(int in)
    {data = in;}
    int getHeight() const
    {return height;}
    int getHeight2() const
    {return height2;}
    int getWidth() const
    {return width;}
    void setWidth(int in)
    {width = in;}
    void setHeight(int in)
    {height = in;}
    void setHeight2(int in)
    {height2 = in;}
    ~Node();
};

#endif // NODE_H
