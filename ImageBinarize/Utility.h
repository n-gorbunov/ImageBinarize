#pragma once

namespace ImageBinarize
{
	class Utility
	{
	public:
		static uint8_t grayscaleValue(uint8_t r, uint8_t g, uint8_t b)
		{
			double result = (299. * r + 587. * g + 114. * b) / 1000;
			return static_cast<uint8_t>(result);
		}
	};
}