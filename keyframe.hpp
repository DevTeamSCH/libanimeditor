#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <memory>

template<typename T>
class KeyFrame {
	std::shared_ptr<T> t;
	double duration; // the duration of the keyframe
public:
	explicit KeyFrame(const std::shared_ptr<T>&, double);
	void setDuration(double);
	double getDuration() const;
	T& getObject();
	const T& getObject() const;
};

template<typename T>
KeyFrame<T>::KeyFrame(const std::shared_ptr<T>& t, double duration) :
	t(t),
	duration(duration)
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
