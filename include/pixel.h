#ifndef PIXEL_H
#define PIXEL_H

#include "color.h"

class Pixel {
	Color color;
public:
	inline explicit Pixel(const Color& = Color(0, 0, 0));
	Pixel(const Pixel&) = default;
	Pixel(Pixel&&) = default;
	Pixel& operator=(const Pixel&) = default;
	Pixel& operator=(Pixel&&) = default;

	inline void setColor(const Color&);
	inline const Color& getColor() const;
	inline Pixel operator+(const Pixel&) const;
	inline Pixel& operator+=(const Pixel&);
	inline bool operator==(const Pixel& rhs) const;
	inline bool operator!=(const Pixel& rhs) const;
};

Pixel::Pixel(const Color& color) :
	color(color)
{

}

void Pixel::setColor(const Color& color)
{
	this->color = color;
}

const Color& Pixel::getColor() const
{
	return color;
}

Pixel Pixel::operator+(const Pixel& other) const
{
	return Pixel(this->color + other.color);
}

Pixel& Pixel::operator+=(const Pixel& other)
{
	return *this = *this + other;
}

bool Pixel::operator==(const Pixel& rhs) const
{
	return color == rhs.color;
}

bool Pixel::operator!=(const Pixel& rhs) const
{
	return !(rhs == *this);
}

#endif // PIXEL_H
