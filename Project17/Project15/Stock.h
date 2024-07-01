#ifndef STOCK
#define STOCK
#include <iostream>
using namespace std;

class Stock {
private:
	string name;
	int shares;
	float share_val;
	double tot_val;
	void set_total() {
		tot_val = shares * share_val;
	}
public:
	void buy(int, float);
	void sell(int, float);
	void update(float);
	void show();
	Stock &topval(Stock&);
	Stock(string, int, float);
	Stock();
	~Stock();
};

#endif
