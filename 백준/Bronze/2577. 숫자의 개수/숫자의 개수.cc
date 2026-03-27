#include <iostream>
#include <cmath>
#pragma warning(disable: 4996)

using namespace std;

int main() {

	int nums[3], onetonine[10] = {0}, cnt, mul=1;
	double res;
	bool top=false;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &nums[i]);
		mul *= nums[i];
	}

	for (int i = 8; i >= 0; i--) {
		res = mul / pow(10, i);
		if (res >= 1 && top == false) {
			top = true;
		}
		if (top == true) {
			cnt = (int)res;
			onetonine[cnt]++;
		}
		mul = mul - (int)res * pow(10, i);
	}

	for (int i = 0; i < 10; i++) {
		cout << onetonine[i] << endl;
	}

	return 0;

}