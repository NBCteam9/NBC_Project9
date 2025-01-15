<!-- Heading -->
# 배틀 몬스터(임시 이름 <- 추후 수정할 것)
C++을 활용해 만든 텍스트 기반 RPG게임입니다!
팀 프로젝트로 팀원 6명이 협업하여 만들었습니다.<br>팀 과제 제출을 위해 주어진 요구사항을 충족시켜 만들었습니다.

## ✔️요구사항
- 캐릭터 생성 및 관리
- 아이템 및 골드 관리
- 캐릭터가 레벨업하면 최대 체력까지 회복
- 몬스터는 경험치와 골드를 일정량 드롭
- 자동 전투 시스템
- 게임 로그 확인

## 🎮프로젝트 개요
### - 개발 기간
25.01.10 ~ 25.01.16
### - 게임 설명
캐릭터가 생성되면 몬스터와 싸워 경험치, 골드를 얻으며 점점 더 강해집니다.

그렇게 강해지고 보스 몬스터와 싸워 이기면 게임의 엔딩을 볼 수 있습니다!
### - 배틀 몬스터란?
1명의 캐릭터가 점점 강해지는 몬스터들로부터 살아남아 최종 보스를 이기면 클리어하는 텍스트 RPG 게임입니다!

게임 화면은 전투 시작, 전투 끝, 상점으로 나뉩니다.


**전투 시작**
- 전투가 시작되면 플레이어가 먼저 몬스터를 공격! -> 몬스터가 플레이어를 공격! 하며 자동으로 진행됩니다.

**전투 끝**
- 죽으면 Game Over, 살아남으면 골드와 경험치를 얻고 계속 진행합니다.
- 전투가 끝나면 현재 캐릭터의 상태를 출력합니다. 인벤토리에 아이템이 있다면 인벤토리 정보까지 출력합니다.
- 각 턴이 끝날 때마다 가지고 있는 골드에 비례해서 이자를 얻습니다. 이자는 최대 10골드까지 쌓입니다.

**상점**
- 전투 후에 살아남았다면 상점으로 이동(Y, N) -> N을 누르면 전투 시작 화면으로, Y를 누르면 상점 화면으로 갑니다.
- 상점에서는 골드로 아이템을 사거나 가지고 있는 아이템을 팔 수 있습니다.
- 상점에서 떠나면 전투 시작 화면으로 넘어갑니다.

## 🏆프로젝트 목표
- **SOLID 원칙을 최대한 지킨 코드 만들기**<br>
확장성과 유지보수를 생각한 코드 제작을 해야 게임을 만드는 개발자가 편합니다.

- **다양한 테스트 케이스로 버그 최소화**<br>
최대한 많은 경우의 버그를 잡아서 플레이하는 사용자가 버그를 발견하지 않아야 좋은 게임입니다.

- **게임 직접 플레이하며 난이도&밸런스 조절**<br>
게임이 재미있으려면 플레이어의 판단과 실력에 따라 게임에서 어디까지 갈지 정해져야 합니다.

- **가독성을 위해 텍스트 출력부를 깔끔하게 만들기**<br>
플레이 하는 사람이 편해야 더 재밌기 때문에 사용자 경험까지 고려해야 합니다.

