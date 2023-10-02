#include "TextureConverter.h"
#include "Util.h"

using namespace DirectX;

void TextureConverter::ConvertTextureWIC2DDS(const std::string& filePath)
{
	//テクスチャ読み込み
	LoadWICTexture(filePath);
}

void TextureConverter::LoadWICTexture(const std::string& filePath)
{
	std::wstring path = Util::Str2WStr(filePath);

	HRESULT hr = LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);

	assert(SUCCEEDED(hr));

	SeparatePath(path);

	SaveDDSTextureToFile();
}

void TextureConverter::SeparatePath(const std::wstring& filePath)
{
	size_t pos1;

	std::wstring noExt;

	pos1 = filePath.rfind('.');

	if (pos1 != std::wstring::npos)
	{
		fileExtension_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);

		noExt = filePath.substr(0, pos1);
	}
	else
	{
		fileExtension_ = L"";
		noExt = filePath;
	}

	size_t posBS = noExt.rfind('\\');
	size_t posSlash = noExt.rfind('/');
	bool areBothNPOS = false;

	if (posBS == std::wstring::npos)
	{
		if (posSlash == std::wstring::npos)
		{
			//両方nposの場合
			folderPath_ = L"";
			fileName_ = noExt;
		}
		else
		{
			pos1 = posSlash;
		}
	}
	else if (posSlash == std::wstring::npos)
	{
		pos1 = posBS;
	}
	else
	{
		pos1 = max(posBS, posSlash);
	}

	if (pos1 != std::wstring::npos)
	{
		folderPath_ = noExt.substr(0, pos1 + 1);

		fileName_ = noExt.substr(pos1 + 1, noExt.size() - pos1 - 1);
	}

	return;
}

void TextureConverter::SaveDDSTextureToFile()
{
	ScratchImage mipChain;

	HRESULT hr = GenerateMipMaps(scratchImage_.GetImages(), scratchImage_.GetImageCount(), scratchImage_.GetMetadata(), TEX_FILTER_DEFAULT, 0, mipChain);

	if (SUCCEEDED(hr))
	{
		scratchImage_ = std::move(mipChain);
		metadata_ = scratchImage_.GetMetadata();
	}

	//Compress
	ScratchImage converted;
	hr = Compress(scratchImage_.GetImages(), scratchImage_.GetImageCount(), metadata_,
		DXGI_FORMAT_BC7_UNORM_SRGB, TEX_COMPRESS_BC7_QUICK | TEX_COMPRESS_SRGB_OUT | TEX_COMPRESS_PARALLEL, 1.0f, converted);

	if (SUCCEEDED(hr))
	{
		scratchImage_ = std::move(converted);
		metadata_ = scratchImage_.GetMetadata();
	}

	metadata_.format = MakeSRGB(metadata_.format);

	std::wstring filePath = folderPath_ + fileName_ + L".dds";

	hr = SaveToDDSFile(scratchImage_.GetImages(), scratchImage_.GetImageCount(), metadata_, DDS_FLAGS_NONE, filePath.c_str());

	assert(SUCCEEDED(hr));


}
