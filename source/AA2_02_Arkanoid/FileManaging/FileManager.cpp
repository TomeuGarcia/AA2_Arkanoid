#include "FileManager.h"

FileManager::FileManager() : _content(), _document() {}

FileManager::~FileManager() 
{
	_content.clear();
	_document.clear();
}

GameData* FileManager::LoadGameData(const char* filePath)
{
	std::ifstream file(filePath);
	if (!file.is_open()) {
		throw std::exception("Couldn't open config.xml file\n");
	}

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



	// Getting PowerUp Info
	nodePtr = rootPtr->first_node("PowerUpInfo");

	float powerUpSpawnChance{ std::stof(nodePtr->first_attribute("PowerUpChancePercent")->value()) };
	float powerUpDuration{ std::stof(nodePtr->first_attribute("PowerUpDuration")->value()) };
	float powerUpSpeed{ std::stof(nodePtr->first_attribute("PowerUpSpeed")->value()) };

	rapidxml::xml_node<>* powerupInfoNodePtr = nodePtr->first_node("ExtraLength");
	float sizeIncreasePercent{ std::stof(powerupInfoNodePtr->first_attribute("SizeIncreasePercent")->value()) };

	powerupInfoNodePtr = nodePtr->first_node("MiniLength");
	float sizeDecreasePercent{ std::stof(powerupInfoNodePtr->first_attribute("SizeDecreasePercent")->value()) };
	float speedIncreasePercent{ std::stof(powerupInfoNodePtr->first_attribute("SpeedIncreasePercent")->value()) };
	
	gameData->SetPowerUpData(powerUpSpawnChance, powerUpDuration, powerUpSpeed,
		sizeIncreasePercent, sizeDecreasePercent, speedIncreasePercent);
	


	// Getting Level Info
	nodePtr = rootPtr->first_node("Level");
	gameData->SetPlatformSpeed(std::stoi(nodePtr->first_attribute("PlatformSpeed")->value()));
	gameData->SetBallSpeed(std::stoi(nodePtr->first_attribute("BallSpeed")->value()));

	for (rapidxml::xml_node<>* levelNodePtr = nodePtr->first_node(); levelNodePtr; levelNodePtr = levelNodePtr->next_sibling()) {
		stringHolder = levelNodePtr->first_attribute("type")->value();

		gameData->SetLevelBricks(std::stoi(levelNodePtr->first_attribute("i")->value()),
								 std::stoi(levelNodePtr->first_attribute("j")->value()),
								 stringHolder);
	}

	_content.clear();
	_document.clear();

	return gameData;
}