#include <iostream>
#include <bitset>

using namespace std;

int main() {
	unsigned char option_viewed = 0x01;
	unsigned char option_edited = 0x02;
	unsigned char option_liked = 0x04;
	unsigned char option_shared = 0x08;
	unsigned char option_deleted = 0x80;

	unsigned char my_article_flags = 0;

	// code here
	cout << "option viewed : " << bitset<8>(option_viewed) << endl;
	cout << "option edited : " << bitset<8>(option_edited) << endl;
	cout << "option liked  : " << bitset<8>(option_liked) << endl;
	cout << "option shared : " << bitset<8>(option_shared) << endl;
	cout << "option deleted: " << bitset<8>(option_deleted) << endl;

	cout << "my article flag: " << bitset<8>(my_article_flags) << endl;
	cout << endl;
	
	// ��縦 ���� ��
	my_article_flags |= option_viewed;
	cout << "��縦 �� �� my article flag: " << bitset<8>(my_article_flags) << endl;

	// ����� ���ƿ並 Ŭ������ ��
	my_article_flags ^= option_liked;
	cout << "���ƿ� Ŭ�� �� my article flag: " << bitset<8>(my_article_flags) << endl;

	// ���ƿ並 �ٽ� Ŭ������ ��
	my_article_flags ^= option_liked;
	cout << "���ƿ� �� Ŭ�� �� my article flag: " << bitset<8>(my_article_flags) << endl;

	// �� ��縸 ������ ��
	if (my_article_flags & option_viewed) {
		my_article_flags |= option_deleted;
		cout << "�� ��� ��" << endl;
		cout << "���� �� my article flag: " << bitset<8>(my_article_flags) << endl;
	}
	else {
		cout << "�� ��� �ƴ�" << endl;
	}

	return 0;
}