#ifndef COLOR_H
#define COLOR_H

#include <QColor>

class Color : QColor {
public:
	inline explicit Color(int, int, int, int = 255);
	inline Color(const QColor&);
	inline Color(QColor&&);
	inline int red() const;
	inline int green() const;
	inline int blue() const;
	inline void setRed(int r);
	inline void setGreen(int g);
	inline void setBlue(int b);
	inline Color operator+(const Color& other) const;
	inline Color& operator+=(const Color& other);
};

Color::Color(int r, int g, int b, int a) :
	QColor(r, g, b, a)
{

}

Color::Color(const QColor& qcolor) :
	QColor(qcolor)
{

}

Color::Color(QColor&& qcolor) :
	QColor(std::move(qcolor))
{

}

int Color::red() const
{
	return QColor::red();
}

int Color::green() const
{
	return QColor::green();
}

int Color::blue() const
{
	return QColor::blue();
}

void Color::setRed(int r)
{
	QColor::setRed(r);
}

void Color::setGreen(int g)
{
	QColor::setGreen(g);
}

void Color::setBlue(int b)
{
	QColor::setBlue(b);
}

Color Color::operator+(const Color& other) const
{
	// blend factor
	double bf = other.alphaF();

	return Color(static_cast<int>((1.0 - bf) * red() + bf * other.red()),
		     static_cast<int>((1.0 - bf) * green() +
				      bf * other.green()),
		     static_cast<int>((1.0 - bf) * blue() + bf * other.blue()),
		     static_cast<int>((1.0 - bf) * alpha() +
				      bf * other.alpha()));
}

Color& Color::operator+=(const Color& other)
{
	return *this = *this + other;
}

#endif // COLOR_H
