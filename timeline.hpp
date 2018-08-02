#ifndef TIMELINE_H
#define TIMELINE_H

#include <map>

#include "keyframe.hpp"
#include "grapicsstate.h"

/*
 * Returning a GraphicsState is different than returning a PixelMatrix, as we
 * interpolate between two states creating a temporary object, and we can't
 * return it by reference. This way we can specialize the return type.
 */
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

/*
 * Stores KeyFrames based on their starting time. Can return the relevant object
 * stored by the KeyFrame for the given time point.
 */
template<typename T>
class Timeline {
	/*
	 * Initially KeyFrames only store the duration, but when searching for
	 * a KeyFrame in the Timeline it's useful to store when that KeyFrame
	 * starts
	 */
	std::map<TimePoint, KeyFrame<T>> timeKeyFrameMap;

	typename std::map<TimePoint, KeyFrame<T>>::const_iterator
	getIteratorForKeyFrame(const TimePoint& time) const;
public:
	void addKeyFrame(const KeyFrame<T>&);
	typename return_type<T>::type getObject(const TimePoint& time);
	typename return_type<T>::const_type
	getObject(const TimePoint& time) const;
};

template<typename T>
typename std::map<TimePoint, KeyFrame<T>>::const_iterator
Timeline<T>::getIteratorForKeyFrame(const TimePoint& time) const
{
	auto it = timeKeyFrameMap.lower_bound(time);

	// If timeKeyFrameMap is empty, or time is pointing out of the Timeline
	if (it == timeKeyFrameMap.end() ||
			it->first + it->second.getDuration() < time)
		throw std::out_of_range("Invalid time");

	return it;
}

template<typename T>
void Timeline<T>::addKeyFrame(const KeyFrame<T>& keyFrame)
{
	TimePoint prevTime(0);
	Duration prevDuration(0);

	if (!timeKeyFrameMap.empty()) {
		auto it = timeKeyFrameMap.rbegin();
		prevTime = it->first;
		prevDuration = it->second.getDuration();
	}

	/*
	 * The new KeyFrame's start time is the previous KeyFrame's start time
	 * plus its duration.
	 */
	timeKeyFrameMap[prevTime + prevDuration] = keyFrame;
}

template<typename T>
typename return_type<T>::type Timeline<T>::getObject(const TimePoint& time)
{
	// getIteratorForKeyFrame can only be called on a const object
	return const_cast<typename return_type<T>::type>
			(const_cast<const Timeline<T> *>
			 (getIteratorForKeyFrame(time))->second.getObject());
}

template<typename T>
typename return_type<T>::const_type
Timeline<T>::getObject(const TimePoint& time) const
{
	return getIteratorForKeyFrame(time)->second.getObject();
}

// specialization, T = GraphicsState
template<>
return_type<GraphicsState>::const_type
Timeline<GraphicsState>::getObject(const TimePoint& time) const
{
	auto it = getIteratorForKeyFrame(time);
	auto next = it;
	++next;

	// if it is an iterator to the last element we can't interpolate
	if (next == timeKeyFrameMap.end())
		return it->second.getObject();

	double ratio = static_cast<double>((time - it->first).count()) /
			it->second.getDuration().count();
	const GraphicsState& currentObject = it->second.getObject();
	const GraphicsState& nextObject = next->second.getObject();

	return GraphicsState{(1.0 - ratio) * currentObject.pos +
				ratio * nextObject.pos, currentObject.visible};
}

#endif // TIMELINE_H
