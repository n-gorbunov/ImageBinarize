#include "ArgumentsParser.h"

#if defined(WIN32) || defined(_WIN64)
#include <Windows.h>
#endif
#include <boost/program_options.hpp>

using namespace boost::program_options;
using namespace std;

ArgumentsParser::ArgumentsParser(int argc, wchar_t *argv[])
	: _showHelp(false)
	, _listSmartCards(false)
{
#if defined(WIN32) || defined(_WIN64)
	this->_rawArguments = ArgumentsParser::getNativeArguments();
#else
	this->_rawArguments = std::vector<std::string>(argv, argv + argc);
#endif
	this->parseCommandLineArguments(this->_rawArguments);
}

ArgumentsParser::~ArgumentsParser()
{
}

void ArgumentsParser::showHelp()
{

}

bool ArgumentsParser::help() const
{
	return this->_showHelp;
}

std::wstring ArgumentsParser::at(unsigned int index)
{
	return this->_rawArguments.at(index);
}

const std::vector<std::wstring> &ArgumentsParser::commandLineArguments() const
{
	return this->_rawArguments;
}

std::vector<std::wstring> ArgumentsParser::getNativeArguments()
{
	std::vector<std::wstring> result;

#if defined(WIN32) || defined(_WIN64)
	PWSTR *argv = nullptr;
	int argc = 0;

	argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (argv == NULL)
		return result;

	for (int i = 0; i < argc; i++) {
		if (!argv[i])
			continue;

		std::wstring arg(argv[i]);
		result.push_back(arg);
	}

	LocalFree(argv);
#endif

	return result;
}

void ArgumentsParser::parseCommandLineArguments(const std::vector<std::wstring> &args)
{
	variables_map optionsMap;
	options_description desc("Allowed options");
	desc.add_options()
		("help", "print help message");

	wparsed_options parsed = wcommand_line_parser(args).options(desc).allow_unregistered().run();
	store(parsed, optionsMap);
	notify(optionsMap);

	if (optionsMap.count("help")) {
		this->_showHelp = true;
	}
}
