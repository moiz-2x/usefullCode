#include "Error.h"

Error::Error(int flag)
{
	Error::hFile = nullptr;
	if (flag == 0)
	{
		Error::type = console;
	}
	else if (flag == 1)
	{
		Error::type = file;
		Error::hFile = new std::wofstream("error.txt", std::ios_base::app);
	}
	else
	{
		std::wcout << "[-] Cann't set {console or file} type in {Error class}\n";
	}
}

Error::~Error() 
{
	Error::hFile->close();
	delete Error::hFile;
};

void Error::PrintError(std::wstring message, std::wstring from, int ErrorCode)
{
	if (Error::type == console)
	{
		std::wcout << "[-] Error while {" << message << "} from {" << from << "}, Error Code: " << ErrorCode << std::endl;
	}
	else if (Error::type == file)
	{
		
		std::wstring output = L"[-] Error while {";
		output.append(message);
		output.append(L"} from {");
		output.append(from);
		output.append(L"}, Error Code: ");
		std::wstring text_errorcode = std::to_wstring(ErrorCode);
		output.append(text_errorcode);
		output.append(L"\n");

		Error::hFile->write(&output[0], output.length());
	
		///output.clear();
	}
}
