#ifndef PIXELQUARTET_H
#define PIXELQUARTET_H

#include <array>

#include "pixel.h"

class PixelQuartet {
	std::array<std::array<Pixel, 2>, 2> pixels;
public:
	inline PixelQuartet();
	PixelQuartet(const PixelQuartet&) = default;
	PixelQuartet(PixelQuartet&&) = default;
	PixelQuartet& operator=(const PixelQuartet&) = default;
	PixelQuartet& operator=(PixelQuartet&&) = default;

	inline Pixel& getPixel(unsigned int, unsigned int);
	inline const Pixel& getPixel(unsigned int, unsigned int) const;
	PixelQuartet operator+(const PixelQuartet&) const;
	inline PixelQuartet& operator+=(const PixelQuartet&);
	inline bool operator==(const PixelQuartet& rhs) const;
	inline bool operator!=(const PixelQuartet& rhs) const;
};

PixelQuartet::PixelQuartet()
{
	pixels.fill({Pixel(), Pixel()});
}

Pixel& PixelQuartet::getPixel(unsigned int n, unsigned int m)
{
	return const_cast<Pixel&>(const_cast<const PixelQuartet *>(this)
				  ->getPixel(n, m));
}

const Pixel& PixelQuartet::getPixel(unsigned int n, unsigned int m) const
{
	if (n >= 2 || m >= 2)
		throw std::out_of_range("Out of range error");

	return pixels[n][m];
}

PixelQuartet& PixelQuartet::operator+=(const PixelQuartet& other)
{
	return *this = *this + other;
}

bool PixelQuartet::operator==(const PixelQuartet& rhs) const
{
	return pixels == rhs.pixels;
}

bool PixelQuartet::operator!=(const PixelQuartet& rhs) const
{
	return !(rhs == *this);
}

#endif // PIXELQUARTET_H
