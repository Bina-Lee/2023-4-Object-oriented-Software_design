#if 01
#include<iostream>

#define PI 3.14159f

class Shape{
    public:
    virtual double calculateArea()=0;
    virtual double calculatePerimeter()=0;
};

class Circle{
    double r;
    public:
    Circle(double _r){
        r=_r;
    }
    double calculateArea(){
        return r*r*PI;
    }
    double calculatePerimeter(){
        return 2*r*PI;
    }
};
class Rectangle{
    double length;
    double width;
    public:
    Rectangle(double _length, double _width){
        length=_length;
        width=_width;
    }
    double calculateArea(){
        return length*width;
    }
    double calculatePerimeter(){
        return 2*(length+width);
    }
};
class Triangle{
    double a;
    double b;
    double c;
    double s;
    bool ab;    //삼각형 구성이 가능한지 확인하는 bool
    public:
    Triangle(double _a, double _b, double _c){
        a=_a;
        b=_b;
        c=_c;
        s=(a+b+c)/2;
        ab=true;    //기본적으로는 true임
        if(a+b<c)ab=false;
        if(b+c<a)ab=false;
        if(c+a<b)ab=false;  //세 경우를 확인하고 해당되는 경우 false로 지정
    }
    double calculateArea(){
        if(ab)return sqrt(s*(s-a)*(s-b)*(s-c)); //ab를 확인 한 후에 return
        return -1;
    }
    double calculatePerimeter(){
        if(ab)return s*2;   //ab를 확인 한 후에 return
        return -1;
    }
};

int main() {

    Circle circle(7.0);
    Rectangle rectangle(4.2, 8.0);
    Triangle triangle(4.0, 4.0, 3.2);
    Triangle t2(10.0, 100.0, 20.0);

    std::cout << "Circle: " << std::endl;
    std::cout << "Area: " << circle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;

    std::cout << "\nRectangle: " << std::endl;
    std::cout << "Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;

    std::cout << "\nTriangle: " << std::endl;
    std::cout << "Area: " << triangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;

    std::cout << "Area: " << t2.calculateArea() << std::endl;
    std::cout << "Perimeter: " << t2.calculatePerimeter() << std::endl;

    return 0;
}
#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

