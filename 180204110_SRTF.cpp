#include<iostream>
using namespace std;

int main()
{
    int atp[10], ctp[10], temp[10];
    int wt[10], tt[10], completion[10];
    int mn, cnt=0;
    double awt=0, tat=0, endtime;

    cout<<"\nEnter the number of Processes: ";
    int n;
    cin>>n;

    cout<<"\nEnter arrival time of process: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>atp[i];
    }

    cout<<"\nEnter CPU time of process: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>ctp[i];
    }

    for(int i=0; i<n; i++)
        temp[i]=ctp[i];

    ctp[9]=9999;

    for(int time=0; cnt!=n; time++)
    {
        mn=9;
        for(int i=0; i<n; i++)
        {
            if(atp[i]<=time && ctp[i]<ctp[mn] && ctp[i]>0 )
                mn=i;
        }
        ctp[mn]--;
        if(ctp[mn]==0)
        {
            cnt++;
            endtime = time+1;
            completion[mn] = endtime;
            wt[mn] = endtime - atp[mn] - temp[mn];
            tt[mn] = endtime - atp[mn];
        }
    }
    cout<<"Process"<<"\t"<< "   cpu-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"  completion-time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<temp[i]<<"\t\t"<<atp[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<"\t\t"<<completion[i]<<endl;
    }
    for(int i=0; i<n; i++)
    {
        awt = awt + wt[i];
        tat = tat + tt[i];
    }
    cout<<"\n\nAverage waiting time ="<<awt/n<<endl;
    cout<<"Average Turnaround time ="<<tat/n<<endl;
}
