#pragma once

#include <string>
#include <vector>
#include <opencv2\core\mat.hpp>

namespace ImageBinarize
{

	class Color
	{
	public:
		Color(unsigned char red, unsigned char green, unsigned char blue)
			: _red(red)
			, _green(green)
			, _blue(blue)
		{
		}

		unsigned char red() const
		{
			return this->_red;
		}
		unsigned char green() const
		{
			return this->_green;
		}
		unsigned char blue() const
		{
			return this->_blue;
		}

	private:
		unsigned char _red;
		unsigned char _green;
		unsigned char _blue;
	};
	
	class Image
	{
	public:
		Image();
		Image(int width, int height);
		//	assuming data is in BGR format
		Image(const unsigned char *data, int width, int height);
		Image(const cv::Mat &sourceMat);
		Image(const std::vector<unsigned char> &data, int width, int height);
		~Image();

		//	TODO: implement
		//void load(const std::string &path);
		//void save(const std::string &path);

		bool isEqualFormat(const Image &other) const;

		void setPixelColor(int x, int y, const Color &color);
		Color pixelColor(int x, int y) const;

		int width() const;
		int height() const;

		cv::Mat &asOpenCVMat();
		const cv::Mat &asOpenCVMat() const ;

		void setMetaInfo(const std::string &value);
		std::string metaInfo() const;

	private:
		cv::Mat _mat;
	};

}