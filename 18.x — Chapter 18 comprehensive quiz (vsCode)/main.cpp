#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm> // for std::max_element

class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() = default;

};

class Point
{
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    Point() = default;

    Point(int x, int y, int z)
        : m_x{ x }, m_y{ z }, m_z{ z }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point)
    {
        out << "Point( " << point.m_x << ", " << point.m_y << ", " << point.m_z << " )";
        return out;
    }

};


class Triangle: public Shape
{
private:
    Point m_x;
    Point m_y;
    Point m_z;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        :  m_x{ p1 }, m_y{ p2 }, m_z{ p3 }
    {   
    }

    std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle(" << m_x << ", " << m_y << ", " << m_z << ')'; 
    }

};

class Circle: public Shape
{
protected:
    int m_radius{};
    Point m_x;

public:
    Circle(const Point& p1, int radius)
        :  m_x{ p1 }, m_radius{ radius }
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
       return out << "Circle(" << m_x << ",m_radius " << m_radius << ')'; 
    }

    int getRadius() const { return m_radius; }
};

Shape& getLargestRadius(std::vector<Shape*> shape)
{
    int* i{ std::max_element(std::begin(shape), std::end(shape)) };

    return i;
    //std::cout << *std::max_element(std::begin(shape), std::end(shape));
    
}

int main()
{
    Circle c{ Point{ 1, 2, 3 }, 7 };
    std::cout << c << '\n';

    Triangle t{ Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9} };
    std::cout << t << '\n';
    
    std::vector<Shape*> v
    {
        new Circle{Point{1, 2, 3}, 7},
        new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Circle{Point{4, 5, 6}, 3}
    };

    // print each shape in vector v on its own line here
    for(const auto* element : v)
    {
        std::cout << *element << '\n';
    }
    std::cout << std::endl;

    std::cout << "The largest radius is: " << getLargestRadius(v);

    for(const auto* element : v)
    {
        delete element;
    }
    v.clear();

    return 0;
}