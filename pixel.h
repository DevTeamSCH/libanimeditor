#ifndef PIXEL_H
#define PIXEL_H

#include "color.h"

class Pixel
{
	Color color;
public:
	inline explicit Pixel(const Color& = Color(0, 0, 0));
	inline void setColor(const Color&);
	inline const Color& getColor() const;
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

#endif // PIXEL_H
