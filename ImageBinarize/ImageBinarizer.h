#pragma once

#include <vector>

#include "OpenCVBinaryTreshold.h"

namespace ImageBinarize
{

	template <typename BinarizationAlgorithm = OpenCVBinaryTreshold>
	class ImageBinarizer
	{
	public:
		ImageBinarizer() {};
		~ImageBinarizer() {};

		//	TODO: implement
		//	std::vector<std::string> supportedAlgorithms();

		void process(const std::string &sourcePath, const std::string &destinationPath)
		{
			const Mat original = imread(sourcePath, CV_LOAD_IMAGE_COLOR);
			Mat processed(original.rows, original.cols, CV_8UC3);

			this->_algorithm.process(Image(original), Image(processed));

			imwrite(destinationPath, processed);
		}

		//	TODO: implement
		//void process(const std::vector<unsigned char> &source, std::vector<unsigned char> &destination);

	private:
		BinarizationAlgorithm _algorithm;
	};
}