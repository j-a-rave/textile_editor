#pragma once

#include <string>
#include <windows.h>

std::string dialog_open(wchar_t const * filter = L"All Files (*.*)\0*.*\0", HWND owner = NULL);
std::string dialog_save(wchar_t const * filter = L"All Files (*.*)\0*.*\0", HWND owner = NULL);