#ifndef VEC2_H
#define VEC2_H

struct vec2 {
	double x, y;

	explicit vec2(double, double);
	inline vec2 operator+(const vec2&) const;
	inline vec2 operator*(double) const;
};

inline vec2 operator*(double d, const vec2& v)
{
	return v * d;
}

vec2 vec2::operator+(const vec2& v) const
{
	return vec2(x + v.x, y + v.y);
}

vec2 vec2::operator*(double d) const
{
	return vec2(d * x, d * y);
}

#endif // VEC2_H