## 📌주요 기능
- [보유 골드에 따른 이자 시스템](#보유-골드에-따른-이자-시스템)
- [몬스터 처치 시 확률 아이템 보상](#몬스터-처치-시-확률-아이템-보상)
- [레벨업 시 체력 회복](#레벨업-시-체력-회복)
- [상점에서 아이템 구매 및 판매](#상점에서-아이템-구매-및-판매)
- [전투는 모두 자동](#전투는-모두-자동)
- [아이템도 자동 사용](#아이템도-자동-사용)
- [골든 고블린 처치 시 엄청난 골드](#골든-고블린-처치-시-엄청난-골드)

## 🧾프로젝트 구조
```
NBC_Project9
 ┃ ┣ AttackBoost.cpp          // 공격력 증가 물약 아이템
 ┃ ┣ AttackBoost.h
 ┃ ┣ Character.cpp            // 주인공 캐릭터
 ┃ ┣ Character.h
 ┃ ┣ GameManager.cpp          // 게임 진행 시스템
 ┃ ┣ GameManager.h
 ┃ ┣ HealthPotion.cpp         // 체력 회복 물약 아이템
 ┃ ┣ HealthPotion.h
 ┃ ┣ Item.cpp                 // 아이템 클래스 선언
 ┃ ┣ Item.h
 ┃ ┣ MaxHPBoost.cpp           // 최대 체력 증가 물약 아이템
 ┃ ┣ MaxHPBoost.h
 ┃ ┣ Monster.cpp              // 몬스터 클래스 선언
 ┃ ┣ Monster.h
 ┃ ┣ MonsterFactory.cpp       // 몬스터 생성 시스템
 ┃ ┣ MonsterFactory.h
 ┃ ┣ Slime.cpp                // 몬스터 : 슬라임
 ┃ ┣ Slime.h
 ┃ ┣ Wolf.cpp                 // 몬스터 : 늑대
 ┃ ┣ Wolf.h
 ┃ ┣ Goblin.cpp               // 몬스터 : 고블린
 ┃ ┣ Goblin.h
 ┃ ┣ GoldenGoblin.cpp         // 몬스터 : 황금 고블린
 ┃ ┣ GoldenGoblin.h
 ┃ ┣ Skeleton.cpp             // 몬스터 : 스켈레톤
 ┃ ┣ Skeleton.h
 ┃ ┣ Orc.cpp                  // 몬스터 : 오크
 ┃ ┣ Orc.h
 ┃ ┣ Zombie.cpp               // 몬스터 : 좀비
 ┃ ┣ Zombie.h
 ┃ ┣ Troll.cpp                // 몬스터 : 트롤
 ┃ ┣ Troll.h
 ┃ ┣ Dragon.cpp               // 몬스터 : 드래곤
 ┃ ┣ Dragon.h
 ┃ ┣ NBC_Project9.cpp         // 프로그램 진입 파일
 ┃ ┣ NBC_Project9.vcxproj
 ┃ ┣ NBC_Project9.vcxproj.filters
 ┃ ┣ NBC_Project9.vcxproj.user
 ┃ ┣ Shop.cpp                 // 상점 시스템
 ┃ ┗ Shop.h
 ┗ 
```

## ⚙개발 환경
- **프로그래밍 언어** - ISO C++14 표준(/std:c++14)
- **개발 환경(IDE)** - Visual Studio 2022 (v143)
- **컴파일러(compilor)** - Microsoft Visual C++ (MSVC) 19.38.33143
- **아키텍처(Architecture)** - x86 (32-bit)
- **협업 도구** - GitHub, Notion

## 📢아직 수정되지 않은 버그/문제점
-
-

# 필수 기능 소개
## 몬스터 처치 시 확률 아이템 보상
## 레벨업 시 체력 회복
몬스터를 처치할 때 확률적으로 아이템을 보상으로 제공합니다.

![몬스터 처치 보상 예시1](https://github.com/user-attachments/assets/d2957f9e-b880-43dd-a008-14538bc6a930)

만약 몬스터가 아이템을 드롭했다면 전투 후 캐릭터 상태 창 밑에 드롭된 아이템을 보여줍니다!
레벨업 시 최대 체력까지 회복되는 것도 확인할 수 있습니다!

[돌아가기](#주요-기능)

## 상점에서 아이템 구매 및 판매
플레이어는 상점에서 아이템을 구매하거나 판매할 수 있습니다.

![아이템 구매 및 판매 예시1](https://github.com/user-attachments/assets/63f337a9-8019-4b30-9110-748fdc215df1)

[돌아가기](#주요-기능)

## 전투는 모두 자동
플레이어가 전투 중 획득한 아이템을 자동으로 사용하도록 설정합니다.<br>
플레이어는 전투가 시작되면 전투 도중의 선택지 없이 끝날 때까지 기다려야 합니다.

![자동 전투 예시 gif](https://github.com/user-attachments/assets/5fc1c9e9-b90e-4b62-bd9c-3cb40735043b)

[돌아가기](#주요-기능)

## 아이템도 자동 사용
적절한 예시를 위해 보스전 전투를 들고 왔습니다.

![아이템 자동 사용 예시 gif](https://github.com/user-attachments/assets/ebfa10c6-4459-4ddd-be56-cebb80454d6c)

이렇게 Health Potion이 자동으로 사용되는 것을 볼 수 있습니다!

[돌아가기](#주요-기능)

# 추가 기능 소개
## 보유 골드에 따른 이자 시스템
이 기능은 플레이어가 가진 골드에 따라 매 라운드 이자를 지급하는 시스템입니다.

![이자 시스템 예시1](https://github.com/user-attachments/assets/7bfc169c-0781-4316-9310-50341a78cdd6)

위 사진에서 Wolf는 4~8골드를 드롭하는데 이자가 보유 골드 10원당 1씩 붙기 때문에<br>
원래보다 10골드 더 많이 받게되었습니다!

[돌아가기](#주요-기능)

## 골든 고블린 처치 시 엄청난 골드
게임의 재미를 위해 낮은 확률로 나오는 골든 고블린을 처치하면 많은 골드가 나오도록 했습니다!

![골든 고블린 예시1](https://github.com/user-attachments/assets/49d2a930-4be7-4c1c-8657-23094acb62dd)

[돌아가기](#주요-기능)
