#pragma once
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<TlHelp32.h>
#include<string>
#include <fstream>

#define UNICODE 1

enum flag
{
	console,
	file
};

class Error
{
public:
	Error(int flag);
	~Error();

	void PrintError(std::wstring message, std::wstring from, int ErrorCode);

private:
	enum flag type;
	std::wofstream* hFile;
};

