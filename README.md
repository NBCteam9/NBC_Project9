<!-- README 작성 전 알면 좋은 것들 -->
<!-- <br>을 사용하면 줄바꿈이 됩니다! -->
<!-- 이미지나 gif를 드롭다운으로 끌어와도 상관 없습니다. 깃허브의 저장소에 저장됩니다! -->
<!-- #,##,### 같은거 앞에 이모지 붙이면 가독성이 올라갑니다! -->
# 스파르타 용사로 환생했으니 공주를 구해조!! <br>아니아니 절대 무리인게 당연하잖아!? (※무리가 아니였다?!)
C++을 활용해 만든 텍스트 기반 RPG게임입니다!
팀 프로젝트로 팀원 6명이 협업하여 만들었습니다.<br>팀 과제 제출을 위해 주어진 요구사항을 충족시켜 만들었습니다.

## ✔️요구사항(모두 완료)
- 캐릭터 생성 및 관리✔️
- 자동 전투 시스템✔️
- 아이템 및 골드 관리✔️
- 캐릭터가 레벨업하면 최대 체력까지 회복✔️
- 몬스터는 경험치와 골드를 일정량 드롭✔️
- 몬스터 설명✔️
- 게임 로그 확인✔️
- 몬스터 보스전✔️
- 상점 시스템✔️

## 🎮프로젝트 개요
### - 개발 기간
25.01.10 ~ 25.01.16
### - 게임 설명
캐릭터가 생성되면 몬스터와 싸워 경험치, 골드를 얻으며 점점 더 강해집니다.

그렇게 강해지고 보스 몬스터와 싸워 이기면 게임의 엔딩을 볼 수 있습니다!
### - 스파르타 용사로 환생했으니 공주를 구해조!! 아니아니 절대 무리인게 당연하잖아!?란?
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

