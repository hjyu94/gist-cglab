// ����� ���α׷���
// ����ڰ� ��� ����ϴ��� �۵��� �� �� �ֵ���

// syntax error ���� ����
// ; ���� ���Ծ��� ��
// �����Ϸ��� ��� �ش�

// semantic error ���� ����
// int x;
// cin >> x;
// if(x>=5) cout<<"greater than 5" ;
// �� ����, x�� 5�϶��� ��µ�.

// violated assumption
// ����ڰ� ���� �ٸ� �ǵ��� ���α׷��� ����ϴ� ���

#include <iostream>
#include <string>
using namespace std;

int main() {
	string hello = "Hello, my name is Jack jack";
	
	int ix;

	// violated assumption
	// ������ġ, �����ġ�� �ɾ�δ� ������ ������
	while (true) {
		cin >> ix;
		cout << hello[ix] << endl;

		if (ix >= 0 && ix <= hello.size() - 1) {
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}
