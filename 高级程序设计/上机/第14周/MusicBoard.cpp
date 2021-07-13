#include "MusicBoard.h"

vector<string> split(const string& str, const string& pattern)
{
    vector<string> ret;
    size_t start = 0, index = str.find_first_of(pattern, 0);
    while (index != str.npos)
    {
        if (start != index)
            ret.push_back(str.substr(start, index - start));
        start = index + 1;
        index = str.find_first_of(pattern, start);
    }
    if (!str.substr(start).empty())
        ret.push_back(str.substr(start));
    return ret;
}

//构造函数
MusicBoard::MusicBoard()
/* 说明：构造函数，初始不需要添加内容*/
{
	;
}

//构造函数
MusicBoard::MusicBoard(vector<string> music_list)
/* 说明：根据string类型的vector，逐条读取并解析vector中的元素，添加入音乐榜单*/
{
    for (auto i = music_list.begin(); i != music_list.end(); i++)
    {
        string pattern = "|";
        vector<string>info = split(*i, pattern);
        Music music(info[0], info[1], stoi(info[2]), info[3], info[4]);
        this->music_list.push_back(music);
    }
}

//成员函数，添加新的音乐信息
bool MusicBoard::addMusic(Music& music)
/* 说明
* 1) 若该音乐与已有音乐的名字相同，但是歌手不同，则认为非同一音乐，添加成功
* 2) 否则认为为同一音乐，添加失败
*/
{
    for (auto i = music_list.begin(); i != music_list.end(); i++)
    {
        if ((*i).name == music.name && (*i).singer == music.singer)
            return false;
    }
    music_list.push_back(music);
    return true;
}

//成员函数，根据label对电影榜单排序
//根据点评人数count从高到低排序
void MusicBoard::sortMusic(string label)
/* 说明
* 1) 该标签只会为commentCount和releaseDate
* 2) 若为commentCount，则评论人数多的音乐在前
* 3) 若为releaseDate，则发行时间早的在前
*/
{
	if(label=="commentCount")
    {
        sort(music_list.begin(), music_list.end(), [](Music& music1, Music& music2) {return music1.count > music2.count; });
    }
    else
    {
        sort(music_list.begin(), music_list.end(), [](Music& music1, Music& music2) {vector<string>date1, date2; string pattern = "-"; date1 = split(music1.date, pattern); date2 = split(music2.date, pattern); return date1[0] < date2[0]||(date1[0]==date2[0]&&date1[1]<date2[1])||(date1[0] == date2[0] && date1[1] == date2[1] &&date1[2]<date2[2]); });
    }
}

//成员函数，返回当前榜单中该索引处的音乐
Music MusicBoard::getByIndex(int index)
{
    return music_list[index];
}

//根据发行国家过滤，返回新的音乐榜单
MusicBoard MusicBoard::filter(string nation)
/* 说明：filter后原board无需改变*/
{
    vector<Music>musiclist;
    copy_if(music_list.begin(), music_list.end(), back_inserter(musiclist), [nation](Music& music) {return music.nation == nation; });
    MusicBoard musicboard;
    for (auto i = musiclist.begin(); i != musiclist.end(); i++)
        musicboard.addMusic(*i);
    return musicboard;
}