#include "FileManager.h"

FileManager::FileManager() : _content(), _document() {}

GameData* FileManager::LoadGameData(const char* filePath)
{
	std::ifstream file(filePath);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();

	_content = buffer.str();
	_document.parse<0>(&_content[0]);

	// Defining and initializing root node
	rapidxml::xml_node<>* rootPtr = _document.first_node();


	GameData* gameData = new GameData();
	std::string stringHolder;


	// Getting Brick Info
	rapidxml::xml_node<>* nodePtr = rootPtr->first_node("BrickInfo");
	for (rapidxml::xml_node<>* brickInfoNodePtr = nodePtr->first_node(); brickInfoNodePtr; brickInfoNodePtr = brickInfoNodePtr->next_sibling()) {
		stringHolder = brickInfoNodePtr->name();

		gameData->SetBrickInfo(stringHolder,
							   std::stoi(brickInfoNodePtr->first_attribute("min")->value()),
							   std::stoi(brickInfoNodePtr->first_attribute("max")->value()));
	}


	// Getting Level Info
	nodePtr = rootPtr->first_node("Level");
	gameData->SetPlatformSpeed(std::stoi(nodePtr->first_attribute("PlatformSpeed")->value()));

	for (rapidxml::xml_node<>* levelNodePtr = nodePtr->first_node(); levelNodePtr; levelNodePtr = levelNodePtr->next_sibling()) {
		stringHolder = levelNodePtr->first_attribute("type")->value();

		gameData->SetLevelBricks(std::stoi(levelNodePtr->first_attribute("i")->value()),
								 std::stoi(levelNodePtr->first_attribute("j")->value()),
								 stringHolder);
	}


	return gameData;
}