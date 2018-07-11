#ifndef PIXELMATRIX_H
#define PIXELMATRIX_H

#include <vector>

#include "pixel.h"

class PixelMatrix
{
	std::vector<std::vector<Pixel>> matrix;

	inline bool checkBounds(unsigned int n, unsigned int m) const;
public:
	const unsigned int n, m;

	explicit PixelMatrix(unsigned int, unsigned int);
	inline Pixel& getPixel(unsigned int, unsigned int);
	inline const Pixel& getPixel(unsigned int, unsigned int) const;
};

bool PixelMatrix::checkBounds(unsigned int n, unsigned int m) const
{
	return n < this->n && m < this->m;
}

Pixel& PixelMatrix::getPixel(unsigned int n, unsigned int m)
{
	return const_cast<Pixel&>(const_cast<const PixelMatrix *>(this)->
				  getPixel(n, m));
}

const Pixel& PixelMatrix::getPixel(unsigned int n, unsigned int m) const
{
	if (!checkBounds(n, m))
		throw std::out_of_range("Out of range error");

	return matrix[n][m];
}
#endif // PIXELMATRIX_H
