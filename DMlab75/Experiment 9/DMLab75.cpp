#include<bits/stdc++.h>
using namespace std;

double calDistance(vector<double> centroid,vector<double> point)
{
	double sum = 0;
	for(int i=0;i<point.size();i++)
	{
		sum = sum + pow((centroid[i] - point[i]),2);
	}
	double distance = sqrt(sum);
	return distance;
}
int main()
{
	vector<vector<double>> points;
	
	int n,dim;
	cout<<"enter the number of points required in circle : ";
	cin>>n;
	cout<<"enter the required dimention : ";
	cin>>dim;
	
	
	
	for(int i=0;i<n;i++)
	{
		vector<double> coordinates;
		double val;
		int k=1;
		for(int j=0;j<dim;j++)
		{
			cout<<"Enter Point : "<< k++ <<" : ";
			cin>>val;
			coordinates.push_back(val);
		}
		points.push_back(coordinates);
	}
	
	vector<double>centroid;
	
	for(int i=0;i<dim;i++)
	{
		double sum=0;
		for(int j=0;j<points.size();j++)
		{
			sum = sum + points[j][i];
		}
		centroid.push_back((double)sum/points.size());
	}
	
	cout<<"Centroid is : (";
	for(int i=0;i<centroid.size();i++)
	{
		if(i==centroid.size()-1)
		cout<<centroid[i];
		else
		cout<<centroid[i]<<",";
	}
	cout<<")";
	
	vector<double> distances;
	
	for(int i=0;i<n;i++)
	{
		distances.push_back(calDistance(centroid,points[i]));
	}
	
	
	vector<double> new_center;
	double min=INT_MAX;
	int new_center_index=-1;
	for(int i=0;i<distances.size();i++)
	{
		if(distances[i]<min) 
		{
			min = distances[i];
			new_center_index = i;
		}
	}
	
	new_center = points[new_center_index];
	
	vector<double> new_distances;
	
	for(int i=0;i<n;i++)
	{
		new_distances.push_back(calDistance(new_center,points[i]) );
	}
	
	double matrix[points.size()][points.size()];
	
	for(int i=0;i<points.size();i++)
	{
		for(int j=0;j<points.size();j++)
		{
			if(i>j)
				matrix[i][j] = calDistance(points[i],points[j]);
			else
				matrix[i][j] = 0;
		}
	}
	
	ofstream writeFile("DMLab75_9_output.csv");
	string p_col = "P";
	int idx_col=1;
	string p_row = "P";
	int idx_row=1;
	writeFile<<" "<<",";
	for(int i=0;i<=dim;i++)
	{
		writeFile<<p_row + to_string(idx_row++)<<",";
	}
	writeFile<<endl;
	for(int i=0;i<points.size();i++)
	{
		writeFile<<p_col+to_string(idx_col++)<<",";
		for(int j=0;j<points.size();j++)
		{
			writeFile<<matrix[i][j]<<",";
		}
		writeFile<<endl;
	}
	
}
