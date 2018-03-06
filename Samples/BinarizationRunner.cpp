#include "BinarizationRunner.h"

#include <string>
#include <opencv2/core/Mat.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <DumbBinarize.h>
#include <OpenCVBinaryTreshold.h>
#include <ImageBinarizer.h>

using namespace cv;
using namespace ImageBinarize;

void populateFilesList(std::vector<std::string> &imageList)
{
	imageList.push_back("!in\\gofra-snabzhennaja-protjazhkoj-zondom.jpg");
	imageList.push_back("!in\\gofrirovannaya-truba-dlya-elektroprovodki.jpg");
	imageList.push_back("!in\\metallicheskaya-gofra.jpg");
}

void BinarizationRunner::runOpenCVTreshold()
{
	const std::string sourcePath = "../!in/ml.png";
	const std::string resultPath = "../!out/ml.bin.png";

	ImageBinarizer<OpenCVBinaryTreshold> binarizer;
	binarizer.process(sourcePath, resultPath);
}

void BinarizationRunner::runDumbTreshold()
{
	const std::string sourcePath = "../!in/gofra-snabzhennaja-protjazhkoj-zondom.jpg";
	const std::string resultPath = "../!out/gofra-snabzhennaja-protjazhkoj-zondom.bin.png";

	ImageBinarizer<DumbBinarize> binarizer;
	binarizer.process(sourcePath, resultPath);
}
