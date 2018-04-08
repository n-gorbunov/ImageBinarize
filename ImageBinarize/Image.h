#pragma once

#include <string>
#include <vector>
#include <opencv2/core/mat.hpp>

namespace ImageBinarize
{

	//	TODO: move to separate file
	class Color
	{
	public:
		Color(uint8_t red, uint8_t green, uint8_t blue)
			: _red(red)
			, _green(green)
			, _blue(blue)
		{
		}

		uint8_t red() const
		{
			return this->_red;
		}
		uint8_t green() const
		{
			return this->_green;
		}
		uint8_t blue() const
		{
			return this->_blue;
		}

	private:
		uint8_t _red;
		uint8_t _green;
		uint8_t _blue;
	};
	
	class Image
	{
	public:
		Image();
		Image(int width, int height);
		Image(const std::string& path);
		//	assuming data is in BGR format
		Image(const unsigned char *data, int width, int height);
		Image(const cv::Mat &sourceMat);
		Image(const std::vector<unsigned char> &data, int width, int height);
		~Image();

		void clear();
		bool isNull() const;

		void convertToGrayscale();

		bool isEqualFormat(const Image &other) const;

		void setPixelColor(int x, int y, const Color &color);
		Color pixelColor(int x, int y) const;

		int width() const;
		int height() const;

		cv::Mat &asOpenCVMat();
		const cv::Mat &asOpenCVMat() const ;

		void setMetaInfo(const std::string &value);
		std::string metaInfo() const;

		bool loadFromFile(const std::string &path);
		bool saveToFile(const std::string &path);

	private:
		cv::Mat _mat;
	};

}