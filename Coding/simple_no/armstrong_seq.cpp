#include<iostream>
using namespace std;

int main() {
	int n,arm,sum,rem;
    for(int i = 100; i <= 4000; i++) {
        n = i;
        sum = 0;
        arm = n;

        while(n != 0) {
            rem = n % 10;
            sum = (rem * rem * rem) + sum;
            n = n / 10;
        }

        if (sum == arm) {
            cout << arm << "\n";
        }
    }

    return 0;
}

