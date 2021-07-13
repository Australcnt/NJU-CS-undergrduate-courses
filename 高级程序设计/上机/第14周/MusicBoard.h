#pragma once
#include "Music.h"
#include <vector>
#include <algorithm>

class MusicBoard
{
public:
	vector<Music> music_list;
public:
	MusicBoard();
	MusicBoard(vector<string> music_list);
	bool addMusic(Music& music);
	void sortMusic(string label);
	Music getByIndex(int index);
	MusicBoard filter(string nation);
};