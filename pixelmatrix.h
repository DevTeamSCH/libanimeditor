#ifndef PIXELMATRIX_H
#define PIXELMATRIX_H

#include <vector>
#include <cmath>

#include "pixel.h"
#include "grapicsstate.h"

class PixelMatrix {
	std::vector<std::vector<Pixel>> matrix;

	inline bool checkBounds(unsigned int n, unsigned int m) const;
public:
	const unsigned int n, m;

	explicit PixelMatrix(unsigned int, unsigned int);
	inline Pixel& getPixel(unsigned int, unsigned int);
	inline const Pixel& getPixel(unsigned int, unsigned int) const;
	inline Pixel& getPixel(const vec2&);
	inline const Pixel& getPixel(const vec2&) const;
	inline void addLayer(const PixelMatrix&, const vec2&);

	static std::pair<int, int> roundvec2(const vec2&);
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

Pixel& PixelMatrix::getPixel(const vec2& v)
{
	return const_cast<Pixel&>(const_cast<const PixelMatrix *>(this)->
				  getPixel(v));
}

const Pixel& PixelMatrix::getPixel(const vec2& v) const
{
	auto p = roundvec2(v);

	return getPixel(static_cast<unsigned int>(p.first),
			static_cast<unsigned int>(p.second));
}

void PixelMatrix::addLayer(const PixelMatrix& pm, const vec2& v)
{
	auto p = roundvec2(v);

	for (unsigned int i = 0; i < pm.n; ++i) {
		int row = static_cast<int>(i) + p.first;

		if (row < 0)
			continue;

		if (row >= static_cast<int>(n))
			break;

		for (unsigned int j = 0; j < pm.m; ++j) {
			int column = static_cast<int>(j) + p.second;

			if (column < 0)
				continue;

			if (column >= static_cast<int>(m))
				break;

			auto& pixel = matrix[static_cast<unsigned int>(row)]
					[static_cast<unsigned int>(column)];

			pixel.setColor(pixel.getColor() +
				       pm.matrix[i][j].getColor());

		}
	}
}

std::pair<int, int> PixelMatrix::roundvec2(const vec2& v)
{
	return std::pair<int, int>(std::lround(v.y), std::lround(v.x));
}
#endif // PIXELMATRIX_H
