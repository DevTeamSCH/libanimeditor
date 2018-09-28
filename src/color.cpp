#include "color.h"

Color::Color(int r, int g, int b, int a)
{
	setComponent(this->r, r);
	setComponent(this->g, g);
	setComponent(this->b, b);
	setComponent(this->a, a);
}

Color Color::operator+(const Color& other) const
{
	double a1 = this->getAlpha() / 255.0;
	double a2 = other.getAlpha() / 255.0;

	int newRed = blendColorComponents(this->r, other.r, a1, a2);
	int newGreen = blendColorComponents(this->g, other.g, a1, a2);
	int newBlue = blendColorComponents(this->b, other.b, a1, a2);
	int newAlpha = static_cast<int>(lround(255 * (a2 + a1 * (1 - a2))));

	return Color(newRed, newGreen, newBlue, newAlpha);
}

bool Color::operator==(const Color& rhs) const
{
	return r == rhs.r &&
	       g == rhs.g &&
	       b == rhs.b &&
	       a == rhs.a;
}
