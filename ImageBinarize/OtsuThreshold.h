#pragma once

#include "Image.h"

namespace ImageBinarize
{

	class OtsuThreshold
	{
	public:
		enum Channel
		{
			Grayscale = 0,
			Red,
			Green,
			Blue
		};

		OtsuThreshold(const Image& image, Channel channel = Grayscale);
		~OtsuThreshold();

		uint32_t thresholdValue();

	private:
		void calculateTreshold(const Image& image);

	private:
		Channel _channel;
		uint32_t _thresholdValue;
	};

}