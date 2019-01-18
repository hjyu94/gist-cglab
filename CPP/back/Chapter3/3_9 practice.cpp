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
	
	// 기사를 봤을 때
	my_article_flags |= option_viewed;
	cout << "기사를 본 후 my article flag: " << bitset<8>(my_article_flags) << endl;

	// 기사의 좋아요를 클릭했을 때
	my_article_flags ^= option_liked;
	cout << "좋아요 클릭 후 my article flag: " << bitset<8>(my_article_flags) << endl;

	// 좋아요를 다시 클릭했을 때
	my_article_flags ^= option_liked;
	cout << "좋아요 또 클릭 후 my article flag: " << bitset<8>(my_article_flags) << endl;

	// 본 기사만 삭제할 때
	if (my_article_flags & option_viewed) {
		my_article_flags |= option_deleted;
		cout << "본 기사 임" << endl;
		cout << "삭제 후 my article flag: " << bitset<8>(my_article_flags) << endl;
	}
	else {
		cout << "본 기사 아님" << endl;
	}

	return 0;
}