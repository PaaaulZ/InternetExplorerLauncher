#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{

	if (argc < 2) return -1;

	char* tempPath = nullptr;
	size_t sizeTempPath = 0;
	if (_dupenv_s(&tempPath, &sizeTempPath, "Temp") == 0 && tempPath != nullptr)
	{

		std::string htaPath = tempPath, htmPath = tempPath;
		htaPath += "\\wwie.hta";
		htmPath += "\\wwie.htm";
		std::string url = argv[1];

		std::ofstream fp;
		fp.open(htaPath);
		fp << "<body onload = \"window.location.href = \'wwie.htm\'; window.close(); \">";
		fp.close();
		fp.open(htmPath);
		fp << "<meta http-equiv=\"refresh\" content=\"0; URL = \'" << url << "\'\" />";
		fp.close();

		system(htaPath.c_str());
		free(tempPath);
		return 0;
	}
	else
	{
		return 1;
	}
}