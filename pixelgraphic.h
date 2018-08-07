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
	inline PixelMatrix getMatrix(const TimePoint& time) const;
};

PixelGraphic::PixelGraphic(const PixelGraphic& other) :
	personalTimeline(other.personalTimeline),
	childTimelines(other.childTimelines.size())
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

PixelMatrix PixelGraphic::getMatrix(const TimePoint& time) const
{
	PixelMatrix pm(personalTimeline.getObject(time));
	for (const auto& p : childTimelines) {
		GraphicsState state = p.second.getObject(time);

		if (!state.visible)
			continue;

		pm.addLayer(p.first->getMatrix(time), state.pos);
	}

	return pm;
}

#endif // PIXELGRAPHIC_H
