﻿#include "Image.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

//	DEBUG
#include <iostream>
//	END DEBUG

namespace ImageBinarize
{

	Image::Image()
	{
	}

	Image::Image(int width, int height)
		: _mat(Mat(height, width, CV_8UC3, cvScalar(0, 0, 0)))
	{
	}

	Image::Image(const std::string& path)
	{
		this->loadFromFile(path);
	}
	
	Image::Image(const unsigned char *data, int width, int height)
	{
		//	TODO: implement
	}

	Image::Image(const cv::Mat &sourceMat)
	{
		this->_mat = sourceMat;
	}

	Image::Image(const std::vector<unsigned char> &data, int width, int height)
	{
		//	TODO: implement
	}

	Image::~Image()
	{
	}

	void Image::clear()
	{
		this->_mat = cv::Mat();
	}

	bool Image::isNull() const
	{
		return !this->_mat.data;
	}

	void Image::convertToGrayscale()
	{
		Mat gray;
		cvtColor(this->_mat, gray, COLOR_BGR2GRAY);
		this->_mat = gray;
	}

	/*bool Image::fromFile(const std::string &path)
	{
		this->_mat = imread(path, cv::IMREAD_COLOR);
		if (!this->_mat.data) {
			this->_mat = Mat();
			return false;
		}

		return true;
	}*/

	bool Image::isEqualFormat(const Image &other) const
	{
		if (this->_mat.empty() && other._mat.empty())
			return true;

		if (this->_mat.cols != other._mat.cols || this->_mat.rows != other._mat.rows)
			return false;

		return true;
	}

	void Image::setPixelColor(int x, int y, const Color& color)
	{
		if (x >= this->_mat.rows || y >= this->_mat.cols)
			return;

		this->_mat.at<Vec3b>(y, x) = Vec3b(color.blue(), color.green(), color.red());
	}

	Color Image::pixelColor(int x, int y) const
	{
		Vec3b bgrColors = this->_mat.at<Vec3b>(y, x);
		return Color(bgrColors.val[2], bgrColors.val[1], bgrColors.val[0]);
	}

	int Image::width() const
	{
		return this->_mat.cols;
	}

	int Image::height() const
	{
		return this->_mat.rows;
	}

	cv::Mat& Image::asOpenCVMat()
	{
		return this->_mat;
	}

	const cv::Mat &Image::asOpenCVMat() const
	{
		return this->_mat;
	}

	void Image::setMetaInfo(const std::string &value)
	{

	}

	std::string Image::metaInfo() const
	{
		return std::string();
	}

	bool Image::loadFromFile(const std::string &path)
	{
		if (path.empty())
			return false;

		Mat tmp = imread(path, cv::IMREAD_ANYCOLOR);
		if (!tmp.data)
			return false;

		this->_mat = tmp;
		return true;
	}

	bool Image::saveToFile(const std::string &path)
	{
		if (path.empty())
			return false;

		if (this->isNull())
			return false;

		imwrite(path, this->_mat);
		return true;
	}

}