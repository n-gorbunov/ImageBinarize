#pragma once

#include <string>
#include <vector>

#include "Image.h"

namespace ImageBinarize
{

	class IBinarizationAlgorithm
	{
	protected:
		virtual ~IBinarizationAlgorithm() {};
		virtual void setOption(const std::string& name, double value) = 0;
		virtual bool process(const Image &in, Image &out) = 0;
		virtual std::string metaData() = 0;
	};

}