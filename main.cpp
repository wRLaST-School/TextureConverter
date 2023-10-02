#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <DirectXTex.h>
#include "TextureConverter.h"

using namespace std;

enum Argument {
	APPLICATION_PATH,
	FILE_PATH,

	NUM_ARGS
};

int main(int argc, char* argv[]) {
	
	assert(argc >= NUM_ARGS);

	//Init COM
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;

	int32_t numOptions = argc - NUM_ARGS;
	char** options = argv + NUM_ARGS;

	converter.ConvertTextureWIC2DDS(argv[FILE_PATH], numOptions, options);

	cout << "Loading " << argv[FILE_PATH] << endl;

	//Close Com
	CoUninitialize();

	system("pause");
	
	return 0;
}