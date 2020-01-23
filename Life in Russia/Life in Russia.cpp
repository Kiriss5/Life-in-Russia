#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#define _WIN32_WINDOWS 0x0501
#define _WIN32_IE 0x0600
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int day = 1;
class Putin {
private:
	int nalog;
public:
	int hp;
	Putin() {
		hp = 5000, nalog = 0;
	}
	~Putin() {
		cout << "bye bye " << hp << endl;
	}
	void status() {
		/*cout << "Squirrel::hp = " << hp << endl;
		cout << "Squirrel::wood" << " = " << wood << endl;
		cout << "_________________" << endl;
		*/
	}
	void steal_wood();
	bool is_alive() {
		return hp > 0;
	}
	void do_damage(int damage);
	void live_one_minute() {
		if (is_alive()) {
			status();
			if (rand() % 3 == 0) {
				steal_wood();
			}
		}
	}

};


class Lesorub {
private:
	int hp, money = 0, dayl = 0, a=0;
	void sleep() {
		dayl++;
		hp = hp + (rand() % 30 + 20);
		if (hp > 100)
			hp = 100;
		cout << "sleep(спит)" << endl;
	}
	void work() {
		if (a == 0) {
			cout << "go to work(идёшь пахать)\n\n";
			hp = hp - (rand() % 20 + 10);
			cash = cash + (rand() % 1500 + 1000);
		}
		else
			cout << "you don't have a job(ты бомж)\n\n";
	}
	void find_job() {
		if (rand() % 3) {
			a = 0;
			dayl = 0;
			cout << "Ты смог найти новую работу\n\n";
		}
		else
			cout << "Попробуй еще\n\n";
	}
	void money1() {
		dayl++;
		money = money + cash;
		cash = 0;
	}
	void pay() {
		if (money > 3000) {
			money = money - 3000;
		}
		else {
			cout << "У тебя теперь нет жилья\n\n";
			hp = 0;
		}
	}
	void miting() {
		if (rand() % 50 == 0) {
			cout << "Даааа!!!\n Нэвальный смог придти к власти и теперь не о чём заботиться\n";
			system("pause");
			exit(0);
		}
		else {
			cout << "Тебя побила Росгвардия\n\n";
			hp = hp - 10;
			dayl++;
		}
	}
	void hpcolor() {
		HANDLE hpColor = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hp <= 50) {
			SetConsoleTextAttribute(hpColor, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << ". hp = " << hp << endl;
		}
		if (hp <= 20) {
			SetConsoleTextAttribute(hpColor, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << ". hp = " << hp << endl;
		}
		if (hp <= 100 and hp >= 51) {
			SetConsoleTextAttribute(hpColor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << ". hp = " << hp << endl;
		}
		SetConsoleTextAttribute(hpColor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
public:
	int cash = 0;
	string answer;
	Lesorub() {
		setlocale(LC_CTYPE, "rus");
		cout << "ИНФОРМАЦИЯ:\n 1. 7 пропусков и ты уволены\n 2. Каждый понедельник у тебя со счёта списывают 3000 руб. квартплаты\n(первые 2 недели тебе её прощают)\n 3. Банк работает только в воскресенье \n 4. Команды:\n	sleep-спать,\n	work-работать,\n	money-положить деньги на счёт,\n	find-найти работу,\n	miting-сходить на митинг)\n И да кстати ты должен платить НАЛОГИ!!!!\n" << endl;
		hp = 100;
	}
	~Lesorub() {
		cout << "пока" << endl;
	}
	void wood_stolen(Putin& who) {
		cout << "Oh shit here go again(опять налоги?)\n\n";
		//who.hp=who.hp - (rand()%30+10);
		who.do_damage((rand() % 30 + 10));
	}
	void status() {
		cout << "_________________\n";
		switch (day % 7) {
		case 1:
			cout << "Понедельник\n";
			break;
		case 2:
			cout << "Вторник\n";
			break;
		case 3:
			cout << "Среда\n";
			break;
		case 4:
			cout << "Четверг\n";
			break;
		case 5:
			cout << "Пятница\n";
			break;
		case 6:
			cout << "Суббота\n";
			break;
		case 0:
			cout << "Воскресенье\n";
			break;
		default:
			break;
		}
		cout << "\n";
		cout << "day " << day;
		hpcolor();
		cout << "cash" << " = " << cash << endl;
		cout << "money" << " = " << money << endl;
		cout << "пропуски = " << dayl << endl;
		cout << "_________________\n";
	}
	bool is_alive() {
		return hp > 0;
	}
	void do_damage(int damage) {
		hp = hp - damage;
		if (hp <= 0) {
			cout << "Пуууууутен!!!" << endl;
			system("pause");
			exit(0);
		}
	}
	void clear() {
		cout << "Загрузка";
		Sleep(500);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(200);
		cout << ".\n";
		Sleep(2000);
		system("cls");
	}
	void secret(){
		clear();
		cout << "                             *******\n"
       "***     ***     ***   ***\n"
       " ***   ***       *** ***    ***   ***\n"
       "    *****         ****      ***   ***\n"
       "   *****          ***       ***  ****\n"
       "  ***   ***      ***        ***** ***\n"
       " ***     ***    ***         ***   ***\n\n";
	}
	void live_one_day() {
		if (is_alive()) {
			status();
			cout << "Чем сегодня займёмся?\n";
			cin >> answer;
			cout << "\n";
			if (answer == "sleep") {
				sleep();
			}
			if (dayl > 6) {
				a = 1;
			}
			if (answer == "secret") {
				secret();
				day = day - 1;
			}
			if (answer == "find" and a == 1) {
				find_job();
			}
			else if (answer == "find" and a != 1) {
				cout << "У тебя уже есть работа\n\n";
				day = day - 1;
			}
			if (answer == "work") {
				work();
			}
			if (answer == "money" and day % 7 == 0) {
				money1();
			}
			else if (answer == "money" and day % 7 != 0) {
				cout << "Банк сейчас закрыт.\n(работает только в воскресенье)\n\n";
			}
			if (answer == "miting") {
				miting();
			}
			if (day % 7 == 1 and day > 14) {
				pay();
			}
			if (answer != "money" and answer != "work" and answer != "sleep" and answer != "find" and answer != "secret" and answer != "miting"){
				cout << "error answer(Не понял щас)\n\n";
				day = day - 1;
			}
		}
	}
};
Lesorub vasya;

void Putin::steal_wood() {
	if (vasya.is_alive() and vasya.cash > 360) {
		vasya.cash = vasya.cash - 360;
		nalog = nalog + 360;
		vasya.wood_stolen(*this);
		//cout << "Good loot" << endl;
	}
}
void Putin::do_damage(int damage) {
	hp = hp - damage;
	if (rand() % 3 == 0) {
		vasya.do_damage(rand() % 30 == 10);
	}
	if (hp <= 0) {
		cout << "Вот весь лут: " << nalog << endl;
	}
}

Putin iris;
int main()
{
	srand(time(NULL));
	system("color 0A");
	setlocale(LC_CTYPE, "rus");
	while (day < 365) {
		vasya.live_one_day();
		//iris.live_one_minute();
		day++;
		vasya.clear();
	}
	cout << "Ты умер(\n";
	system("pause");
	return 0;
}