#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
class flight
{
public:
long  flightno,fare;
char  flightname[30], source[20], desti[20], stime[5], dtime[5];
void getf()
 {
  cout<<"Please enter the flight number: \n ";
  cin>>flightno;
  cout<<"Please enter the flight name:  \n";
  cin>>flightname;
  cout<<"Please enter the source:  \n";
  cin>>source;
  cout<<"Please enter the destination:  \n";
  cin>>desti;
  cout<<"Please enter the departure time 
  (start from source): \n”;                
  cin>>stime;
  cout<<"Please enter the arrival time (stop at      
  destination): \n”;
  cin>>dtime;
  cout<<"Please enter the fare per person:\n”  
  cin>>fare;
 }
void showf()
 {
  cout<<"The flight number is: " <<flightno<<"\n\n";
  cout<<"The flight name is:"<<flightname<<"\n\n";
  cout<<"The source is:"<<source<<"\n\n";
  cout<<"The destination is:"<<desti<<"\n\n";
  cout<<"The departure time (start from source) is :”
  <<stime<<”\n\n”;
  cout<<"The arrival time (stop at destination) is:”
  <<dtime<<"\n\n";
}
long retflno()
 {
  return flightno;
 }
};


class customer
{
public:
char cusname[30],desti[20],source[20],flightname[30];
int nop,ticketno;
long fare, flightno;
void cusinfo()
 {
  cout<<"Please enter your name: \n";
  cin >>cusname;
  cout<<"Please enter the source: \n";
  cin >>source;
  cout<<"Please enter the destination: \n";
  cin >>desti;
  cout<<"Please enter the no. of people: \n";
  cin>>nop;
 }
void calcfare()
 {
  cout<<"Your total Fare is: \n"<<nop*fare;
 }
 void showc()
  {
   cout<<"\n Name: \t "<<cusname;
   cout<<"\n Source: \t "<<source;
   cout<< "\n Destination: \t "<<desti;
   cout<<"\n Number of Persons: \t "<<nop;
   cout<<"\n Ticket no.: \t "<<ticketno;
   calcfare();
  }
};



