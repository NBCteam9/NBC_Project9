#include "HealPotion.h"



HealPotion::getName() {
	return name;
}
HealPotion::use(Character* character) {

	int currentHealth = character->getHealth();//���� ü�� �޾ƿ���
	int maxHealth = character->getMaxHealth();//�ִ� ü�� �޾ƿ���

	if (currentHealth == maxHealth) {// Ǯ���϶� ���� ���԰� ����
		cout << "ü���� �̹� ���� á���ϴ�." << endl;
	}
	else {
		currentHealth += 50;//ü�� 50 ����
		cout << "������ ����߽��ϴ� ü���� 50 ȸ���˴ϴ�. ���� ü�� = " << currentHealth << endl;
		character->setHealth(currentHealth); // ü�� �缳��
	}
}