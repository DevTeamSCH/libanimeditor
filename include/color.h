#ifndef COLOR_H
#define COLOR_H

#include <stdexcept>
#include <cmath>

class Color {
	int r, g, b, a;

	inline void setComponent(int& component, int value);
	inline static bool checkIntegrity(int value);
	inline static int
	blendColorComponents(int a, int b, double alphaA, double alphaB);
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

int Color::blendColorComponents(int a, int b, double alphaA, double alphaB)
{
	return static_cast<int>((b * alphaB + a * alphaA * (1 - alphaB)) /
				(alphaB + alphaA * (1 - alphaB)));
}

Color::Color(int r, int g, int b, int a)
{
	setComponent(this->r, r);
	setComponent(this->g, g);
	setComponent(this->b, b);
	setComponent(this->a, a);
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
	double a1 = this->getAlpha() / 255.0;
	double a2 = other.getAlpha() / 255.0;

	int newRed = blendColorComponents(this->r, other.r, a1, a2);
	int newGreen = blendColorComponents(this->g, other.g, a1, a2);
	int newBlue = blendColorComponents(this->b, other.b, a1, a2);
	int newAlpha = static_cast<int>(std::lround(
		255 * (a2 + a1 * (1 - a2))));

	return Color(newRed, newGreen, newBlue, newAlpha);
}

Color& Color::operator+=(const Color& other)
{
	return *this = *this + other;
}

#endif // COLOR_H
