#pragma once
#include <iostream>
#include <sstream>

#include "../../../dependencies/XML/rapidxml.hpp"
#include "../../../dependencies/XML/rapidxml_utils.hpp"
#include "../../../dependencies/XML/rapidxml_iterators.hpp"
#include "../../../dependencies/XML/rapidxml_print.hpp"

#include "GameData.h"

class FileManager {

public:
	FileManager();
	GameData* LoadGameData(const char* filePath);

private:
	std::string _content;
	rapidxml::xml_document<> _document;

};