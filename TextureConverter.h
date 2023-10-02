#pragma once
#include <string>
class TextureConverter
{
public:
	//Convert Texture from WIC to DDS
	void ConvertTextureWIC2DDS(const std::string& filePath);

private:
	void LoadWICTexture(const std::string& filePath);
};

