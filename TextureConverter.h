#pragma once
#include <string>
#include <DirectXTex.h>
class TextureConverter
{
public:
	//Convert Texture from WIC to DDS
	void ConvertTextureWIC2DDS(const std::string& filePath, int numOptions = 0, char* options[] = nullptr);

private:
	void LoadWICTexture(const std::string& filePath);
	void SeparatePath(const std::wstring& filePath);

	void SaveDDSTextureToFile(int numOptions = 0, char* options[] = nullptr);

	DirectX::TexMetadata metadata_;
	DirectX::ScratchImage scratchImage_;

	std::wstring folderPath_;
	std::wstring fileName_;
	std::wstring fileExtension_;
};

