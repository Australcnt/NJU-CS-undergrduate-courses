#include "Game.h"

#include <iostream>
using namespace std;

Game::Game()
{
	UI::Set_Window();
	UI::Hide_Cursor();
	srand((unsigned)time(NULL));
	state = RUNNING;
	num_x = 0;
	num_y = 0;
	plant_type = 0;
	score = 100;
	score_update_flag = false;
	timer = 0;
	zombie_speed = 70;
}

void Game::Menu() // ��ʼ��Ϸ/�˳���Ϸ
{
	int choice = 0;
	cin >> choice;
	if (choice == 1)
		Game_Start();
	else
		Quit();
}

void Game::Game_Start() // ��Ϸ��Ҫ�߼�
{
	srand((unsigned)time(NULL));
	Tip();
	garden.Print();
	Update_Score();
	store.Update_Sunshine(*this);
	store.Print();
	while(1)
	{
		switch(state) // ��ǰ��Ϸ״̬
		{
		case RUNNING: Running(); break;
		case PERCHASING: Perchasing(); break;
		case WEEDING: Weeding(); break;
		case PAUSING: Pausing(); break;
		default: break;
		}
		
		store.Sunshine_Produce(*this);
		
		for (int i = 0; i < PLANT_TYPE_MAX; i++)
		{
			if (store.plant_card[i].cooldown_flag == true)
				store.plant_card[i].Cool_Down();
		}
		store.Print();

		Create_Zombie();
		
		for (int i = 0; i < SWARD_NUM_Y; i++)
		{
			for (int j = 0; j < SWARD_NUM_X + 1; j++)
			{
				if (garden.swards[i][j].plant != NULL)
				{
					garden.swards[i][j].plant->Functioning(*this);
				}
				if (!garden.swards[i][j].zombies.empty())
				{
					for (auto k = garden.swards[i][j].zombies.begin(); k != garden.swards[i][j].zombies.end();)
					{
						if (!(*k)->Move(*this))
							k++;
						else
							//garden.swards[(*k)->num_y][(*k)->num_x + 1].Delete_Zombie(garden, *k);
							k = garden.swards[i][j].zombies.erase(k);
					}
				}
			}
		}

		if (score_update_flag == true)
			Update_Score();
		if (store.sunshine_update_flag == true)
			store.Update_Sunshine(*this);
		garden.Update_Swards();

		for (auto i = peas.begin(); i < peas.end(); )
		{
			if ((*i)->Move(*this))
				i = peas.erase(i);
			else
				i++;
		}

		Sleep(SLEEP_TIME);
	}
}

void Game::Game_Over() // ��ʾ��Ϸ������(�û�)�÷֣������Ϸ����
{
	system("cls");
	UI::Move_Cursor(WINDOW_LENGTH_X / 2 - 7, WINDOW_LENGTH_Y / 2 - 1);
	UI::Print_With_Color("## ��Ϸ���� ##", BACKGROUND_RED | DEFAULT_COLOR);
	UI::Move_Cursor(WINDOW_LENGTH_X / 2 - 7, WINDOW_LENGTH_Y / 2 + 1);
	UI::Print_With_Color("���շ�����", DEFAULT_COLOR);
	UI::Move_Cursor(WINDOW_LENGTH_X /2 + 3, WINDOW_LENGTH_Y / 2 + 1);
	UI::Print_With_Color(score, DEFAULT_COLOR);
	//UI::Move_Cursor(WINDOW_LENGTH_X /2 - 9, WINDOW_LENGTH_Y / 2 + 5);
	//UI::Print_With_Color("��������˳���Ϸ...", BACKGROUND_SELECTED_COLOR);
	UI::Set_Color(BACKGROUND_SELECTED_COLOR);
	UI::Move_Cursor(WINDOW_LENGTH_X /2 - 10, WINDOW_LENGTH_Y / 2 + 5);
	system("pause");
	UI::Set_Color(DEFAULT_COLOR);
	//if (getch())
    exit(-1);
}

void Game::Quit() // �˳���Ϸ
{
	exit(-1);
}

void Game::Running()// ��������
{
	char ch;
	if (_kbhit())
	{
		ch = _getch(); // ���жϺ���������ͬgetch()
		switch(ch)
		{
		case '1':
		case '2':
			plant_type = ch - '1';
			state = PERCHASING;
			Tip();
			store.plant_card[plant_type].select_flag = true;
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case 'x':
		case 'X':
			state = WEEDING;
			Tip();
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case ' ':
			//state = PAUSING;
			//Tip();
			Pausing();
			break;
		}
	}
}

