<!-- Heading -->
# 배틀 몬스터(임시 이름 <- 추후 수정할 것)
C++을 활용해 만든 텍스트 기반 RPG게임입니다!
팀 프로젝트로 팀원 6명이 협업하여 만들었습니다.<br>팀 과제 제출을 위해 주어진 요구사항을 충족시켜 만들었습니다!

## ✔️ 요구사항
- 캐릭터 생성 및 관리
- 아이템 및 골드 관리
- 캐릭터가 레벨업하면 최대 체력까지 회복
- 몬스터는 경험치와 골드를 일정량 드롭
- 자동 전투 시스템
- 게임 로그 확인

## 🎮 프로젝트 개요
### 개발 기간
25.01.10 ~ 25.01.16
### 게임 설명
캐릭터가 생성되면 몬스터와 싸워 경험치, 골드를 얻으며 점점 더 강해집니다.<br>
그렇게 강해지고 보스 몬스터와 싸워 이기면 게임의 엔딩을 볼 수 있습니다!
### 배틀 몬스터란?
1명의 캐릭터가 점점 강해지는 몬스터들로부터 살아남아 최종 보스를 이기면 클리어하는 텍스트 RPG 게임입니다!

게임 화면은 전투 시작, 전투 끝, 상점으로 나뉩니다.

**전투 시작**은 전투가 시작되면 플레이어가 먼저 몬스터를 공격! -> 몬스터가 플레이어를 공격! 하며 자동으로 진행됩니다.

**전투 끝**에서 죽으면 Game Over! 살아남으면 골드와 경험치를 얻고 계속 진행!<br>
그렇게 게임이 진행되면 현재 캐릭터의 상태를 출력합니다. 얻은 아이템이 있다면 그 아이템의 정보까지 출력합니다!

**상점**은 전투 후에 살아남았다면 (Y, N) <- 여기서 n을 누르면 전투 시작 화면으로, y를 누르면 상점 화면으로 갑니다!<br>
상점에서는 골드로 아이템을 사거나 가지고 있는 아이템을 팔 수 있습니다.<br>
상점에서 떠나면 전투 시작 화면으로 넘어갑니다!

## 🏆프로젝트 목표
- **SOLID 원칙을 최대한 지킨 코드 만들기**<br>
확장성과 유지보수를 생각한 코드 제작.

- **다양한 테스트 케이스로 버그 최소화**<br>
최대한 많은 경우의 버그를 잡아내야 함.

- **게임 직접 플레이하며 난이도&밸런스 조절**<br>
게임이 재미있으려면 플레이어의 판단과 실력에 따라 게임에서 어디까지 갈지 정해져야 함.

- **가독성을 위해 텍스트라도 출력부를 깔끔하게 만들기**<br>
플레이 하는 사람이 편해야 더 재밌기 때문에 사용자 경험까지 고려해야 함.

## 📌주요 기능
- [보유 골드에 따른 이자 시스템](#보유-골드에-따른-이자-시스템)
- [몬스터 킬시 확률 아이템 보상](#몬스터-킬시-확률-아이템-보상)
- [상점에서 아이템 구매 및 판매](#상점에서-아이템-구매-및-판매)
- [게임의 시작부터 끝까지의 화면 출력](#게임의-시작부터-끝까지의-화면-출력)
- [전투는 모두 자동](#전투는-모두-자동)

## ⚙ 개발 환경
- **프로그래밍 언어** - ISO C++14 표준(/std:c++14)
- **개발 환경(IDE)** - Visual Studio 2022 (v143)
- **컴파일러(compilor)** - Microsoft Visual C++ (MSVC) 19.38.33143
- **아키텍처(Architecture)** - x86 (32-bit)
- **협업 도구** - GitHub, Notion

# 기능 소개

## 보유 골드에 따른 이자 시스템
이 기능은 플레이어가 가진 골드에 따라 매 라운드 이자를 지급하는 시스템입니다.
## 몬스터 킬시 확률 아이템 보상
몬스터를 처치할 때 확률적으로 아이템을 보상으로 제공합니다.
## 상점에서 아이템 구매 및 판매
플레이어는 상점에서 아이템을 구매하거나 판매할 수 있습니다.
## 게임의 시작부터 끝까지의 화면 출력
게임의 시작, 진행, 종료 화면을 출력합니다.
## 전투는 모두 자동
플레이어가 전투 중 획득한 아이템을 자동으로 사용하도록 설정합니다.
플레이어는 전투가 시작되면 전투 도중의 선택지 없이 끝날 때까지 기다려야 합니다.

## 📢 아직 수정되지 않은 버그/문제점
-
-
