#include "Util.h"
#include <Windows.h>

std::wstring Util::Str2WStr(const std::string& str)
{
    int bufSize = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);

    std::wstring ret;

    ret.resize(bufSize);

    MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &ret[0], bufSize);

    return ret;
}
