#include "HealPotion.h"



HealPotion::getName() {
	return name;
}
HealPotion::use(Character* character) {

	int currentHealth = character->getHealth();//현재 체력 받아오기
	int maxHealth = character->getMaxHealth();//최대 체력 받아오기

	if (currentHealth == maxHealth) {// 풀피일때 물약 못먹게 설정
		cout << "체력이 이미 가득 찼습니다." << endl;
	}
	else {
		currentHealth += 50;//체력 50 증가
		cout << "물약을 사용했습니다 체력이 50 회복됩니다. 남은 체력 = " << currentHealth << endl;
	}
	return currentHealth; //증가된 체력 반환
}