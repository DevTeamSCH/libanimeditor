#include "pixelquartet.h"

PixelQuartet PixelQuartet::operator+(const PixelQuartet& other) const
{
	PixelQuartet tmp(*this);
	for (unsigned int i = 0; i < 2; ++i) {
		for (unsigned int j = 0; j < 2; ++j) {
			tmp.pixels[i][j] += other.pixels[i][j];
		}
	}

	return tmp;
}
