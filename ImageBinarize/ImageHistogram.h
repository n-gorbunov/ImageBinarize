#pragma once

#include <array>

namespace ImageBinarize
{
	class Image;
		
	class ImageHistogram
	{
	public:
		ImageHistogram();
		ImageHistogram(const Image& image);
		~ImageHistogram();

		void clear();
		void setImage(const Image& image);
	
		const std::array<uint64_t, 256> &grayscale() const;
		const std::array<uint64_t, 256> &red() const;
		const std::array<uint64_t, 256> &green() const;
		const std::array<uint64_t, 256> &blue() const;

	private:
		void process(const Image& image);

	private:
		//	TODO: порефакторить это все
		std::array<uint64_t, 256> _grayscale;
		std::array<uint64_t, 256> _red;
		std::array<uint64_t, 256> _green;
		std::array<uint64_t, 256> _blue;
	};

}