#include "pixelmatrix.h"

PixelMatrix::PixelMatrix(unsigned int n, unsigned int m) :
	matrix(n, std::vector<Pixel>(m)),
	n(n),
	m(m)
{

}
