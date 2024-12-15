#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int w;
    cout<<"\n Enter the Size of Sliding Window :-  ";
    cin>>w;
    
    int f;
    cout<<"\n Enter the number of Frames :- ";
    cin>>f;
    
    int frames[f];
    cout<<"\n Enter the "<<f<<"Frames one by one :- \n";
    for(int i=0;i<f;i++)
    {
        cin>>frames[i];
    }
    
    queue<int> Q;
    
    cout<<"\n\n(1 - Send Acknowledgement  0 -  do not send Acknowledgement)"<<endl;
    
    
    for(int i=0 ; i < w ; i++)
    {
        if(i<f)
        {
            Q.push(frames[i]);
            cout<<"Sending Data"<<frames[i]<<"...."<<endl;
        }
    }
    
    bool flag=0;
    for(int i=0;i<f;i++)
    {
        cout<<"\n Send the Acknowledgement of "<<Q.front()<<"\n (1 or 0) :- ";
        cin>>flag;
        
        int ack_frame=Q.front();
        Q.pop();
        
        
        if(flag==1)
        {
            Q.push(frames[i+w]);
            cout<<"\n Sending data "<<frames[i+w]<<"..."<<endl;
           
        }
    
    else
    {
        Q.push(ack_frame);
        cout<<"\n Sending data"<<ack_frame<<"...."<<endl;
        i--;
    }
}

cout<<"\n\n Frames Transfered Succesfully"<<endl;
    
}

