#pragma once
#include <iostream>
#include <sstream>

#include "../../../dependencies/XML/rapidxml.hpp"
#include "../../../dependencies/XML/rapidxml_utils.hpp"
#include "../../../dependencies/XML/rapidxml_iterators.hpp"
#include "../../../dependencies/XML/rapidxml_print.hpp"

#include "GameData.h"
#include "RankingData.h"

#define RANKING_SIZE 10


class FileManager {

public:
	FileManager();
	~FileManager();
	GameData* LoadGameData(const char* filePath);

	void StoreRankingData(const char* filePath, std::vector<RankingPlayer>* rankingPlayers);
	std::vector<RankingPlayer>* GetRankingData(const char* filePath);

private:
	std::string _content;
	rapidxml::xml_document<> _document;

};