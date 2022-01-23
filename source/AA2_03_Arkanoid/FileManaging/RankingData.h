#pragma once
#include <iostream>


struct RankingPlayer {
	RankingPlayer();
	RankingPlayer(const std::string& name, const int& score);

	std::string _name;
	int _score;

	bool operator< (const RankingPlayer& other) { return _score < other._score; }
	bool operator!= (const RankingPlayer& other) { return (_score != other._score) && (_name != other._name); }
};



