#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <memory>
#include <chrono>

using Duration = std::chrono::duration<int, std::milli>;
using TimePoint = std::chrono::duration<int, std::milli>;

template<typename T>
class KeyFrame {
	T t;
public:
	explicit KeyFrame(const T& t);
	KeyFrame(const KeyFrame<T>&) = default;
	KeyFrame(KeyFrame<T>&&) = default;
	KeyFrame<T>& operator=(const KeyFrame&) = default;
	KeyFrame<T>& operator=(KeyFrame&&) = default;

	inline T& getObject();
	inline const T& getObject() const;
};

template<typename T>
KeyFrame<T>::KeyFrame(const T& t) :
	t(t)
{

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
