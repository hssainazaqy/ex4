#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>


//-----------------------------------------------------------
class DeckFileNotFound : public std::runtime_error{

public:
    DeckFileNotFound(): std::runtime_error("Deck File Error: File not found")
    {}
};
//-----------------------------------------------------------
class DeckFileFormatError : public std::runtime_error{

public:
    explicit DeckFileFormatError(int line):
        std::runtime_error("Deck File Error: File format error in line " + std::to_string(line))
    {}
};
//-----------------------------------------------------------
class DeckFileInvalidSize :  public std::runtime_error{
public:
    DeckFileInvalidSize():
            std::runtime_error("Deck File Error: Deck size is invalid")
    {}
};

#endif