## 📌필수 및 도전 기능
- [캐릭터 생성](#캐릭터-생성)
- [몬스터 처치 시 확률 아이템 보상](#몬스터-처치-시-확률-아이템-보상)
- [레벨업 시 체력 회복](#레벨업-시-체력-회복)
- [전투 시스템](#전투-시스템)
- [몬스터 설명](#몬스터-설명)
- [전투는 모두 자동](#전투는-모두-자동)
- [아이템도 자동 사용](#아이템도-자동-사용)
- [상점에서 아이템 구매 및 판매](#상점에서-아이템-구매-및-판매)
## 📌추가 기능
- [보유 골드에 따른 이자 시스템](#보유-골드에-따른-이자-시스템)
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

## C++ 클래스 다이어그램
![C++ 클래스 다이어그램 이미지](https://github.com/user-attachments/assets/14fc36bb-19b4-47b5-ae37-2291e8bc6a7d)

## 클래스 설명 및 핵심 로직
### 박선우님 - (본인이 구현한 클래스들, , )
(여기다가 본인이 구현한 클래스나 핵심 로직의 설명하고 싶은 부분을 적어주세요!)<br>
(다형성 / 디자인 패턴(SOLID 원칙 포함) / 상속 / STL에 관련 내용을 작성해주세요!)

### 이재성님 - (본인이 구현한 클래스들, , )
(여기다가 본인이 구현한 클래스나 핵심 로직의 설명하고 싶은 부분을 적어주세요!)<br>
(다형성 / 디자인 패턴(SOLID 원칙 포함) / 상속 / STL에 관련 내용을 작성해주세요!)

### 안가현님 - (본인이 구현한 클래스들, , )
(여기다가 본인이 구현한 클래스나 핵심 로직의 설명하고 싶은 부분을 적어주세요!)<br>
(다형성 / 디자인 패턴(SOLID 원칙 포함) / 상속 / STL에 관련 내용을 작성해주세요!)

### 박영민님 - (본인이 구현한 클래스들, , )
(여기다가 본인이 구현한 클래스나 핵심 로직의 설명하고 싶은 부분을 적어주세요!)<br>
(다형성 / 디자인 패턴(SOLID 원칙 포함) / 상속 / STL에 관련 내용을 작성해주세요!)

### 최무현님 - (GameManager, MonsterFactory, Shop)

GameManager :
 - 전투와 관련된 로직을 처리하는 클래스, 전투 그 자체 외에도 전투 승리 시 이자를 포함한 골드, 아이템, 경험치 획득, 이번 게임에서 처치한 몬스터의 종류와 수 저장 및 출력 기능이 있다.
 - onordered_map을 이용해 처치한 몬스터의 종류와 수를 저장한다. (STL: onordered_map)

MonsterFactory :
 - 몬스터를 저장하고 필요한 몬스터를 반환하는 클래스, 원래 GameManager에 있던 몬스터 생성 함수를 따로 클래스로 뺐다. (팩토리 패턴, 단일책임원칙)
 - 처음에는 첫번째 이미지처럼 스위치를 이용해 인스턴스를 생성해 리턴하는 방식이였는데, 이 경우 몬스터가 새로 추가될 때마다 클래스를 수정해야하기 때문에 개방폐쇄원칙을 위반한다.
 - 
   실제로 몬스터를 스위치문에 추가하고 랜던값 % 뒤의 숫자를 수정하지 않아 새로 추가한 몬스터가 생성되지 않는 문제가 있었다.
   
   이 문제를 해결하기 위해 두번째 이미지 처럼 수정했다. AddMonster()를 이용해 main함수에서 몬스터를 추가하면 MonsterFactory 클래스를 수정하지 않고 몬스터가 추가할 수 있다.
   
   또, 반환할 때는 새로운 인스턴스를 생성하는 것이 아니라 기존에 있던 인스턴스를 초기화해서 반환해서 미미하지만 메모리적으로도 이점이 있다. (개방폐쇄원칙)

초기코드 :

![badCode](https://github.com/user-attachments/assets/a043b1fa-b8a9-48f8-a808-8969fd83a001)

수정한 코드 :

![goodCode](https://github.com/user-attachments/assets/82feccd1-89ab-4bb4-9c46-bf0e57d39d8e) 

 - 게임에 하나만 존재하고 몬스터를 생성하고 추가하는 등 여러 클래스에서 접근할 필요가 있기에 싱글톤 적용했다. (싱글톤 패턴)

Shop :
 - 상점과 관련된 로직을 처리하는 클래스, 원래 GameManager에 있던 visitShop()을 Shop 클래스로 옮기고 main 함수에서 접근하도록 고쳤다. (단일책임원칙)
 - 상점에 없는 아이템을 사려하거나, 인벤토리에 없는 아이템을 팔려고 할 때 등 예외처리에 신경을 많이 썼다.

### 선우민석님 - (본인이 구현한 클래스들, , )
(여기다가 본인이 구현한 클래스나 핵심 로직의 설명하고 싶은 부분을 적어주세요!)<br>
(다형성 / 디자인 패턴(SOLID 원칙 포함) / 상속 / STL에 관련 내용을 작성해주세요!)

## ⚙개발 환경
- **프로그래밍 언어** - ISO C++14 표준(/std:c++14)
- **개발 환경(IDE)** - Visual Studio 2022 (v143)
- **컴파일러(compilor)** - Microsoft Visual C++ (MSVC) 19.38.33143
- **아키텍처(Architecture)** - x86 (32-bit)
- **협업 도구** - GitHub, Notion

## 📢아직 수정되지 않은 버그/문제점
- 상점으로 이동 여부를 입력받을 때 사용자가 y, n이 아닌 다른 문자열이나 숫자, 특수 기호를 입력하면 바로 게임이 진행됩니다.

## 📢주의할 점!!
- Golden Goblin(황금 고블린)을 잡아도 보상이 1~110 Gold라서 운이 안 좋으면 적은 보상을 받을 수 있습니다!

# 필수 및 도전 기능 소개
## 캐릭터 생성
![캐릭터 생성 예시](https://github.com/user-attachments/assets/c632cd0f-4f39-408c-8a09-f968fa3cb5ac)

위 이미지처럼 캐릭터 이름에 공백을 포함할 시 다시 사용자에게 입력을 받습니다!

[돌아가기](#필수-및-도전-기능)

## 전투 시스템
- 랜덤으로 출몰하는 몬스터와 턴제로 싸웁니다.
### 전투 시작 조건
- 캐릭터 생성 직후

![캐릭터 생성 직후 전투](https://github.com/user-attachments/assets/854a3efe-059e-4b2d-9053-3f895e7f52e3)
- 전투 승리 직후 상점을 스킵하거나 이용한 후 상점을 떠나면 바로 전투
  
![전투 승리 후 상점 이용 끝나고 바로 전투](https://github.com/user-attachments/assets/32bf81d2-572a-4733-8d74-92bf0ed86e4f)
- 전투 승리: 경험치 50 획득 & 랜덤한 골드 획득
- 경험치 누적 100 이상 → 자동 레벨업

[돌아가기](#필수-및-도전-기능)

### 몬스터 설명
- 몬스터도 이름, 체력, 공격력을 가집니다.
- 몬스터 스펙은 캐릭터 레벨에 비례해서 랜덤하게 생성됩니다.
- 몬스터는 고정 경험치 50과 몬스터 종류에 따라 랜덤 골드를 드랍합니다.

[돌아가기](#필수-및-도전-기능)

### 전투는 모두 자동
플레이어는 전투가 시작되면 전투 도중의 선택지 없이 끝날 때까지 기다려야 합니다.

![자동 전투 예시 gif](https://github.com/user-attachments/assets/5fc1c9e9-b90e-4b62-bd9c-3cb40735043b)

[돌아가기](#필수-및-도전-기능)

### 아이템도 자동 사용
플레이어가 전투 중 획득한 아이템을 자동으로 사용하도록 설정합니다.<br>
아이템은 사용 순간 사라지고, 효과는 바로 캐릭터에게 반영되는 소비 아이템입니다.<br>
적절한 예시를 위해 보스전 전투를 들고 왔습니다.

![아이템 자동 사용 예시 gif](https://github.com/user-attachments/assets/ebfa10c6-4459-4ddd-be56-cebb80454d6c)

이렇게 Health Potion이 자동으로 사용되는 것을 볼 수 있습니다!

[돌아가기](#필수-및-도전-기능)

## 몬스터 처치 시 확률 아이템 보상
## 레벨업 시 체력 회복
몬스터를 처치할 때 확률적으로 아이템을 보상으로 제공합니다.

![몬스터 처치 보상 예시](https://github.com/user-attachments/assets/d2957f9e-b880-43dd-a008-14538bc6a930)

만약 몬스터가 아이템을 드롭했다면 전투 후 캐릭터 상태 창 밑에 드롭된 아이템을 보여줍니다!<br>
이 때 드랍되는 아이템은 최대 1개입니다.<br>
레벨업 시 최대 체력까지 회복되는 것도 확인할 수 있습니다!

## 게임 로그 확인
게임 내 중요한 이벤트(전투, 아이템 사용, 골드&경험치 획득)은 콘솔에 기록되어야 합니다.<br>
로그를 통해 어떤 몬스터를 몇 마리 눕혔는지~ 한 눈에 확인 가능합니다.

[돌아가기](#필수-및-도전-기능)

## 게임 화면
전투 화면과 주인공 사망 시 게임 종료 화면의 예시입니다!
### 전투 화면
(이미지 추가 할 곳)
### 게임 오버..
![게임 오버 화면](https://github.com/user-attachments/assets/eaa5f44a-0d75-49fe-9ca7-983c25a04ef4)

[돌아가기](#필수-및-도전-기능)

## 몬스터 보스전
- **레벨 10 달성** 시, 이제 일반 몬스터의 난이도가 너무 쉬워집니다.
- 10렙 달성후 상점을 빠져나오면 **보스 몬스터**가 짜잔~ 등장합니다.
- 체력·공격력은 기존 몬스터 레벨의 **1.5배** 범위를 랜덤으로 설정했습니다. 10Lv의 능력치라면 15Lv의 능력치로!
- 보스 클리어하면 엔딩 메시지가 출력됩니다!

  ![보스전 전투](https://github.com/user-attachments/assets/16197f60-ec4c-407b-941f-4744342c8f02)

  ![승리 후 엔딩 메시지](https://github.com/user-attachments/assets/faff6460-255b-481d-9ed6-d9e24a61617b)

## 상점에서 아이템 구매 및 판매
플레이어는 상점에서 아이템을 구매하거나 판매할 수 있습니다.

![아이템 구매 및 판매 예시](https://github.com/user-attachments/assets/63f337a9-8019-4b30-9110-748fdc215df1)

- 아이템 구매
    - 플레이어는 골드를 사용해서 아이템을 구매 가능
    - 구매 아이템은 인벤토리에 즉시 추가
- 아이템 판매
    - 플레이어는 보유한 아이템을 골드로 판매 가능 **(판매 가격은 구입 원가의 60%!)**
    - 판매된 아이템은 인벤토리에서 즉시 제거
- “체력 물약 10 Gold”, “공격력 강화 15 Gold”처럼 가격을 정해놓았습니다.
- 구매 즉시 인벤토리에 들어오며, 판매 시 아이템이 소멸되고 골드 획득!

[돌아가기](#필수-및-도전-기능)

# 추가 기능 소개
## 보유 골드에 따른 이자 시스템
이 기능은 플레이어가 가진 골드에 따라 매 라운드 이자를 지급하는 시스템입니다.

![이자 시스템 예시](https://github.com/user-attachments/assets/7bfc169c-0781-4316-9310-50341a78cdd6)

위 사진에서 Wolf는 4~8골드를 드롭하는데 이자가 보유 골드 10원당 1씩 붙기 때문에<br>
원래보다 10골드 더 많이 받게 되었습니다!

[돌아가기](#추가-기능)

## 골든 고블린 처치 시 엄청난 골드
게임의 재미를 위해 낮은 확률로 나오는 골든 고블린을 처치하면 많은 골드가 나오도록 했습니다!

![골든 고블린 예시](https://github.com/user-attachments/assets/49d2a930-4be7-4c1c-8657-23094acb62dd)

[돌아가기](#추가-기능)

# 👀테스트 케이스(혹시나 테스트 더 필요해보이면 적어주세요!)
| 테스트 제목             | 테스트 절차                                                                 | 케이스 분류      | 
|-------------------------|----------------------------------------------------------------------------|------------------|
| 캐릭터 생성 테스트       | 1. 게임 시작 시 캐릭터 이름 입력<br>2. 해당 이름으로 캐릭터가 생성되는지 확인    | 정상(Normal)     | 
| 캐릭터 이름 공백 입력    | 1. 캐릭터 이름을 공백으로 입력<br>2. 에러 메시지 출력 & 재입력 요구             | 비정상(Abnormal) | 
| 초기 상태 확인 테스트    | 1. 캐릭터 생성 후 초기(레벨1, 체력200, 공격력30) 점검                          | 정상(Normal)     | 
| 전투 시스템 테스트       | 1. 랜덤 몬스터와 전투<br>2. 공격/피격 로직과 HP 감소를 확인                    | 정상(Normal)     | 
| 전투 승리 보상 테스트    | 1. 전투 승리 후 50경험치 & 일정한 가중치의 랜덤 골드 획득                       | 정상(Normal)     | 
| 전투 패배 종료 테스트    | 1. 플레이어 체력 0 → 게임 오버 메시지 출력 & 종료                              | 정상(Normal)     | 
| 레벨업 테스트           | 1. 경험치 100 이상 획득 시 레벨 +1<br>2. 체력/공격력 증가 정상 반영             | 정상(Normal)     | 
| 보스전 테스트           | 1. 레벨 10 도달<br>2. 보스 몬스터 자동 소환 → 승리 시 게임 클리어               | 정상(Normal)     | 