void main()
{
flight f,fli;
int opt,g,n,ticket,fl;
customer c,cus;
char ch='y';
long no;
clrscr();
char pass[10];
cout<<"*^*^*^*^*^*^*^*^*^*^*^*^-WELCOME TO STARCOM TRAVEL AGENCY-^*^*^*^*^*^*^*^*^*^*^*\n\n";
cout<<"Please enter  the password if you are an officer else enter any alphabet\n";
cin>>pass;
if(strcmp(pass,"yes")==0)
 {
  cout<<"\t"<<"\t"<<"  "<<"\t"<<"Hello Sir ,\n\n Here are
  your options-\n\n";
  cout<<"\t"<<"\t"<<"1."<<"\t"<<"Inserting more   
  flights\n\n";
  cout<<"\t"<<"\t"<<"2."<<"\t"<<"Canceling flights\n\n";
  cout<<"\t"<<"\t"<<"3."<<"\t"<<"Altering flight
  information\n\n";
  cout<<"\t"<<"\t"<<"4."<<"\t"<<"Show flight information 
  \n\n";
  cout<<"\t"<<"\t"<<"5."<<"\t"<<"Quit \n";
  cin>>opt;
  clrscr();
  switch(opt)
   {
    case 1:  cout<<"You have entered for:Inserting more
                flights \n";
                
                ofstream out("flight.dat",ios::binary|ios::app|  
                ios::end);
	         while(ch!='n')
	         {
	          f.getf();
	          out.write((char*)&f,sizeof(f));
	          cout<<"The following flight has been     
                 entered:  \n";
	          f.showf();
	          cout<<"Want to enter more flights? y/n \n";
	          cin>>ch;
	         }
	        out.close();
	        break;



 case 2:  cout<<"You have entered for: Cancelling   
              existing flights \n\n";
	      cout<<"Please enter the flight number of flight
             	to be cancelled";
             cin>>no;
	      ifstream i("flight.dat",ios::binary,ios::beg);
	      ofstream o("temp.dat",ios::binary|ios::app);
	      i.read((char*)&f,sizeof(f));
	      while(i)
	       {
		if(f.flightno!=no)
		 {
		  o.write((char*)&f,sizeof(f));
		  i.read((char*)&f,sizeof(f));
		 }
		else
		 {
		  fli=f;
		  i.read((char*)&f,sizeof(f));
		 }
	       }
	      o.close();
	      i.close();
	      remove("flight.dat");
	      rename("temp.dat","flight.dat");
	      cout<<"flight deleted:\n";
	      fli.showf();
	      break;
	      





 case 4: cout<<"You have entered to: Show the flight 
             information \n \n";
	      cout<<"Please enter the flight number of flight
            to  be displayed \n";
	     cin>>no;
	     ifstream inn("flight.dat",ios::binary);
	     inn.read((char*)&f,sizeof(f));
	     while(inn)
	     {
	      if(f.flightno==no)
	       {
		f.showf();
		break;
	       }
	      else
	       inn.read((char*)&f,sizeof(f));
	     }
	     inn.close();
	     break;
case 5:  exit(0);
	    break;
default:"Please enter proper choice";
  }
 }
else
 {
  cout<<"Please enter your choice out of-\n\n";
  cout<<"\t"<<"\t"<<"1."<<"\t"<<"General
  instructions\n\n";
  cout<<"\t"<<"\t"<<"2."<<"\t"<<"Flight information \n\n”;
  cout<<"\t"<<"\t"<<"3."<<"\t"<<"Booking of tickets \n\n";
  cout<<"\t"<<"\t"<<"4."<<"\t"<<"Cancelling of
  tickets\n\n";
  
  cout<<"\t"<<"\t"<<"5."<<"\t"<<"Show ticket information  
  through ticket no.\n\n";
  cout<<"\t"<<"\t"<<"6."<<"\t"<<"Quit \n";
  cin>>opt;
 switch(opt)
  {
   case 1: cout<<"General Norms and conditions to be
              followed while booking/cancelling tickets  
              online are: \n\n ";
	       cout<<"1.All the information entered must be   
              correct.Changes can't be made later. \n\n";
	       cout<<"2.Only 75% of your money will be  
              returned back on cancellation. \n\n";
	       cout<<"3.Cancellation of tickets must be done  
             within 15 days of booking. \n \n";
	      cout<<"4.Flights may be cancelled due to  
             unfavourable wheather conditions. \n \n";
	      cout<<"5.Your fare must be payed within 5 days  
             of booking in case of payment by cash \n\n";
	      cout<<"6.The flight timings may be altered due 
             to technical problems. \n\n";
	      cout<<"7.For more information you may visit our
            office. \n\n";
            break;
case 2: ifstream in("flight.dat",ios::binary);
	     in.read((char*)&f,sizeof(f));
	     while(in)
	     {
	     f.showf();
	     in.read((char*)&f,sizeof(f));
	     }
	     in.close();
	     break;

case 3: cout<<"You Opted for booking tickets";
	     c.cusinfo();
	     ifstream in1("flight.dat",ios::binary|ios::beg);
	     in1.read((char*)&f,sizeof(f));
	     while(in1)
	    {
	     if(strcmpi(c.desti,f.desti)==0&&   
            strcmpi(c.source,f.source)==0)
	      {
	       f.showf();
	       c.fare=f.fare;
	       c.flightno=f.flightno;
	       strcpy(c.flightname,f.flightname);
	       in1.read((char*)&f,sizeof(f));
	       break;
	      }
	     else
	      in1.read((char*)&f,sizeof(f));
	    }
	   ifstream in2("customer.dat",ios::binary|ios::beg);
	    if(in2.eof())
	    c.ticketno=1;
	    else
	     {
	      in2.read((char*)&f,sizeof(f));
	      while(in2)
	       {
		in2.read((char*)&f,sizeof(f));
	       }
	      n=c.ticketno+1;
	     }
	    ofstream   
           out1("customer.dat",ios::app|ios::binary);
	    c.ticketno=n;
	    out1.write((char*)&c,sizeof(c));
	    in2.close();
	    in1.close();
	    out1.close();
	    c.showc();
	    break;
case 4:  cout<<"You Opted for-Cancelling of tickets";
	      cout<<"Please enter the ticket number of ticket 
             to be cancelled";
	      cin>>no;
	      ifstream     
            in4("customer.dat",ios::binary|ios::beg);
            ofstream out2("temp.dat",ios::app|ios::binary);
	     in4.read((char*)&c,sizeof(c));
	     while(in4)
	     {
	     if(c.ticketno!=no)
	      {
	       out2.write((char*)&c,sizeof(c));
	       in4.read((char*)&f,sizeof(f));
	      }
	     else
	      {
	       cus=c;
	       in4.read((char*)&f,sizeof(f));
	      }
	     }
	     in4.close();
	     out2.close();
	     remove("customer.dat");
	     rename("temp.dat","customer.dat");
	     cout<<"Details of following customer is 
           deleted:\n";
	    cus.showc();
	    break;
case 5:  cout<<"Please enter your ticket no.";
	      cin>>ticket;
	      ifstream    
            in3("customer.dat",ios::binary|ios::beg);
	     in3.read((char*)&c,sizeof(c));
	     while(in3)
	     {
	      if(c.ticketno==ticket)
	       {
		cout<<"CUSTOMER DETAILS: \n";
		c.showc();
		fl=c.flightno;
		break;
	       }
	      else
	       in3.read((char*)&c,sizeof(c));
	     }
	    in3.close();
	    ifstream in5("flight.dat",ios::binary|ios::beg);
	    in5.read((char*)&f,sizeof(f));
	    while(in5)
	     {
	      if(f.flightno==fl)
	       {
		cout<<"FLIGHT DETAILS: \n";
		f.showf();
		break;
	       }
	      else
	       in5.read((char*)&f,sizeof(f));
	     }
	    in5.close();
	    break;
   case 6:  exit(0);
	         break;
   default: cout<<"Please enter proper choice";
  }
 }
getch();
}
