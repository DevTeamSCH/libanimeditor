#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <memory>
#include <chrono>

using Duration = std::chrono::duration<int, std::milli>;
using TimePoint = std::chrono::duration<int, std::milli>;

template<typename T>
class KeyFrame {
	std::unique_ptr<T> t;
	Duration duration; // the duration of the keyframe
public:
	explicit KeyFrame(std::unique_ptr<T>&&, const Duration&);
	KeyFrame(const KeyFrame<T>&);
	KeyFrame(KeyFrame<T>&&) = delete;
	void setDuration(Duration);
	Duration getDuration() const;
	T& getObject();
	const T& getObject() const;
};

template<typename T>
KeyFrame<T>::KeyFrame(std::unique_ptr<T>&& t, const Duration& duration) :
	t(std::move(t)),
	duration(duration)
{

}

template<typename T>
KeyFrame<T>::KeyFrame(const KeyFrame<T>& other) :
	t(std::make_unique<T>(*other.t)),
	duration(other.duration)
{

}

template<typename T>
void KeyFrame<T>::setDuration(Duration duration)
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
