#ifndef PIXELGRAPHIC_H
#define PIXELGRAPHIC_H

#include <vector>
#include <memory>

#include "pixelmatrix.h"
#include "grapicsstate.h"
#include "timeline.hpp"

class PixelGraphic {
	Timeline<PixelMatrix> personalTimeline;
	std::vector<std::pair<std::unique_ptr<PixelGraphic>,
	Timeline<GraphicsState>>> childTimelines;
public:
	PixelGraphic();
	inline PixelGraphic(const PixelGraphic&);
	inline PixelMatrix& getMatrix();
	inline const PixelMatrix& getMatrix() const;
};

PixelGraphic::PixelGraphic(const PixelGraphic& other) :
	personalTimeline(other.personalTimeline)
{
	for (const auto& it : other.childTimelines) {
		childTimelines.push_back(
					std::pair<std::unique_ptr<PixelGraphic>,
					Timeline<GraphicsState>>(
						std::make_unique<PixelGraphic>(
							*it.first),
						it.second));
	}
}

#endif // PIXELGRAPHIC_H
