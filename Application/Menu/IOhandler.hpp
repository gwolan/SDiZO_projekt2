#pragma once

#include <string>


// handles console input and output


class IOhandler
{
    public:
    IOhandler(const std::string& menuContent);
    ~IOhandler() = default;

    void printMenu();
    void readMenuSelection();
    std::string getCurrentMenuSelection();
    void setMenuContent(const std::string& menuContent);


    private:
    std::string currentSelection;
    std::string menu;
};
