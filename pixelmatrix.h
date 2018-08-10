#ifndef PIXELMATRIX_H
#define PIXELMATRIX_H

#include <vector>
#include <cmath>

#include "pixelquartet.h"
#include "grapicsstate.h"

class PixelMatrix {
	std::vector<PixelQuartet> matrix;

	inline bool checkBounds(unsigned int n, unsigned int m) const;
public:
	const unsigned int n, m;

	explicit PixelMatrix(unsigned int, unsigned int);
	inline PixelQuartet& getPixelQuartet(unsigned int, unsigned int);
	inline const PixelQuartet&
	getPixelQuartet(unsigned int, unsigned int) const;
	inline PixelQuartet& getPixelQuartet(const vec2&);
	inline const PixelQuartet& getPixelQuartet(const vec2&) const;
	inline void addLayer(const PixelMatrix&, const vec2&);

	static std::pair<int, int> roundvec2(const vec2&);
};

bool PixelMatrix::checkBounds(unsigned int n, unsigned int m) const
{
	return n < this->n && m < this->m;
}

PixelQuartet& PixelMatrix::getPixelQuartet(unsigned int n, unsigned int m)
{
	return const_cast<PixelQuartet&>(const_cast<const PixelMatrix *>(this)->
				  getPixelQuartet(n, m));
}

const PixelQuartet&
PixelMatrix::getPixelQuartet(unsigned int n, unsigned int m) const
{
	if (!checkBounds(n, m))
		throw std::out_of_range("Out of range error");

	return matrix[n * this->n + m];
}

PixelQuartet& PixelMatrix::getPixelQuartet(const vec2& v)
{
	return const_cast<PixelQuartet&>(const_cast<const PixelMatrix *>(this)->
				  getPixelQuartet(v));
}

const PixelQuartet& PixelMatrix::getPixelQuartet(const vec2& v) const
{
	auto p = roundvec2(v);

	return getPixelQuartet(static_cast<unsigned int>(p.first),
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

			auto& pixelQuartet =
					getPixelQuartet(
						static_cast<unsigned int>(row),
						static_cast<unsigned int>(
							column));

			pixelQuartet += pm.getPixelQuartet(i, j);

		}
	}
}

std::pair<int, int> PixelMatrix::roundvec2(const vec2& v)
{
	return std::pair<int, int>(std::lround(v.y), std::lround(v.x));
}
#endif // PIXELMATRIX_H
