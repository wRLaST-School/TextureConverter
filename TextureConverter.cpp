#include "TextureConverter.h"
#include "Util.h"

void TextureConverter::ConvertTextureWIC2DDS(const std::string& filePath)
{
	//�e�N�X�`���ǂݍ���
	LoadWICTexture(filePath);
}

void TextureConverter::LoadWICTexture(const std::string& filePath)
{
	std::wstring path = Util::Str2WStr(filePath);
}
