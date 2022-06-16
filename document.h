#pragma once

#include <string>

class document {
public:
	document() {}
	virtual ~document();
	virtual bool save() = 0;
	virtual bool create_new() = 0;
	virtual bool open() = 0;

	std::string extension;
	std::wstring filter;
	std::string filepath;
	bool dirty;
};