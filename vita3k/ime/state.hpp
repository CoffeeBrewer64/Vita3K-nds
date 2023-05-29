#pragma once

#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <ime/types.hpp>
#include <lang/state.hpp>

struct Ime
{
    ImeLangState lang;
    bool state = false;
    SceImeEditText edit_text;
    SceImeParam param;
    std::string enter_label;
    std::u16string str;
    uint32_t caps_level = 0;
    uint32_t caretIndex = 0;
    uint32_t event_id = SCE_IME_EVENT_OPEN;
};

#endif // STATE_HPP_INCLUDED
