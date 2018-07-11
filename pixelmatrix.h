#ifndef PIXELMATRIX_H
#define PIXELMATRIX_H

#include <vector>

#include "pixel.h"

class PixelMatrix
{
	std::vector<std::vector<Pixel>> matrix;
public:
	const unsigned int n, m;

	explicit PixelMatrix(unsigned int, unsigned int);
	inline const std::vector<Pixel>& operator[](int) const;
};

const std::vector<Pixel>& PixelMatrix::operator[](int i) const
{
	return matrix[i];
}

#endif // PIXELMATRIX_H
