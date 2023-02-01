#include<iostream>
#include<cmath>
using namespace std;

struct disk
{
    double center_x;
    double center_y;
    double radius;
};
bool intersect(disk d1,disk d2)
{
    return pow(d1.center_x-d2.center_x,2)+pow(d1.center_y-d2.center_y,2) < pow(d1.radius+d2.radius,2);
}

bool checkAllPairs(disk disks[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; i < n; j++)
        {
            if (intersect(disks[i],disks[j]))
            {
                return true;
            }
            
        }
        
    }
    return false;
}

void readData(disk disks[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the "<<i+1<<" Disk Details: "<<endl;
        cout<<"Enter the x corrdinate: ";
        cin>>disks[i].center_x;
        cout<<"Enter the y coordinate: ";
        cin>>disks[i].center_y;
        cout<<"Enter the Radius: ";
        cin>>disks[i].radius;
    }
}

int main()
{
     int n;
     cout<<"Enter the number of disks: ";
     cin>>n;
     cout<<endl;
    disk disks[n];

    readData(disks,n);
    if(checkAllPairs(disks,n))
        cout<<"Yes they intersect"<<endl;
    else
        cout<<"No they don't intersect"<<endl;
    
    return 0;
}