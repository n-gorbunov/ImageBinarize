#include "OtsuThreshold.h"

#include <array>

#include "Utility.h"

namespace ImageBinarize
{

	OtsuThreshold::OtsuThreshold(const Image& image, Channel channel)
		: _channel(channel)
	{
		this->calculateTreshold(image);
	}

	OtsuThreshold::~OtsuThreshold()
	{

	}

	uint32_t OtsuThreshold::thresholdValue()
	{
		return this->_thresholdValue;
	}

	//	TODO: переделать с возможностью выбора каналов
	//	INFO: подсмотрено на https://habrahabr.ru/post/112079/
	void OtsuThreshold::calculateTreshold(const Image& image)
	{
		std::array<uint64_t, 256> hist;
		hist.fill(0);

		int width = image.width();
		int height = image.height();

		Color color = image.pixelColor(0, 0);
		uint8_t grayscale = Utility::grayscaleValue(color.red(), color.green(), color.blue());

		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				color = image.pixelColor(x, y);
				grayscale = Utility::grayscaleValue(color.red(), color.green(), color.blue());
				hist[grayscale]++;
			}
		}

		uint64_t m = 0;
		uint64_t n = 0;
		for (unsigned int i = 0; i < hist.size(); ++i) {
			m += i * hist[i];
			n += hist[i];
		}

		float maxSigma = -1;
		int threshold = 0;

		uint64_t alpha1 = 0;
		uint64_t beta1 = 0;
		for (unsigned int i = 0; i < hist.size(); ++i) {
			alpha1 += i * hist[i];
			beta1 += hist[i];

			float w1 = (float)beta1 / n;
			float a = (float)alpha1 / beta1 - (float)(m - alpha1) / (n - beta1);
			float sigma = w1 * (1 - w1) * a * a;
			if (sigma > maxSigma) {
				maxSigma = sigma;
				threshold = i;
			}
		}

		this->_thresholdValue = threshold;
	}

}