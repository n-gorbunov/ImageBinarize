#include "ImageHistogram.h"

#include "Image.h"
#include "Utility.h"

namespace ImageBinarize
{
	ImageHistogram::ImageHistogram()
	{
	}

	ImageHistogram::ImageHistogram(const Image& image)
	{
		this->process(image);
	}

	ImageHistogram::~ImageHistogram()
	{
	}

	void ImageHistogram::clear()
	{
		this->_grayscale.fill(0);
		this->_red.fill(0);
		this->_green.fill(0);
		this->_blue.fill(0);
	}

	void ImageHistogram::setImage(const Image& image)
	{
		this->process(image);
	}

	const std::array<uint64_t, 256>& ImageHistogram::grayscale() const
	{
		return this->_grayscale;
	}

	const std::array<uint64_t, 256>& ImageHistogram::red() const
	{
		return this->_red;
	}

	const std::array<uint64_t, 256>& ImageHistogram::green() const
	{
		return this->_green;
	}

	const std::array<uint64_t, 256>& ImageHistogram::blue() const
	{
		return this->_blue;
	}

	void ImageHistogram::process(const Image& image)
	{
		this->clear();

		int width = image.width();
		int height = image.height();

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				Color pixelColor = image.pixelColor(x, y);
				uint8_t red = pixelColor.red();
				this->_red[red]++;
				uint8_t green = pixelColor.green();
				this->_green[green]++;
				uint8_t blue = pixelColor.blue();
				this->_blue[blue]++;

				this->_grayscale[Utility::grayscaleValue(red, green, blue)]++;
			}
		}
	}

}
