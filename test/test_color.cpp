#include "catch.hpp"

#include "color.h"

TEST_CASE("Color: check constructor", "[color]")
{
	Color c1(1, 2, 3, 4);

	REQUIRE(c1.getRed() == 1);
	REQUIRE(c1.getGreen() == 2);
	REQUIRE(c1.getBlue() == 3);
	REQUIRE(c1.getAlpha() == 4);

	REQUIRE(Color(1, 1, 1).getAlpha() == 255);

	REQUIRE_THROWS(Color(-1, 0, 0, 0));
	REQUIRE_THROWS(Color(256, 0, 0, 0));
}

TEST_CASE("Color: check setters", "[color]")
{
	const int normalValue = 1;
	const int highValue = 256;
	const int lowValue = -1;

	Color c(normalValue, normalValue, normalValue, normalValue);

	const std::array<std::pair<std::function<void(Color&, int)>,
		std::function<int(const Color&)>>, 4> setterGetterPairs =
		{
			std::make_pair(&Color::setRed, &Color::getRed),
			std::make_pair(&Color::setGreen, &Color::getGreen),
			std::make_pair(&Color::setBlue, &Color::getBlue),
			std::make_pair(&Color::setAlpha, &Color::getAlpha)
		};

	for (auto sgPair : setterGetterPairs) {
		REQUIRE(sgPair.second(c) == normalValue);

		REQUIRE_THROWS(sgPair.first(c, highValue));
		REQUIRE_THROWS(sgPair.first(c, lowValue));
	}
}

TEST_CASE("Color: check getters", "[color]")
{
	const int redValue = 1;
	const int greenValue = 2;
	const int blueValue = 3;
	const int alphaValue = 4;

	Color c(redValue, greenValue, blueValue, alphaValue);

	const std::array<std::pair<std::function<int(const Color&)>, int>,
		4> getterValuePairs =
		{
			std::make_pair(&Color::getRed, redValue),
			std::make_pair(&Color::getGreen, greenValue),
			std::make_pair(&Color::getBlue, blueValue),
			std::make_pair(&Color::getAlpha, alphaValue)
		};

	for (auto gvPair : getterValuePairs)
		REQUIRE(gvPair.first(c) == gvPair.second);
}

TEST_CASE("Color: check + operator", "[color]")
{
	/*
	 * Random values tested with GIMP
	 */
	Color c1(169, 80, 80, 148);
	Color c2(23, 241, 213, 54);
	Color c3 = c1 + c2;

	REQUIRE(c3.getRed() == 122);
	REQUIRE(c3.getGreen() == 130);
	REQUIRE(c3.getBlue() == 122);
	REQUIRE(c3.getAlpha() == 171);

	c1 += c2;

	REQUIRE(c3.getRed() == c1.getRed());
	REQUIRE(c3.getGreen() == c1.getGreen());
	REQUIRE(c3.getBlue() == c1.getBlue());
	REQUIRE(c3.getAlpha() == c1.getAlpha());
}
