#include <iostream>
#include <vector>

using namespace std;

struct Student {
         int idn;
         string name;
         double mark;   
         bool repeater;
 };
     
void information(const vector<Student>& stu, double& min, double& max, double& avg){
	max = min = avg = -1;
	bool fi = true;
	int vsize = stu.size();
	int people = 1;
	for (int i = 0;i < vsize;++i){
		if (not stu[i].repeater and stu[i].mark > -1){
			if (fi) {
				fi = false;
				min = stu[i].mark;
				max = min;
				avg = min;
			}
			else {
				++people;
				if (stu[i].mark < min)min = stu[i].mark;
				else if (stu[i].mark > max) max = stu[i].mark;
				avg = avg + stu[i].mark;
			}
		}
	}
	if(min > -1)avg = avg / people;
}

int main () {
}