#include "TextureConverter.h"
#include "Util.h"

void TextureConverter::ConvertTextureWIC2DDS(const std::string& filePath)
{
	//テクスチャ読み込み
	LoadWICTexture(filePath);
}

void TextureConverter::LoadWICTexture(const std::string& filePath)
{
	std::wstring path = Util::Str2WStr(filePath);
}
