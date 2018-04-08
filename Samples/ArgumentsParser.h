#pragma once

#include <string>
#include <vector>

class ArgumentsParser
{
public:
	ArgumentsParser(int argc, wchar_t *argv[]);
	virtual ~ArgumentsParser();

	void showHelp();

	bool help() const;

	std::wstring at(unsigned int index);
	const std::vector<std::wstring> &commandLineArguments() const;

private:
#if defined(WIN32) || defined(_WIN64)
	std::vector<std::wstring> getNativeArguments();
#endif
	void parseCommandLineArguments(const std::vector<std::wstring> &args);

private:
	bool _showHelp;
	std::vector<std::wstring> _rawArguments;
};
