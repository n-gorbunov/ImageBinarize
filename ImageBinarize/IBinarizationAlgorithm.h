#pragma once

#include <map>
#include <string>
#include <vector>

#include "Image.h"

namespace ImageBinarize
{

	class BinarizationAlgorithm
	{
	protected:
		virtual ~BinarizationAlgorithm() {};
		virtual void setOption(const std::string& name, double value) = 0;
		virtual bool process(const Image &in, Image &out) = 0;
		virtual std::string metaData() = 0;

	protected:
		std::map<std::string, double> _options;
	};

}