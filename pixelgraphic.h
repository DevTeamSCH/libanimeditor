#ifndef PIXELGRAPHIC_H
#define PIXELGRAPHIC_H

#include <vector>

#include "pixelmatrix.h"
#include "grapicsstate.h"
#include "timeline.hpp"

class PixelGraphic {
	Timeline<PixelMatrix> personalTimeline;
	std::vector<std::pair<std::shared_ptr<PixelGraphic>,
	Timeline<GraphicsState>>> childTimelines;
public:
	PixelGraphic();
	inline PixelMatrix& getMatrix();
	inline const PixelMatrix& getMatrix() const;
};

#endif // PIXELGRAPHIC_H
