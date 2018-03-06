#include "DumbBinarize.h"

#include <sstream>
#include <opencv2\core\matx.hpp>

using namespace cv;

namespace ImageBinarize
{

	DumbBinarize::DumbBinarize(double treshold)
		: _treshold(treshold)
	{
	}

	DumbBinarize::~DumbBinarize()
	{
	}

	void DumbBinarize::setOption(const std::string& name, double value)
	{
		if (name == "treshold") {
			this->_treshold = value;
		}
	}

	std::string DumbBinarize::metaData()
	{
		std::ostringstream ss;
		ss << "{";
		ss << "  \"type\": \"Treshold\",";
		ss << "  \"treshold\": " << this->_treshold;
		ss << "}"; 
		return ss.str();
	}

	bool DumbBinarize::process(const Image &in, Image &out)
	{
		if (!in.isEqualFormat(out))
			return false;

		int width = in.width();
		int height = in.height();

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				Color pixelColor = in.pixelColor(x, y);
				if (this->brightness(pixelColor.red(), pixelColor.green(), pixelColor.blue()) < this->_treshold) {
					out.setPixelColor(x, y, Color(0, 0, 0));
				}
				else {
					out.setPixelColor(x, y, Color(0xFF, 0xFF, 0xFF));
				}
			}
		}

		return true;
	}

	double DumbBinarize::brightness(unsigned int red, unsigned int green, unsigned int blue)
	{
		//	INFO: from https://www.w3.org/TR/AERT/#color-contrast
		//	BRIGHTNESS = (Red value X 299) + (Green value X 587) + (Blue value X 114)) / 1000

		double result = (299. * red + 587. * green + 114. * blue) / 1000;

		return result;
	}

}