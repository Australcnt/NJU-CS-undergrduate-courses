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

//���캯��
MusicBoard::MusicBoard()
/* ˵�������캯������ʼ����Ҫ�������*/
{
	;
}

//���캯��
MusicBoard::MusicBoard(vector<string> music_list)
/* ˵��������string���͵�vector��������ȡ������vector�е�Ԫ�أ���������ְ�*/
{
    for (auto i = music_list.begin(); i != music_list.end(); i++)
    {
        string pattern = "|";
        vector<string>info = split(*i, pattern);
        Music music(info[0], info[1], stoi(info[2]), info[3], info[4]);
        this->music_list.push_back(music);
    }
}

//��Ա����������µ�������Ϣ
bool MusicBoard::addMusic(Music& music)
/* ˵��
* 1) �����������������ֵ�������ͬ�����Ǹ��ֲ�ͬ������Ϊ��ͬһ���֣���ӳɹ�
* 2) ������ΪΪͬһ���֣����ʧ��
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

//��Ա����������label�Ե�Ӱ������
//���ݵ�������count�Ӹߵ�������
void MusicBoard::sortMusic(string label)
/* ˵��
* 1) �ñ�ǩֻ��ΪcommentCount��releaseDate
* 2) ��ΪcommentCount���������������������ǰ
* 3) ��ΪreleaseDate������ʱ�������ǰ
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

//��Ա���������ص�ǰ���и�������������
Music MusicBoard::getByIndex(int index)
{
    return music_list[index];
}

//���ݷ��й��ҹ��ˣ������µ����ְ�
MusicBoard MusicBoard::filter(string nation)
/* ˵����filter��ԭboard����ı�*/
{
    vector<Music>musiclist;
    copy_if(music_list.begin(), music_list.end(), back_inserter(musiclist), [nation](Music& music) {return music.nation == nation; });
    MusicBoard musicboard;
    for (auto i = musiclist.begin(); i != musiclist.end(); i++)
        musicboard.addMusic(*i);
    return musicboard;
}