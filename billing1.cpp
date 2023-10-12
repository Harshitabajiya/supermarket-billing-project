#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t          Supermarket Main Menu       \n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email   \n";
			cin>>email;
			cout<<"\t\t\t Password       \n";
			cin>>password;
			
			if(email=="harshitabajiya2838@gmail.com" && password=="harshita@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password";
			}
			break;
	
	
	case 2:
		{
			buyer();
			
		}
	
	case 3:
		{
			exit(0);
		}
		
		default :
			{
				cout<< "Please select from the given options";
				
			}
			
	
}
goto m;
}

void shopping:: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		add();
    		break;
    		
    	case 2:
    		edit();
    		break;
    		
    	case 3:
    		rem();
    		break;
    		
    	case 4:
    		menu();
    		break;
    		
    	default :
    		cout<<"Invalid choice!";
    		
	}
	goto m;
}

void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :
			
			cout<<"invalid choice";
			
	}
	
	goto m;
	
	
}

void shopping ::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product ";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on product";
	cin>>dis;
	//here I used file handling operation to write in file
	//ios::in means open file in reading mode 
	//ios::out means open file in writing mode

	data.open("database.txt",ios::in);
	
	if(!data)//if this file doesnt exists then then i will open file  in writing  mode
	{
		data.open("database.txt", ios::app|ios::out);//app=append mode
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else//if file exists then i will read from the file
	{
		data>>c>>n>>p>>d;
		//here we initialize the index of file
		
	//for iteration purpose we are reading from the file	
		while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
    
		
	
	
	if(token==1)
	goto m;
	else{
		//if  token is not incremented that is the code entered by the user is not duplicate then open file and write
		data.open("database.txt", ios::app|ios::out);
		//write inside the file and open file in writing mode to insert hence print recor inserted
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
}
	cout<<"\n\n\t\t Record inserted !";
}

void shopping ::edit()//fif you want to edit the function
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	//open file in readiing mode aqnd check whether it exists or not
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{
		//here we open the other file but not the same file  i.e data1
		//open this file in append mode and write 
		//here we save our edited data in new file and further rename it to the original name
		
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			//pkey is my code which is enetred by the administrator to edit the data if that matches then
			//inside the file we will write...
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
			}
			else
			{
				//if not matches then 
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;//for increment purpose
		}
		data.close();
		data1.close();
		
		remove("database.txt");//remove already file created and then i will rename the file
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
	
	
	
}
void shopping::rem()//remove fxn
{
	
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
		
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out);// open file in append and write mode 
		data>>pcode>>pname>>price>>dis;// here this is how we read dATA FROM  FILE 
		//here we use data because we will iterate through this data
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else//if does not match it will execute and display the database 1 file
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	//open the data base file in reading mode 
	cout<<"\n\n|___________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;//for the iteration purpose
		
	}
	data.close();
}

void shopping::receipt() //all the customer operation will take place
	{
		system("cls");
		fstream data;
		
		int arrc[100],arrq[100];//array of codes
		//array of quantity
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();    // close the already created file              
			list();//call this list because we have to show the custommer that these are the product 
			//available in the market
			cout<<"\n____________________________\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|____________________________|\n";
			do
			{
				m:
				cout<<"\n\n Product Code : ";
				cin>>arrc[c];//enterd by user
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
						goto m;
					}
				}
				c++;  //product key is not duplicate then it will increment            
				cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;	
			}
			
			while(choice == 'y');
			system("cls");
			
			cout<<"\n\n\t\t\t__________RECEIPT______________\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
			
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])   //here we are checking and calculating amount
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>pcode>>pname>>price>>dis;  //for iterating purpose
					   
					   
					   
					   
					   
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total;
		}
	}
int main()
{
	shopping s;
	s.menu();
}

