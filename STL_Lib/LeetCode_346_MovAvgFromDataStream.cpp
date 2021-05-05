/* leetcode - 346 Moving Average from Data Stream 
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/
#include <iostream>
#include<queue>
using namespace std;

class MovingAvg {
private:
	queue<int> q;
	int size;
	double sum;
public:
	MovingAvg(int size) {	// sign value thru constrcutor initialization
		this->size = size;	// this points to current object, from private int size
		sum = 0;
	}

	double Sliding(int val) {
		if (q.size() >= size) { // if the queue size() greater than the user defined i/p,  size 3 
			sum = sum - q.front();
			q.pop();
		}
		q.push(val);
		sum = sum + val;
		return sum / q.size();
	}
	
};
int main() {
	MovingAvg obj = MovingAvg(3);
	 
	cout << obj.Sliding(1) << endl;
	cout << obj.Sliding(10) << endl;
	cout << obj.Sliding(3) << endl;
	cout << obj.Sliding(5) << endl;
	return 0;
}