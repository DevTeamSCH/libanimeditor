#include "pixelmatrix.h"

void PixelMatrix::addLayer(const PixelMatrix& pm, const vec2& v)
{
	auto offset = roundvec2(v);
	int rowOffset = offset.first;
	int columnOffset = offset.second;
	int n_ = static_cast<int>(pm.n);
	int m_ = static_cast<int>(pm.m);

	int rowLowerBound = std::max(-rowOffset, 0);
	int rowUpperBound = std::min(static_cast<int>(n) - rowOffset, n_);

	int columnLowerBound = std::max(-columnOffset, 0);
	int columnUpperBound = std::min(static_cast<int>(m) - columnOffset, m_);

	for (int i = rowLowerBound; i < rowUpperBound; ++i) {
		auto row = static_cast<unsigned int>(rowOffset + i);

		for (int j = columnLowerBound; j < columnUpperBound; ++j) {
			auto column = static_cast<unsigned int>(columnOffset +
								j);

			getPixelQuartet(row, column) += pm.getPixelQuartet(
				static_cast<unsigned int>(i),
				static_cast<unsigned int>(j));
		}
	}
}
