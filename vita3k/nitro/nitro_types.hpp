#pragma once

#ifndef NITRO_TYPES_HPP_INCLUDED
#define NITRO_TYPES_HPP_INCLUDED

#include <cstddef>

// No namespaces should be used; this needs to be as easy to access as possible

enum Position
{
    Begin,
    Current,
    End
};

enum OpenMode
{
    Read,
    Write,
    Update
};

enum FileCompression
{
    None,
    LZ77,
    ZIP,
    _7Z,
    RAR
};

size_t CopyBufferSize();
size_t ReallocBufferSize();

bool CanReadWithMode(const OpenMode mode);
bool CanWriteWithMode(const OpenMode mode);
const char *GetOpenMode(const OpenMode mode);

#endif // NITRO_TYPES_HPP_INCLUDED
