#pragma once

#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <cstdint>
#include <map>
#include <string>

namespace compat
{

enum CompatibilityState
{
    UNKNOWN = -1,
    NOTHING,
    BOOTABLE,
    INTRO,
    MENU,
    INGAME_LESS,
    INGAME_MORE,
    PLAYABLE,
};

struct Compatibility
{
    uint32_t issue_id;
    CompatibilityState state = UNKNOWN;
    time_t updated_at;
};

struct CompatState
{
    bool compat_db_loaded = false;
    std::map<std::string, Compatibility> app_compat_db;
    /*std::map<CompatibilityState, ImVec4> compat_color{
        { UNKNOWN, ImVec4(0.54f, 0.54f, 0.54f, 1.f) },
        { NOTHING, ImVec4(1.00f, 0.00f, 0.00f, 1.f) }, // #ff0000
        { BOOTABLE, ImVec4(0.39f, 0.12f, 0.62f, 1.f) }, // #621fa5
        { INTRO, ImVec4(0.77f, 0.08f, 0.52f, 1.f) }, // #c71585
        { MENU, ImVec4(0.11f, 0.46f, 0.85f, 1.f) }, // #1d76db
        { INGAME_LESS, ImVec4(0.88f, 0.54f, 0.12f, 1.f) }, // #e08a1e
        { INGAME_MORE, ImVec4(1.00f, 0.84f, 0.00f, 1.f) }, // #ffd700
        { PLAYABLE, ImVec4(0.05f, 0.54f, 0.09f, 1.f) }, // #0e8a16
    };

    // In order for this to be uncommented out, we will need a colour system for whatever GUI system will be used

    */
};

}

#endif // STATE_HPP_INCLUDED