#include "StoryPrinter.h"

void StoryPrinter::PrintIntro(Character* character) const
{
	cout << "\n====================\n" << endl;
	cout << "어느날 눈을 떠보니, 이세계에 스파르타 용사로 환생했다!?\n" << endl;
	Sleep(1000);
	cout << "오, 스파르타 용사 " << character->GetName() << ", 내 딸 공주를 구해주게...\n" << endl;
	Sleep(1000);
	cout << "드래곤을 쓰러트리고 공주를 구해달라고?? 아니아니 절대 무리인게 당연하잖아?!\n" << endl;
	Sleep(1000);
	cout << "애처로운 절규 따위 무시당한 채, 등 떠밀린 모험을 시작하게 되는데..." << endl;
	Sleep(1000);
	cout << "\n====================\n" << endl;
}

void StoryPrinter::PrintVictory(Character* character) const
{
	cout << "\n====================\n" << endl;
	cout << "드래곤을 쓰러트리자 나타난건, 도내 탑급 쿨뷰티 미소녀?!\n" << endl;
	Sleep(1000);
	cout << "\"당신이 저를 구해주신 용사님이신가요...?\" (와락)\n" << endl;
	Sleep(1000);
	cout << "\"어이어이! 절-대로 잘 어울리는 커플이잖아? 젠장!\"\n" << endl;
	Sleep(1000);
	cout << "이세계 생활... 썩 나쁘지 않을지도!? (코 쓱)\n" << endl;
	Sleep(1000);
	cout << "그렇게 " << character->GetName() << ", 공주는 결혼해서 이세계에서 오래오래 행복하게 살았답니다~ -끝- " << endl;
	Sleep(1000);
	cout << "\n====================\n" << endl;
}

void StoryPrinter::PrintLose() const
{
	cout << "\n====================\n" << endl;
	cout << "눈앞이 흐려진다... 여기까지인가 생각이 들던 그 때! \"용사님! 용사님!\"\n" << endl;
	Sleep(1000);
	cout << "당신을 부르는 목소리에 눈을 뜨자, 눈 앞에 나타난건... 여신님?!\n" << endl;
	Sleep(1000);
	cout << "용사님! 포기하지 말아요! 중요한건 꺾이지 않는 마음이라구요!\n" << endl;
	Sleep(1000);
	cout << "우오오옷! 젠장!!! 온몸에 믿을 수 없는 힘이 솟구친다!\n" << endl;
	Sleep(1000);
	cout << "여신님의 힘으로 다시 한번 환생하시겠습니까? [Y / N]  ";

}
