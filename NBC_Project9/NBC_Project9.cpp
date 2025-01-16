#include <iostream>
#include <string>
#include "GameManager.h"
#include "MonsterFactory.h"
#include "Shop.h"
#include "Character.h"
#include "Slime.h"
#include "Wolf.h"
#include "Goblin.h"
#include "GoldenGoblin.h"
#include "Skeleton.h"
#include "Orc.h"
#include "Zombie.h"
#include "Troll.h"
#include "Dragon.h"
#include "Monster.h"
#include "StoryPrinter.h"

using namespace std;

int main()
{
    GameManager gameManager;

    MonsterFactory::GetInstance()->AddMonster(new Goblin(1));
    MonsterFactory::GetInstance()->AddMonster(new Orc(1));
    MonsterFactory::GetInstance()->AddMonster(new Skeleton(1));
    MonsterFactory::GetInstance()->AddMonster(new Slime(1));
    MonsterFactory::GetInstance()->AddMonster(new Troll(1));
    MonsterFactory::GetInstance()->AddMonster(new Wolf(1));
    MonsterFactory::GetInstance()->AddMonster(new Zombie(1));
    MonsterFactory::GetInstance()->AddMonster(new GoldenGoblin(1));

    MonsterFactory::GetInstance()->AddBossMonster(new Dragon(1));

    Shop shop;

    cout << "Welcome to Game!" << endl;
    cout << "Create your character." << endl;
    string name;
    cin.clear();
    StoryPrinter storyPrinter;

   
    while (1)
    {
        getline(cin, name);

        if (name.find(' ') != string::npos)
        {
            cout << "Your name contains space. Please try again" << endl;
        }
        else
        {
            cout << "Your name : " << name << endl;
            break;
        }
    }
    Character* warrior = Character::GetInstance(name);
    string DefeatChoice;
    storyPrinter.PrintIntro(warrior);
    while (true)
    {
        // 배틀 로직
        while (true)
        {
            if (warrior->GetLevel() >= 10)
            {
                if (gameManager.Battle(warrior) == false) // 패배
                {
                    storyPrinter.PrintLose();
                    
                    while (1)
                    {
                        cin >> DefeatChoice;
                        if (DefeatChoice == "Y" || DefeatChoice == "y") // Retry
                        {
                            cout << endl;
                            cout << "당신은 의지가 충만해진다." << endl;
                            cout << "\n====================\n" << endl;
                            Sleep(1000);
                            warrior->InitCharacter(); // 캐릭터 초기화
                            gameManager.Initialize();
                            break; // 내부 while 루프를 종료하고 외부 while 루프로 돌아감
                        }
                        else if (DefeatChoice == "N" || DefeatChoice == "n")
                        {
                            Character::DestroyInstance();
                            MonsterFactory::DestoryInstance();
                            return 0;
                        }
                        else
                        {
                            cout << "잘못된 입력입니다. 다시 입력하세요 (Y/N): ";
                        }
                    }
                }
                else
                {
                    storyPrinter.PrintVictory(warrior);
                    gameManager.DisplayKilledMonsters();
                    Character::DestroyInstance();
                    MonsterFactory::DestoryInstance();
                    return 0;
                }
            }
            else // 레벨 10 미만
            {
                if (gameManager.Battle(warrior) == false) // 패배
                {
                    storyPrinter.PrintLose();
                    
                    while (1)
                    {
                        cin >> DefeatChoice;
                        if (DefeatChoice == "Y" || DefeatChoice == "y") // Retry
                        {
                            cout << endl;
                            cout << "당신은 의지가 충만해진다." << endl;
                            cout << "\n====================\n" << endl;
                            Sleep(1000);
                            warrior->InitCharacter(); // 캐릭터 초기화
                            gameManager.Initialize();
                            break; // 내부 while 루프를 종료하고 외부 while 루프로 돌아감
                        }
                        else if (DefeatChoice == "N" || DefeatChoice == "n")
                        {
                            Character::DestroyInstance();
                            MonsterFactory::DestoryInstance();
                            return 0;
                        }
                        else
                        {
                            cout << "잘못된 입력입니다. 다시 입력하세요 (Y/N): ";
                        }
                    }
                }
                else
                {
                    break; // 배틀 성공 시 내부 루프 종료
                }
            }
        }

        // 상점 방문
        cout << "\n====================\n" << endl;
        cout << "Do you want to go shop?? (Y/N): ";
        while (1)
        {
            string choice;
            cin >> choice;
            if (choice == "Y" || choice == "y")
            {
                shop.VisitShop(warrior);
                break;
            }
            else if (choice == "N" || choice == "n")
            {
                break;
            }
            else
            {
                cout << "Please re-enter (Y/N): ";
            }
        }
        cout << "\n====================\n" << endl;
    }

    Character::DestroyInstance();
    MonsterFactory::DestoryInstance();

    return 0;
}
