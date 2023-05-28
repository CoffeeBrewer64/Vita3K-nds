#include <nitro/nitro_types.hpp>

const char *GetOpenMode(const OpenMode mode)
{
    switch(mode)
    {
        case OpenMode::Read:
        {
            return "rb";
        }
        case OpenMode::Write:
        {
            return "wb";
        }
        case OpenMode::Update:
        {
            return "ab";
        }
        default:
        {
            return nullptr;
        }
    }
}

bool CanReadWithMode(const OpenMode mode)
{
    return mode == OpenMode::Read;
}

bool CanWriteWithMode(const OpenMode mode)
{
    return (mode == OpenMode::Write) || (mode == OpenMode::Update);
}

size_t CopyBufferSize()
{
    return 0x100000;
}

size_t ReallocBufferSize()
{
    return 0x100000;
}
