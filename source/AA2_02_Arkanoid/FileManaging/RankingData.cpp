#include "RankingData.h"


RankingPlayer::RankingPlayer()
	: _name(""), _score(0) 
{}

RankingPlayer::RankingPlayer(const std::string & name, const int& score)
	: _name(name), _score(score)
{
}

bool operator<(const RankingPlayer& rp1, const RankingPlayer& rp2)
{
	return rp1._score < rp2._score;
}
