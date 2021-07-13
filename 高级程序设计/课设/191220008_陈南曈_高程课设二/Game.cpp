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
	tip_update_flag = false;
	timer = 0;
	zombie_speed = 70;
}

void Game::Menu() // 开始游戏/退出游戏
{
	int choice = 0;
	cin >> choice;
	if (choice == 1)
		Game_Start();
	else
		Quit();
}

void Game::Game_Start() // 游戏主要逻辑
{
	srand((unsigned)time(NULL));
	Tip();
	garden.Print();
	Update_Score();
	store.Update_Sunshine(*this);
	store.Print();
	//Zombie* zombie = NULL;
	//zombie = new Zombie;
	//zombie->Set(garden, "普通僵尸", 100, 25, 20, 10, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
	//zombie = new Coneheadzombie;
	//zombie->Set(garden, "路障僵尸", 150, 25, 20, 15, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
	//zombie = new Newspaperzombie;
	//zombie->Set(garden, "读报僵尸", 125, 25, 20, 20, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
	//zombie = new Polevaultingzombie;
	//zombie->Set(garden, "撑杆僵尸", 125, 25, 20, 20, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
	//zombie = new Jackintheboxzombie;
	//zombie->Set(garden, "小丑僵尸", 100, 25, 20, 15, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
	//zombie = new Catapultzombie;
	//zombie->Set(garden, "投石僵尸", 250, 20, 20, 40, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
	//garden.swards[zombie->num_y][SWARD_NUM_X].Add_Zombie(garden, zombie);

	while(1)
	{
		switch(state) // 当前游戏状态
		{
		case RUNNING: Running(); break;
		case PERCHASING: Perchasing(); break;
		case WEEDING: Weeding(); break;
		case PAUSING: Pausing(); break;
		default: break;
		}
		
		if(tip_update_flag)
		{
			Tip();
			tip_update_flag = false;
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
					if (!garden.swards[i][j].plant->Functioning(*this))
						garden.swards[i][j].Delete_Plant();
				}
				if (!garden.swards[i][j].zombies.empty())
				{
					for (auto k = garden.swards[i][j].zombies.begin(); k != garden.swards[i][j].zombies.end();)
					{
						if ((*k)->Move(*this))
							k++;
						else
							//garden.swards[(*k)->num_y][(*k)->num_x + 1].Delete_Zombie(garden, *k);
							k = garden.swards[i][j].zombies.erase(k);
					}
					int n = 0;
					for (auto m = garden.swards[i][j].zombies.begin(); m < garden.swards[i][j].zombies.end(); m++, n++)
							(*m)->Locate(garden, n);
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
				i++;
			else
				i = peas.erase(i);
		}
		//garden.Update_Swards();

		Sleep(SLEEP_TIME);
	}
}

void Game::Game_Over() // 显示游戏结束和(用户)得分，清空游戏数据
{
	system("cls");
	UI::Move_Cursor(WINDOW_LENGTH_X / 2 - 7, WINDOW_LENGTH_Y / 2 - 1);
	UI::Print_With_Color("## 游戏结束 ##", BACKGROUND_RED | DEFAULT_COLOR);
	UI::Move_Cursor(WINDOW_LENGTH_X / 2 - 7, WINDOW_LENGTH_Y / 2 + 1);
	UI::Print_With_Color("最终分数：", DEFAULT_COLOR);
	UI::Move_Cursor(WINDOW_LENGTH_X /2 + 3, WINDOW_LENGTH_Y / 2 + 1);
	UI::Print_With_Color(score, DEFAULT_COLOR);
	UI::Set_Color(BACKGROUND_SELECTED_COLOR);
	UI::Move_Cursor(WINDOW_LENGTH_X /2 - 10, WINDOW_LENGTH_Y / 2 + 5);
	system("pause");
	UI::Set_Color(DEFAULT_COLOR);
    exit(-1);
}

void Game::Quit() // 退出游戏
{
	exit(-1);
}

void Game::Running()// 正常运行
{
	char ch;
	if (_kbhit())
	{
		ch = _getch(); // 非中断函数，功能同getch()
		switch(ch)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			plant_type = ch - '1';
			state = PERCHASING;
			tip_update_flag = true;
			store.plant_card[plant_type].select_flag = true;
			store.plant_card[plant_type].update_flag = true;
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case 'a':
		case 'A':
			if (ch >= 'A')
				plant_type = ch - 'A' + 9;
			else
				plant_type = ch - 'a' + 9;
			state = PERCHASING;
			tip_update_flag = true;
			store.plant_card[plant_type].select_flag = true;
			store.plant_card[plant_type].update_flag = true;
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case 'x':
		case 'X':
			state = WEEDING;
			tip_update_flag = true;
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case ' ':
			Pausing();
			break;
		}
	}
}

