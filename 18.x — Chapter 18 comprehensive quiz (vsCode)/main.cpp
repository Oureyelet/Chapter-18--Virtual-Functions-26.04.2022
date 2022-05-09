#include <iostream>
#include <string>
#include <string_view>
#include <array>

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

class Triangle: public Shape
{
protected:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    Triangle(int x, int y, int z)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }


};

class Circle: public Shape, public Triangle
{
protected:
    int m_center_Point{};
    int m_radius{};

public:
    Circle(int x, int y, int z, int center_Point)
        : Triangle{ x, y, z }, m_center_Point{ center_Point }
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << 
    }
};

int main()
{
    
    


    return 0;
}