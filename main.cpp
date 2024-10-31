#include<iostream>
#include "ArraySKT.h"
using namespace std;

int main(){



	Array arr(7);
	arr.print();

	arr.insert(11);
	arr.insert(12);
	arr.insert(13);
	arr.insert(14);
	arr.print();
	arr.insertAt(7,15);
	arr.print();
/*

	//arr.remove();
	//arr.print();

	arr.removeAt(0);
	arr.print();

	arr.initArray(1);
	arr.print();

	arr.replaceAt(0,9999);
	arr.print();*/
	cout<<arr.at(8)<<endl;


	arr.clear();
	arr.print();

	//index out of bound
	cout<<arr.at(0)<<endl;

	int numbers[] = {1,2,3,4,5};
	Array arrNew(20);
	arrNew.copyArray(numbers,5);
	arrNew.print();
	arrNew.reverseArray();
	arrNew.print();

return 0;
}
