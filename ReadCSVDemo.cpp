#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream readFile("DemoCSV.csv");
	vector<vector<string>> v;
	string City;
	string Trip1Cost;
	string Trip2Cost;
	while(readFile.peek()!=EOF)
	{
		getline(readFile,City,',');
		getline(readFile,Trip1Cost,',');
		getline(readFile,Trip2Cost,',');
		
		vector<string> v1;
		v1.push_back(City);
		v1.push_back(Trip1Cost);
		v1.push_back(Trip2Cost);
		
		v.push_back(v1);
	}
	ofstream writeFile("WriteCSV.csv");
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[0].size();j++)
		{
			writeFile << v[i][j] << ",";
		}
	}
	
	return 0;
}
