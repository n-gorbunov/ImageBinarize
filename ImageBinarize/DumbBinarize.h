#pragma once

//	very simple treshold algorithm

#include "IBinarizationAlgorithm.h"

namespace ImageBinarize
{

	class DumbBinarize : public BinarizationAlgorithm
	{
	public:
		DumbBinarize(double treshold = 127);
		~DumbBinarize();

		virtual bool process(const Image &in, Image &out) override;

		virtual void setOption(const std::string& name, double value) override;
		virtual std::string metaData() override;

	private:
		double brightness(unsigned int red, unsigned int green, unsigned int blue);

	private:
		double _treshold;
	};

}