void Game::Perchasing() // 购买植物
{
	garden.swards[num_y][num_x].select_flag = true;
	garden.swards[num_y][num_x].update_flag = true;
	char ch;
	if (_kbhit())
	{
		ch = _getch(); // 非中断函数，功能同getch()
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72://上
				if (num_y > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_y--;
				}
				break;
			case 75://左
				if (num_x > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_x--;
				}
				break;
			case 77://右
				if (num_x < SWARD_NUM_X - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_x++;
				}
				break;
			case 80://下
				if (num_y < SWARD_NUM_Y - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_y++;
				}
				break;
			default:
				break;
			}
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].update_flag = true;
			plant_type = ch - '1';
			store.plant_card[plant_type].select_flag = true;
			store.plant_card[plant_type].update_flag = true;
			state = PERCHASING;
			tip_update_flag = true;
			break;
		case 'a':
		case 'A':
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].update_flag = true;
			if (ch >= 'A')
				plant_type = ch - 'A' + 9;
			else
				plant_type = ch - 'a' + 9;
			store.plant_card[plant_type].select_flag = true;
			store.plant_card[plant_type].update_flag = true;
			state = PERCHASING;
			tip_update_flag = true;
			break;
		case 'x':
		case 'X':
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].update_flag = true;
			state = WEEDING;
			tip_update_flag = true;
			break;
		case 27: // Esc键
			garden.swards[num_y][num_x].select_flag = false;
			garden.swards[num_y][num_x].update_flag = true;
			store.plant_card[plant_type].select_flag = false;
			store.plant_card[plant_type].update_flag = true;
			state = RUNNING;
			tip_update_flag = true;
			break;
		case '\r': // Enter键
			if (store.Perchase(plant_type, num_x, num_y, garden)) // 如果购买成功
			{ 
				garden.swards[num_y][num_x].select_flag = false;
				garden.swards[num_y][num_x].update_flag = true;
				store.plant_card[plant_type].select_flag = false;
				store.plant_card[plant_type].update_flag = true;
				state = RUNNING;
				tip_update_flag = true;
			}
			break;

		case ' ': //空格键暂停
			Pausing();
			break;
		default:
			break;
		}
	}
}

void Game::Weeding() // 移除植物
{
	state = WEEDING;
	tip_update_flag = true;
	garden.swards[num_y][num_x].select_flag = true;
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
			case 72://上
				if (num_y > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_y--;
				}
				break;
			case 75://左
				if (num_x > 0)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_x--;
				}
				break;
			case 77://右
				if (num_x < SWARD_NUM_X - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_x++;
				}
				break;
			case 80://下
				if (num_y < SWARD_NUM_Y - 1)
				{
					garden.swards[num_y][num_x].select_flag = false;
					garden.swards[num_y][num_x].update_flag = true;
					num_y++;
				}
				break;
			default:
				break;
			}
			garden.swards[num_y][num_x].select_flag = true;
			garden.swards[num_y][num_x].update_flag = true;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'a':
		case 'A':
			state = PERCHASING;
			tip_update_flag = true;
			break;
		case '\r': // Enter键
			if (garden.swards[num_y][num_x].plant!=NULL)
			{
				garden.swards[num_y][num_x].Delete_Plant();
				garden.swards[num_y][num_x].select_flag = false;
				garden.swards[num_y][num_x].update_flag = true;
				state = RUNNING;
				tip_update_flag = true;
			}
			break;
		case 27: // Esc键
			garden.swards[num_y][num_x].select_flag = false;
			garden.swards[num_y][num_x].update_flag = true;
			state = RUNNING;
			tip_update_flag = true;
			break;
		case ' ': // Space键
			Pausing();
			break;
		default:
			break;
		}
	}
}

void Game::Pausing() // 暂停游戏
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
			if (ch == ' ') //空格结束暂停
			{
				state = state_copy;
				tip_update_flag = true;
				break;
			}
		}
		Sleep(SLEEP_TIME);
	}
}

void Game::Add_Pea(Pea* pea) // 添加豌豆
{
	peas.push_back(pea);
}

void Game::Delete_Pea(Pea* pea)
{
	for (auto i = peas.begin(); i < peas.end(); i++) // 删除豌豆
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
		UI::Print_With_Color(" ##游戏中##  种植：\"1-9\"数字键 \"a\"字母键 | 铲除：\"x\"键 | 暂停：Space键", TIP_COLOR);
		break;
	case PERCHASING:
		UI::Print_With_Color(" ##种植中##  选择：\"1-2\"数字键 \"a\"字母键 | 确认：Enter键 | 取消：Esc键 | 暂停：Space键", TIP_COLOR);
		break;
	case WEEDING:
		UI::Print_With_Color(" ##铲除中##  确认：Enter键 | 取消：Esc键 | 暂停：Space键", TIP_COLOR);
		break;
	case PAUSING:
		UI::Print_With_Color(" ##暂停中##  继续游戏：Space键", TIP_COLOR);
		break;
	}
}

void Game::Create_Zombie() // 生成僵尸
{
	if (timer + 1 == zombie_speed)
	{
		for (int i = 0; i < score / 100; i++)
		{
			int zombie_type = rand() % ZOMBIE_TYPE_MAX;
			Zombie* zombie = NULL;
			switch (zombie_type)
			{
			case 0:
				zombie = new Zombie;
				zombie->Set(garden, "普通僵尸", 100, 25, 20, 10, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
				break;
			case 1:
				zombie = new Coneheadzombie;
				zombie->Set(garden, "路障僵尸", 150, 25, 20, 15, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
				break;
			case 2:
				zombie = new Newspaperzombie;
				zombie->Set(garden, "读报僵尸", 125, 25, 20, 20, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
				break;
			case 3:
				zombie = new Polevaultingzombie;
				zombie->Set(garden, "撑杆僵尸", 125, 25, 20, 20, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
				break;
			case 4:
				zombie = new Jackintheboxzombie;
				zombie->Set(garden, "小丑僵尸", 100, 25, 20, 15, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
				break;
			case 5:
				zombie = new Catapultzombie;
				zombie->Set(garden, "投石僵尸", 250, 20, 20, 40, SWARD_NUM_X, rand() % SWARD_NUM_Y, 50);
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