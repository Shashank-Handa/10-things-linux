#include <iostream>

#include<fstream>

using namespace std;


int main(int argc, char* argv[]){
	if(argc<=1){
		return -1;
	}

	string filename = argv[1];
	
	ifstream fin;
	
	fin.open(filename);
	
	
	string line;
	while(getline(fin, line)){
		int n=line.size();
		for(int i=0; i<n/2;i++){
			swap(line[i], line[n-i-1]);
		}
		cout<<line<<endl;
	}
	fin.close();
	return 0;
	
}
