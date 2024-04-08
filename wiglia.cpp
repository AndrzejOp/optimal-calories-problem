#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Dish {
	string dishName;
	int kcal = 0;
};

int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;
	
	vector<Dish> dishes(n);

	int maxCalories = 0;
	for (int i = 0; i < n; i++) {
		cin >> dishes[i].dishName >> dishes[i].kcal;
		if (dishes[i].kcal > maxCalories) {
			maxCalories = dishes[i].kcal;
		}
	}
	for (int i = 1; maxCalories / i > 0; i *= n) {
		vector<Dish> C(n);
		int* ranks = new int[n] {0};
		for (int j = 0; j < n; j++) {
			ranks[(dishes[j].kcal / i) % n]++;
		}
		for (int j = 1; j < n; j++) {
			ranks[j] += ranks[j - 1];
		}
		for (int j = n - 1; j >= 0; j--) {
			C[ranks[(dishes[j].kcal / i) % n] - 1] = dishes[j];
			ranks[(dishes[j].kcal / i) % n]--;
		}
		dishes = C;
	}
	for (Dish dish : dishes) {
		cout << dish.dishName << " ";
	}

	return 0;

}