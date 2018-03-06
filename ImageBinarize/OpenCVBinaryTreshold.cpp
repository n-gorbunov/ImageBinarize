#include "OpenCVBinaryTreshold.h"

#include <sstream>
#include <opencv2/imgproc/imgproc.hpp>

namespace ImageBinarize
{
	OpenCVBinaryTreshold::OpenCVBinaryTreshold()
	{
		//	default params
		this->_options["treshold"] = 127;
		this->_options["treshold_type"] = 0;
		this->_options["max_value"] = 255;
	}

	OpenCVBinaryTreshold::~OpenCVBinaryTreshold()
	{

	}

	bool OpenCVBinaryTreshold::process(const Image &in, Image &out)
	{
		const cv::Mat &src = in.asOpenCVMat();
		cv::Mat &dst = out.asOpenCVMat();

		const int threshold = static_cast<int>(this->_options["treshold"]);
		const int maxValue = static_cast<int>(this->_options["max_value"]);

		if (this->_options["treshold_type"] == 0) {
			// Binary Threshold
			cv::threshold(src, dst, threshold, maxValue, cv::THRESH_BINARY);
		}
		else {
			// Inverted Binary Threshold
			cv::threshold(src, dst, threshold, maxValue, cv::THRESH_BINARY_INV);
		}

		return true;
	}

	void OpenCVBinaryTreshold::setOption(const std::string& name, double value)
	{
		this->_options[name] = value;
	}

	std::string OpenCVBinaryTreshold::metaData()
	{
		std::ostringstream ss;
		ss << "{";
		ss << "  \"type\": \"OpenCVBinaryTreshold\"," << std::endl;
	
		for (const auto& it : this->_options) {
			ss << "  \"" << it.first << "\": \"" << it.second << "\"," << std::endl;
		}
		ss << "}";
		return ss.str();
	}

}