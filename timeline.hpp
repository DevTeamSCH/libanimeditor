#ifndef TIMELINE_H
#define TIMELINE_H

#include <vector>

#include "keyframe.hpp"
#include "grapicsstate.h"

template<typename T>
struct return_type {
	using type = T&;
	using const_type = const T&;
};

template<>
struct return_type<GraphicsState> {
	using type = GraphicsState;
	using const_type = GraphicsState;
};

template<typename T>
class Timeline {
	std::vector<KeyFrame<T>> keyFrames;

	typename std::vector<KeyFrame<T>>::iterator
	getIteratorForKeyFrame(double time) const;
public:
	void addKeyFrame(const KeyFrame<T>&);
	typename return_type<T>::type getObject(double time);
	typename return_type<T>::const_type getObject(double time) const;
};

template<typename T>
typename std::vector<KeyFrame<T>>::iterator
Timeline<T>::getIteratorForKeyFrame(double time) const
{
	double playTime = 0.0;

	for (auto it = keyFrames.begin(); it != keyFrames.end(); ++it) {
		playTime += it->getDuration();

		if (playTime > time)
			return it;
	}

	throw std::out_of_range("Time points out of the timeline");
}

template<typename T>
void Timeline<T>::addKeyFrame(const KeyFrame<T>& keyFrame)
{
	keyFrames.push_back(keyFrame);
}

template<typename T>
typename return_type<T>::type Timeline<T>::getObject(double time)
{
	return *getIteratorForKeyFrame(time);
}

template<typename T>
typename return_type<T>::const_type Timeline<T>::getObject(double time) const
{
	return *getIteratorForKeyFrame(time);
}

/* This is not yet implemented. For GraphicsState objects we interpolate
 * between keyframes.
template<>
return_type<GraphicsState>::const_type
Timeline<GraphicsState>::getObject(double time) const
{

}
*/
#endif // TIMELINE_H
