#include "file_dialog.h"
#include <locale>
#include <codecvt>

std::string dialog_open(wchar_t const * filter, HWND owner)
{
	OPENFILENAME ofn;
	wchar_t file_name[MAX_PATH] = L"";
	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = owner;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = file_name;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = L"";

	std::string file_name_str;

	if (GetOpenFileName(&ofn)) {
		file_name_str = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(file_name);
	}

	return file_name_str;
}

std::string dialog_save(wchar_t const* filter, HWND owner)
{
	OPENFILENAME ofn;
	wchar_t file_name[MAX_PATH] = L"";
	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = owner;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = file_name;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = L"";

	std::string file_name_str;

	if (GetSaveFileName(&ofn)) {
		file_name_str = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(file_name);
	}

	return file_name_str;
}