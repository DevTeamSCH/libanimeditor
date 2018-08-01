#ifndef TIMELINE_H
#define TIMELINE_H

#include <map>

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
	/*
	 * Initially KeyFrames only store the duration, but when searching for
	 * a KeyFrame in the Timeline it's useful to store when that KeyFrame
	 * starts
	 */
	std::map<double, KeyFrame<T>> timeKeyFrameMap;

	typename std::map<double, KeyFrame<T>>::const_iterator
	getIteratorForKeyFrame(double time) const;
public:
	void addKeyFrame(const KeyFrame<T>&);
	typename return_type<T>::type getObject(double time);
	typename return_type<T>::const_type getObject(double time) const;
};

template<typename T>
typename std::map<double, KeyFrame<T>>::const_iterator
Timeline<T>::getIteratorForKeyFrame(double time) const
{
	auto it = timeKeyFrameMap.lower_bound(time);
	if (it == timeKeyFrameMap.end() ||
			it->first + it->second.getDuration() < time)
		throw std::out_of_range("Invalid time");

	return it;
}

template<typename T>
void Timeline<T>::addKeyFrame(const KeyFrame<T>& keyFrame)
{
	double prevTime = 0.0;
	double prevDuration = 0.0;

	auto it = timeKeyFrameMap.rbegin();
	if (it != timeKeyFrameMap.rend()) {
		prevTime = it->first;
		prevDuration = it->second.getDuration();
	}

	timeKeyFrameMap[prevTime + prevDuration] = keyFrame;
}

template<typename T>
typename return_type<T>::type Timeline<T>::getObject(double time)
{
	return getIteratorForKeyFrame(time)->second.getObject();
}

template<typename T>
typename return_type<T>::const_type Timeline<T>::getObject(double time) const
{
	return getIteratorForKeyFrame(time)->second.getObject();
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
