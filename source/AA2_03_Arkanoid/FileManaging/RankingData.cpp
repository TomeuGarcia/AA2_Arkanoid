#include "RankingData.h"


RankingPlayer::RankingPlayer()
	: _name(""), _score(0) 
{}

RankingPlayer::RankingPlayer(const std::string & name, const int& score)
	: _name(name), _score(score)
{
}
