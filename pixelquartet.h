#ifndef PIXELQUARTET_H
#define PIXELQUARTET_H

#include <array>

#include "pixel.h"

class PixelQuartet {
	std::array<std::array<Pixel, 2>, 2> pixels;
public:
	inline PixelQuartet();
	inline Pixel& getPixel(unsigned int, unsigned int);
	inline const Pixel& getPixel(unsigned int, unsigned int) const;
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

#endif // PIXELQUARTET_H
