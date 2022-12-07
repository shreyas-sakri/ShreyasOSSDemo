#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;
 
int main()
{
	string fname="DMLab75_4.csv";
	vector<vector<string>> v;
	vector<string> row;
	string line, word;
	
	fstream file ;
	file.open(fname);
	if(file.is_open())
	{
		while(getline(file, line))
		{
		
			row.clear();
			 
			stringstream str(line);
			 
			while(getline(str, word, ','))
			row.push_back(word);
			v.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
	
	cout<<endl;
	
	int c1_tot = 0;
	int c2_tot = 0;
	int r1_tot = 0;
	int r2_tot = 0;
	for(int i=1;i<v.size();i++)
	{
		for(int j=1;j<v[i].size();j++)
		{ 
			 if(i==1)
			  r1_tot+=stoi(v[i][j]);
			 if(i==2)
			  r2_tot+=stoi(v[i][j]);
			 if(j==1)
			  c1_tot+=stoi(v[i][j]);
			 if(j==2)
			  c2_tot+=stoi(v[i][j]);
		}
	
	}
	
	ofstream writeFile("DMLab75_4_output.csv"); 
	writeFile<<"row 1 total:    "<<","<<r1_tot<<endl;
	writeFile<<"row 2 total:    "<<","<<r2_tot<<endl;
	writeFile<<"column 1 total: "<<","<<c1_tot<<endl;
	writeFile<<"column 2 total: "<<","<<c2_tot<<endl;
	
	
	 
	 for(int i = 1; i < v.size(); i++) 
	 {
	    for(int j = 1; j < v[i].size(); j++) 
		{
		    if(i == 1)
	            writeFile<<"\nt-weight for "<<v[i][j] << " wrt other is"<<","<<((double)stoi(v[i][j]) / r1_tot) * 100;
	        if(i == 2)
	            writeFile<<"\nt-weight for "<<v[i][j] << " wrt other is"<<","<<((double)stoi(v[i][j]) / r2_tot) * 100;
	        if(j == 1)
	            writeFile<<"\nd-weight for "<<v[i][j] << " wrt other is"<<","<<((double)stoi(v[i][j]) / c1_tot) * 100;
	        if(j == 2)
	            writeFile<<"\nd-weight for "<<v[i][j] << " wrt other is"<<","<<((double)stoi(v[i][j]) / c2_tot) * 100;
	    }
	}
	
	return 0;
}
 
 
