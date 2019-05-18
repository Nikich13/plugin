#ifndef SMMO_PROTOSHARP_PATHS_H_
#define SMMO_PROTOSHARP_PATHS_H_

#include <algorithm>
#include <string>

namespace protosharp
{
//newExt must not contain leading dot '.'
inline void ReplaceExtInplace(std::string &str,
                              const std::string &newExt)
{
    std::string delimiters = "\\/.";

    auto it = std::find_first_of(str.rbegin(),str.rend(),delimiters.begin(),delimiters.end());

    if(it == str.rend() || *it != '.')
        return;

    str.erase(it.base(),str.end());
    str.append(newExt);
}

//newExt must not contain leading dot '.'
inline std::string ReplaceExt(std::string str,
                              const std::string &newExt)
{
    ReplaceExtInplace(str,newExt);

    return str;
}
}
#endif