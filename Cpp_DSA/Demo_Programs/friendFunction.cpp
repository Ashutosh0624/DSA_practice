#include<iostream>
#include<string>
using namespace std;
class Box{
    private:
        double width;
    public:
        Box(double width)
        :  width{width} {}
        void getBoxDimension() const;
        friend void printWidth(Box box);   
};
void Box::getBoxDimension() const{
    cout<<"Width :"<<width<<endl;
}

void printWidth(Box box){
    cout<<"Width of the box is :"<<box.width<<endl;
}
// Friend function : a friend function is a function that is not a member function of the class but has access to the 
// class private's data
/* 
   Friend class :
   A friend class is a class that is given access to thte private and protected members of another class.
   This is useful when two or more classes need to work together, closely

*/
class Rectangle{
    private:
        int length, breadth;
    public:
        Rectangle(int length, int breadth)
            : length{length}, breadth{breadth}{}
        void getRectangleDimensions() const;
        friend class Square;
};

void Rectangle::getRectangleDimensions() const{
    cout<<"Length : "<<length<<" Breadth : "<<breadth<<endl;
}

class Square{
    public:
        int getArea(Rectangle& rec) const;

};
int Square::getArea(Rectangle& rec) const{
    return rec.length * rec.length;
}
int main()
{
    Box r1{16};
    printWidth(r1);
    //cout<<widthDimension<<endl;
    Rectangle r4{10, 20};
    Square s1; 
    cout<<"Area of the sqaure :"<<s1.getArea(r4)<<endl;
    return 0;
}