#include "Textbox.h"

Textbox::Textbox()
{

}

Textbox::Textbox(int size, sf::Color color, bool sel)
{
    textbox.setCharacterSize(size);
    textbox.setColor(color);
    isSelected = sel;
    if(sel)
    {
        textbox.setString("_");
    }
    else textbox.setString("");
}


void Textbox::inputLogic(int charTyped)
    {
        if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
        {
            text << static_cast<wchar_t>(charTyped);
        }
        else if(charTyped == DELETE_KEY)
        {
            if(text.str().length() > 0)
            {
                deleteLastChar();
            }
        }
        textbox.setString(text.str() + L"_");
    }


void Textbox::deleteLastChar()
{
    std::wstring t = text.str();
    std::wstring newT = L"";
    for(int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    text.str(L"");
    text << newT;

    textbox.setString(text.str());
}

void Textbox::setSelected(bool sel)
{
    isSelected = sel;
    if(!sel)
    {
        std::wstring t = text.str();
        std::wstring newT = L"";
        for(int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        textbox.setString( newT );
    }
}

void Textbox::typeOn(sf::Event input)
{
    if(isSelected)
    {
        int charTyped = input.text.unicode;
        if(charTyped < 128 || (charTyped > 1039 && charTyped < 1104))
        {
            if(hasLimit)
            {
                if(text.str().length() <= limit)
                {
                    inputLogic(charTyped);
                }
                else if(text.str().length() > limit && charTyped == DELETE_KEY)
                {
                    deleteLastChar();
                }
            }
            else inputLogic(charTyped);
        }
    }
}