void Game::Perchasing() // ����ֲ��
{
	garden.swards[num_y][num_x].select_flag = true;
	garden.swards[num_y][num_x].update_flag = true;
	garden.swards[num_y][num_x].Print_Select();
	char ch;
	if (_kbhit())
	{
		ch = _getch(); // ���жϺ���������ͬgetch()
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72://��
				if (num_y > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_y--;
				}
				break;
			case 75://��
				if (num_x > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_x--;
				}
				break;
			case 77://��
				if (num_x < SWARD_NUM_X - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_x++;
				}
				break;
			case 80://��
				if (num_y < SWARD_NUM_Y - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_y++;
				}
				break;
			default:
				break;
			}
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			garden.swards[num_y][num_x].Print_Select();
			break;
		case '1':
		case '2':
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].Print();
			plant_type = ch - '1';
			store.plant_card[plant_type].select_flag = true;
			store.plant_card[plant_type].Print();
			state = PERCHASING;
			Tip();
			break;
		case 'x':
		case 'X':
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].Print();
			state = WEEDING;
			Tip();
			break;
		case 27: // Esc��
			garden.swards[num_y][num_x].select_flag = false;
			garden.swards[num_y][num_x].update_flag = true;
			garden.swards[num_y][num_x].Print_Select();
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].Print();
			state = RUNNING;
			Tip();
			break;
		case '\r': // Enter��
			if (store.Perchase(plant_type, num_x, num_y, garden)) // �������ɹ�
			{ 
				garden.swards[num_y][num_x].select_flag = false;
				garden.swards[num_y][num_x].update_flag = true;
				garden.swards[num_y][num_x].Print_Select();
				store.plant_card[plant_type].select_flag = false;
				store.plant_card[plant_type].Print();
				state = RUNNING;
				Tip();
			}
			break;

		case ' ': //�ո����ͣ
			Pausing();
			break;
		default:
			break;
		}
	}
}

void Game::Weeding() // �Ƴ�ֲ��
{
	state = WEEDING;
	Tip();
	garden.swards[num_y][num_x].select_flag = true;
	garden.swards[num_y][num_x].Print_Select();
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72://��
				if (num_y > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_y--;
				}
				break;
			case 75://��
				if (num_x > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_x--;
				}
				break;
			case 77://��
				if (num_x < SWARD_NUM_X - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_x++;
				}
				break;
			case 80://��
				if (num_y < SWARD_NUM_Y - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					garden.swards[num_y][num_x].Print_Select();
					num_y++;
				}
				break;
			default:
				break;
			}
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			garden.swards[num_y][num_x].Print_Select();
			break;
		case '1':
		case '2':
			state = PERCHASING;
			Tip();
			break;
		case '\r': // Enter��
			if (garden.swards[num_y][num_x].plant!=NULL)
			{
				garden.swards[num_y][num_x].Delete_Plant();
				garden.swards[num_y][num_x].select_flag = false;
				garden.swards[num_y][num_x].update_flag = true;
				garden.swards[num_y][num_x].Print_Select();
				state = RUNNING;
				Tip();
			}
			break;
		case 27: // Esc��
			garden.swards[num_y][num_x].select_flag = false;
			garden.swards[num_y][num_x].update_flag = true;
			garden.swards[num_y][num_x].Print_Select();
			state = RUNNING;
			Tip();
			break;
		case ' ': // Space��
			Pausing();
			break;
		default:
			break;
		}
	}
}

void Game::Pausing() // ��ͣ��Ϸ
{
	STATE state_copy = state;
	state = PAUSING;
	Tip();
	while (1)
	{
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			if (ch == ' ') //�ո������ͣ
			{
				state = state_copy;
				Tip();
				break;
			}
		}
		Sleep(SLEEP_TIME);
	}
}

void Game::Add_Pea(Pea* pea) // ����㶹
{
	peas.push_back(pea);
}

void Game::Delete_Pea(Pea* pea)
{
	for (auto i = peas.begin(); i < peas.end(); i++) // ɾ���㶹
	{
		if (*i == pea)
		{
			i = peas.erase(i);
			break;
		}
	}
}

void Game::Tip()
{
	UI::Move_Cursor(0, STORE_LENGTH_Y);
	string str(WINDOW_LENGTH_X, ' ');
	cout << str;
	UI::Move_Cursor(0, STORE_LENGTH_Y);
	switch(state)
	{
	case RUNNING:
		UI::Print_With_Color(" ##��Ϸ��##  ��ֲ��\"1-2\"���ּ� | ������\"x\"�� | ��ͣ��Space��", TIP_COLOR);
		break;
	case PERCHASING:
		UI::Print_With_Color(" ##��ֲ��##  ѡ��\"1-2\"���ּ� | ȷ�ϣ�Enter�� | ȡ����Esc�� | ��ͣ��Space��", TIP_COLOR);
		break;
	case WEEDING:
		UI::Print_With_Color(" ##������##  ȷ�ϣ�Enter�� | ȡ����Esc�� | ��ͣ��Space��", TIP_COLOR);
		break;
	case PAUSING:
		UI::Print_With_Color(" ##��ͣ��##  ������Ϸ��Space��", TIP_COLOR);
		break;
	}
}

void Game::Create_Zombie() // ���ɽ�ʬ
{
	if (timer + 1 == zombie_speed)
	{
		for (int i = 0; i < score / 100; i++)
		{
			int zombie_type = rand() % ZOMBIE_TYPE_MAX;
			Zombie* zombie = new Zombie;
			switch (zombie_type)
			{
			case 0:
				zombie->Set(garden);
				break;
			default:
				break;
			}
			garden.swards[zombie->num_y][SWARD_NUM_X].Add_Zombie(garden, zombie);
		}
		timer = 0;
	}
	else
	{
		timer++;
	}
}

void Game::Update_Score()
{
	UI::Move_Cursor(141, 0);
	string str(10, ' ');
	cout << str;
	UI::Move_Cursor(141, 0);
	UI::Print_With_Color(score, DEFAULT_COLOR);
	score_update_flag = false;
}