#ifndef COLOR_H
#define COLOR_H

#include <stdexcept>

class Color {
	int r, g, b, a;

	inline void setComponent(int& component, int value);
	inline static bool checkIntegrity(int value);
public:
	inline explicit Color(int, int, int, int = 255);
	Color(const Color&) = default;
	Color(Color&&) = default;
	Color& operator=(const Color&) = default;
	Color& operator=(Color&&) = default;

	inline int getRed() const;
	inline int getGreen() const;
	inline int getBlue() const;
	inline int getAlpha() const;
	inline void setRed(int r);
	inline void setGreen(int g);
	inline void setBlue(int b);
	inline void setAlpha(int a);
	inline Color operator+(const Color& other) const;
	inline Color& operator+=(const Color& other);
};

void Color::setComponent(int& component, int value)
{
	if (!checkIntegrity(value))
		throw std::out_of_range("Invalid color component value");

	component = value;
}

bool Color::checkIntegrity(int value)
{
	return value >= 0 && value <= 255;
}

Color::Color(int r, int g, int b, int a) :
	r(r),
	g(g),
	b(b),
	a(a)
{

}

int Color::getRed() const
{
	return r;
}

int Color::getGreen() const
{
	return g;
}

int Color::getBlue() const
{
	return b;
}

int Color::getAlpha() const
{
	return a;
}

void Color::setRed(int r)
{
	setComponent(this->r, r);
}

void Color::setGreen(int g)
{
	setComponent(this->g, g);
}

void Color::setBlue(int b)
{
	setComponent(this->b, b);
}

void Color::setAlpha(int a)
{
	setComponent(this->a, a);
}

Color Color::operator+(const Color& other) const
{
	// blend factor
	double bf = other.getAlpha() / 255.0;

	return Color(static_cast<int>((1.0 - bf) * getRed() +
				      bf * other.getRed()),
		     static_cast<int>((1.0 - bf) * getGreen() +
				      bf * other.getGreen()),
		     static_cast<int>((1.0 - bf) * getBlue() +
				      bf * other.getBlue()),
		     static_cast<int>((1.0 - bf) * getAlpha() +
				      bf * other.getAlpha()));
}

Color& Color::operator+=(const Color& other)
{
	return *this = *this + other;
}

#endif // COLOR_H
