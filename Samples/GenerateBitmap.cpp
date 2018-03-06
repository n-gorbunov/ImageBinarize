#include "GenerateBitmap.h"

std::vector<unsigned char> generateAsVectorChar(unsigned int width, unsigned int height)
{
	std::vector<unsigned char> result(width * height * 3);

	//	fill background
	for (unsigned int i = 0; i < width * height * 3; i += 3) {
		result[i] = 0x88;
		result[i + 1] = 0x88;
		result[i + 2] = 0x88;
	}

	unsigned int rectXMin = width / 4;
	unsigned int rectXMax = (3 * width) / 4;
	unsigned int rectYMin = height / 4;
	unsigned int rectYMax = (3 * height) / 4;

	for (int y = rectYMin; y < rectYMax; ++y) {
		for (int x = rectXMin; x < rectXMax; ++x) {
			result[3 * (y * width + x)] = 0x01;
			result[3 * (y * width + x) + 1] = 0xDF;
			result[3 * (y * width + x) + 2] = 0x01;
		}
	}

	return result;
}
