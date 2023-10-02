#pragma once
#include <string>
class TextureConverter
{
public:
	//Convert Texture from WIC to DDS
	void ConvertTextureWIC2DDS(const std::string& filePath);

private:
	void LoadWICTexture(const std::string& filePath);
	void SeparatePath(const std::wstring& filePath);

	void SaveDDSTextureToFile();

	TexMetadata metadata_;
	ScratchImage scratchImage_;

	std::wstring folderPath_;
	std::wstring fileName_;
	std::wstring fileExtension_;
};

