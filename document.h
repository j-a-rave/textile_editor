#pragma once

#include <string>

#define EXTENSION_LEN 3

class document {
public:
	document() {}
	virtual ~document() = 0;
	virtual bool save() = 0;

	char extension[EXTENSION_LEN];
	std::wstring filter;
	std::string filepath;
	bool dirty;
};