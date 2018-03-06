#pragma once

#include <map>
#include "IBinarizationAlgorithm.h"

namespace ImageBinarize
{

	class OpenCVBinaryTreshold : public IBinarizationAlgorithm
	{
	public:
		OpenCVBinaryTreshold();
		~OpenCVBinaryTreshold();

		virtual bool process(const Image &in, Image &out) override;
		virtual void setOption(const std::string& name, double value) override;
		virtual std::string metaData() override;

	private:
		std::map<std::string, double> _options;
	};

}