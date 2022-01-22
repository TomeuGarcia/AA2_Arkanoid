#pragma once
#include <iostream>
#include <map>


struct RankingPlayer {
	RankingPlayer();
	RankingPlayer(const std::string& name, const int& score);

	std::string _name;
	int _score;
};

bool operator< (const RankingPlayer& rp1, const RankingPlayer& rp2);

