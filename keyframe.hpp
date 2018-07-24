#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <memory>

template<typename T>
class KeyFrame {
	std::unique_ptr<T> t;
	double duration; // the duration of the keyframe
public:
	explicit KeyFrame(const std::unique_ptr<T>&, double);
	KeyFrame(const KeyFrame<T>&);
	KeyFrame(KeyFrame<T>&&) = delete;
	void setDuration(double);
	double getDuration() const;
	T& getObject();
	const T& getObject() const;
};

template<typename T>
KeyFrame<T>::KeyFrame(const std::unique_ptr<T>& t, double duration) :
	t(t),
	duration(duration)
{

}

template<typename T>
KeyFrame<T>::KeyFrame(const KeyFrame<T>& other) :
	t(std::make_unique(*other.t)),
	duration(other.duration)
{

}

template<typename T>
void KeyFrame<T>::setDuration(double duration)
{
	this->duration = duration;
}

template<typename T>
double KeyFrame<T>::getDuration() const
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
