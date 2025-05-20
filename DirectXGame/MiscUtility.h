#pragma once

#include <string> //string, wstring

//string => wstring 文字列変換
std::wstring ConvertString(const std::string& str);

//wstring => string 文字列変換
std::string ConvertString(const std::wstring& str);