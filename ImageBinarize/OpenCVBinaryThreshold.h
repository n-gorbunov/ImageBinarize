#pragma once


#include "IBinarizationAlgorithm.h"

namespace ImageBinarize
{

	class OpenCVBinaryThreshold : public BinarizationAlgorithm
	{
	public:
		OpenCVBinaryThreshold();
		~OpenCVBinaryThreshold();

		virtual bool process(const Image &in, Image &out) override;
		virtual void setOption(const std::string& name, double value) override;
		virtual std::string metaData() override;

	private:
		std::map<std::string, double> _options;
	};

}