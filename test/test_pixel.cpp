#include "catch.hpp"

#include "pixel.h"

TEST_CASE("Pixel: check constructor", "[pixel]")
{
	Pixel p(Color(1, 2, 3, 4));

	REQUIRE(p.getColor().getRed() == 1);
	REQUIRE(p.getColor().getGreen() == 2);
	REQUIRE(p.getColor().getBlue() == 3);
	REQUIRE(p.getColor().getAlpha() == 4);
}

TEST_CASE("Pixel: check setter and getter", "[pixel]")
{
	Pixel p;
	p.setColor(Color(1, 2, 3, 4));

	REQUIRE(p.getColor().getRed() == 1);
	REQUIRE(p.getColor().getGreen() == 2);
	REQUIRE(p.getColor().getBlue() == 3);
	REQUIRE(p.getColor().getAlpha() == 4);
}

TEST_CASE("Pixel: check operator +", "[pixel]")
{
	/*
	 * Random values tested with GIMP
	 */
	Color c1(169, 80, 80, 148);
	Color c2(23, 241, 213, 54);
	Pixel p1(c1);
	Pixel p2(c2);

	Pixel p3 = p1 + p2;
	Color c3 = p3.getColor();

	REQUIRE(c3.getRed() == 122);
	REQUIRE(c3.getGreen() == 130);
	REQUIRE(c3.getBlue() == 122);
	REQUIRE(c3.getAlpha() == 171);

	p1 += p2;

	REQUIRE(c3.getRed() == p1.getColor().getRed());
	REQUIRE(c3.getGreen() == p1.getColor().getGreen());
	REQUIRE(c3.getBlue() == p1.getColor().getBlue());
	REQUIRE(c3.getAlpha() == p1.getColor().getAlpha());
}
