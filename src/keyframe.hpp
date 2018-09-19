#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <memory>
#include <chrono>

using Duration = std::chrono::duration<int, std::milli>;
using TimePoint = std::chrono::duration<int, std::milli>;

template<typename T>
class KeyFrame {
	T t;
	Duration duration; // the duration of the keyframe
public:
	explicit KeyFrame(const T& t, const Duration& duration);
	KeyFrame(KeyFrame<T>&&) = delete;
	void setDuration(const Duration&);
	Duration getDuration() const;
	T& getObject();
	const T& getObject() const;
};

template<typename T>
KeyFrame<T>::KeyFrame(const T& t, const Duration& duration) :
	t(t),
	duration(duration)
{

}

template<typename T>
void KeyFrame<T>::setDuration(const Duration& duration)
{
	this->duration = duration;
}

template<typename T>
Duration KeyFrame<T>::getDuration() const
{
	return duration;
}

template<typename T>
T& KeyFrame<T>::getObject()
{
	return *t;
}

template<typename T>
const T& KeyFrame<T>::getObject() const
{
	return *t;
}

#endif // KEYFRAME_H
