#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
FILE *f1,*f2;
#define size 200


typedef struct Account{

			int account_number;

			char name[30];

			char mobile[11];

			char address[50];

			char city[15];

			double balance;


};



//Function that allows user to insert information into a file
void insert()
{
	restart:
	int user_input;
	struct Account user;
	
	
	printf("Enter the account number: ");
	scanf("%d",&user.account_number);

	printf("\nEnter the name of the client: ");
	//using getchar because gets function is ignored during runtime,so getchar takes its place and gets ignored instead allowing use of gets function
	getchar();
	gets(user.name);

	printf("\nEnter the moblie phone number: ");
	//%[^\n]s reads until it finds \n,so it stores spaces as well
	scanf("%[^\n]s",&user.mobile);

	printf("\nEnter the address: ");
	getchar();
	scanf("%[^\n]s",&user.address);

	printf("\nEnter the city: ");
	getchar();
	gets(user.city);

	printf("\nEnter the balance of the account: ");
	scanf("%lf",&user.balance);
	printf("\n");

	//Opening file on append mode to allow for updates if user chooses 
	f1= fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt", "a ");

	//Printing the user inputs in the file
	fprintf( f1, "%d\n", user.account_number);
	fprintf( f1, "%s\n", user.name);
	fprintf( f1, "%s\n", user.mobile);
	fprintf( f1, "%s\n", user.address);
	fprintf( f1, "%s\n", user.city);
	fprintf( f1, "%lf\n", user.balance);

	//Closing file to save the information inside
	fclose(f1);
	
	retry:
	
	printf("do you want to enter another record? \n type 1 for yes and 0 for no: ");
	scanf("%d",&user_input);

	//if user wants to enter another record call the function again
	if (user_input==1)
	{

		insert();
		
	}
	//if user inputs a wrong choice inform him and goto the label "retry" to ask for input again
	else if(user_input	!= 1 && user_input != 0)
	{
		//clear the console screen
		system("cls");
		printf("Wrong input try again\n");
		//Function that clears the buffer,so that an error doesn't occur
		fflush(stdin);
		goto retry;
	}
	

		
		
}

void Display_Per_Acc()
{
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");
	//Loop that reads file until the end
	while(input_status!=EOF)
	{
		//The %*c removes the \n in the file
		fscanf(f1,"%d%*c",&user[i].account_number);
		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		//when the end of file is reached fscanf returns -1 which is EOF
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}

	//Loop that sorts the array based on account number
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(user[j].account_number>user[j+1].account_number)
			{
				temp=user[j+1];
				user[j+1]=user[j];
				user[j]=temp;
			}
		}
	}
	printf("\n");

	//Loop that prints the the sorted array
	for(i=0;i<size;i++)
	{
		//If the account number in the array is not equal to 0 print the array
		if(user[i].account_number != NULL)
		{
		printf("%d",user[i].account_number);
		printf(" %s",user[i].name);
		printf(" %s",user[i].mobile);
		printf(" %s",user[i].address);
		printf(" %s",user[i].city);
		printf(" %lf",user[i].balance);
		printf("\n");
		}
	}
}

void Display_Per_Name()
{
int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	//Loop that reads file until the end
	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);

		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);

		i++;
	
	}

	//Loop that sorts array based on name using the strcmp function from string.h library
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(strcmp(user[j].name,user[j+1].name)>0)
			{
				temp=user[j+1];
				user[j+1]=user[j];
				user[j]=temp;
			}
		}
	}
	printf("\n");

	//Loop that prints the sorted array
	for(i=0;i<size;i++)
	{
		if(user[i].account_number != NULL)
		{
		printf("%d",user[i].account_number);
		printf(" %s",user[i].name);
		printf(" %s",user[i].mobile);
		printf(" %s",user[i].address);
		printf(" %s",user[i].city);
		printf(" %lf",user[i].balance);
		printf("\n");
		}
	}

}

void Display_per_Balance()
{
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	//Loop that reads until the end of file
	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);
		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);

		i++;
	
	}

	//Loop that sorts based on balance
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(user[j].balance>user[j+1].balance)
			{
				temp=user[j+1];
				user[j+1]=user[j];
				user[j]=temp;
			}
		}
	}
	printf("\n");

	//Loop that prints the sorted array
	for(i=0;i<size;i++)
	{
		if(user[i].account_number != NULL)
		{
		printf("%d",user[i].account_number);
		printf(" %s",user[i].name);
		printf(" %s",user[i].mobile);
		printf(" %s",user[i].address);
		printf(" %s",user[i].city);
		printf(" %lf",user[i].balance);
		printf("\n");
		}
	}

}

void Delete_Record()
{
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};
	int ans;

	//Open the file in read mode
	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	//Loop that scans until end of file
	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);
		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}

	//Close the file 
	fclose(f1);

	//Open the file in write mode to write the new file without the unwanted record
	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","w+");

	int Deleted_Account_Number=0;
	printf("enter the account number of the record you want to delete: ");
	scanf("%d",&Deleted_Account_Number);

		for(int i=0;i<size-1;i++)
		{
			check:

			//If the user account number is not equal to the account number the user wants to delete and not equal to 0(meaning end of file not reached)
			if((user[i].account_number != Deleted_Account_Number) && (user[i].account_number != 0))
			{
				
				//Print the records
				fprintf( f1, "%d\n", user[i].account_number);
				fprintf( f1, "%s\n", user[i].name);
				fprintf( f1, "%s\n", user[i].mobile);
				fprintf( f1, "%s\n", user[i].address);
				fprintf( f1, "%s\n", user[i].city);
				fprintf( f1, "%lf\n",user[i].balance);
				
				
			}
			//If the user account = 0 then end of file has been reached
			else if(user[i].account_number == 0)
			{
				break;
			
			}
			
			
		}		

		//Close the file to save it
		fclose(f1);

		printf("Record successfully deleted");
}

void Update_Record()
{
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};
	int ans;
	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);

		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}


	int Updated_Account_Number=0;

	printf("enter the account number you want to edit");
	scanf("%d",&Updated_Account_Number);

		
		for(int i=0;i<size-1;i++)
		{
			//if the account number is equal to the account number the user typed in print 7 choices
			if(user[i].account_number == Updated_Account_Number)
			{
				
				printf("choose from 1-7 according to which element you want to edit. \n 1.acount number \n 2.name \n 3.moblie \n 4.address \n 5.city \n 6.balance \n 7.return to menu \n your choice:");
				scanf("%d",&ans);
				fflush(stdin);

				if(ans==1)
				{
				printf("enter the new account number: ");
				scanf("%d",&user[i].account_number);
				fflush(stdin);
				}

				else if(ans==2)
				{
				printf("enter the new name: ");
				gets(user[i].name);
				fflush(stdin);
				}

				else if(ans==3)
				{
				printf("enter the new mobile: ");
				scanf("%s",&user[i].mobile);
				fflush(stdin);
				}

				else if(ans==4)
				{
				printf("enter the new address: ");
				gets(user[i].address);
				fflush(stdin);
				}

				else if(ans==5)
				{
				printf("enter the new city: ");
				gets(user[i].city);
				fflush(stdin);
				}


				else if(ans==6)
				{
				printf("enter the new balance: ");
				scanf("%lf",&user[i].balance);
				fflush(stdin);
				}


				else if(ans==7)
				{
					//Go to label jump thus skipping the rest of the function
					goto jump;
	
				}
				
				
			}
			
		}
			
			//Close the file
			fclose(f1);

			//open the file in write to put in the updated records and overwrite the old text file
			f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","w+");


		for(int j=0;j<size-1;j++)
		{
			
			if(user[j].account_number != 0)
			{
				
				fprintf( f1, "%d\n", user[j].account_number);
				fprintf( f1, "%s\n", user[j].name);
				fprintf( f1, "%s\n", user[j].mobile);
				fprintf( f1, "%s\n", user[j].address);
				fprintf( f1, "%s\n", user[j].city);
				fprintf( f1, "%lf\n",user[j].balance);

			}
			
			
	     }

		fclose(f1);

		//Putting getch for jump label to function
		jump:
		getch();
}

void Search_Per_Acc()
{

	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);

		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}
	int Desired_account=0;
	printf("enter the account number: ");

	  //While loop meant for error handling to prevent user from entering string instead of an integer
	  while(scanf("%d",&Desired_account) != 1)
		{
			printf("Please enter an integer: ");
			while(getchar() != '\n');
		}
		for(int j=0;j<size-1;j++)
		{
			//If account number equal to desired account print the full record and jump to end of function
			if(user[j].account_number == Desired_account)
			{
					

				printf("%d",user[j].account_number);
				printf(" %s",user[j].name);
				printf(" %s",user[j].mobile);
				printf(" %s",user[j].address);
				printf(" %s",user[j].city);
				printf(" %lf",user[j].balance);
				printf("\n");
				goto jump;
			}
			
		}
			//
			for(int j=0;j<size-1;j++)
			{
				//If the account number was not found call the function again
				if(user[j].account_number != Desired_account)
				{
			
					printf("\ninvalid account number \n try again \n");
					Search_Per_Acc();
				}
			}


			jump:
			getch();
}

void Search_Per_Name()
{
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);

		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}
	char temp_name[30];
	char*ptr;
	printf("enter the account name: ");
	fflush(stdin);
	gets(temp_name);

		for(int j=0;j<size-1;j++)
		{
			if(strcmp(user[j].name,temp_name)==0)
			{
					

				printf("%d",user[j].account_number);
				printf(" %s",user[j].name);
				printf(" %s",user[j].mobile);
				printf(" %s",user[j].address);
				printf(" %s",user[j].city);
				printf(" %lf",user[j].balance);
				printf("\n");
				goto jump;
			}
			
		}
			for(int j=0;j<size-1;j++)
			{
				if(strcmp(user[j].name,temp_name)!=0)
				{
			
					printf("\ninvalid account name \n try again \n");
					Search_Per_Name();
				}
			}
			jump:
			getch();

}

void Withdraw()
{
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);

		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}
	retry:
	int tempacc=0;
	double amount=0;
	printf("enter the account number");
	scanf("%d",&tempacc);


	printf("enter the amount you want to withdraw: ");
	scanf("%lf",&amount);

		for(int j=0;j<size-1;j++)
		{

			
			if(user[j].account_number == tempacc)
			{
				//Subtract the the amount the user entered from the balance in the record
				user[j].balance-=amount;

				printf("%d",user[j].account_number);
				printf(" %s",user[j].name);
				printf(" %s",user[j].mobile);
				printf(" %s",user[j].address);
				printf(" %s",user[j].city);
				printf(" %lf",user[j].balance);
				printf("\n");
				

				

				goto jump;
			}
			
		}
			for(int j=0;j<size-1;j++)
			{
				if(user[j].account_number != tempacc)
				{
			
					printf("\ninvalid account number \n try again \n");
					goto retry;
				}
			}
			jump:
			fclose(f1);

			f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","w+");
			
			
		for(int j=0;j<size-1;j++)
		{
			check:
			if((user[j].account_number != tempacc) && (user[j].account_number != 0))
			{
				

				fprintf( f1, "%d\n", user[j].account_number);
				fprintf( f1, "%s\n", user[j].name);
				fprintf( f1, "%s\n", user[j].mobile);
				fprintf( f1, "%s\n", user[j].address);
				fprintf( f1, "%s\n", user[j].city);
				fprintf( f1, "%lf\n",user[j].balance);
				
				
			}
			else if(user[j].account_number == tempacc)
			{
				


				fprintf( f1, "%d\n", user[j].account_number);
				fprintf( f1, "%s\n", user[j].name);
				fprintf( f1, "%s\n", user[j].mobile);
				fprintf( f1, "%s\n", user[j].address);
				fprintf( f1, "%s\n", user[j].city);
				fprintf( f1, "%lf\n",user[j].balance);
				
			}
			else if(user[j].account_number == 0)
			{
				break;
			
			}
			
			
		}
	

		fclose(f1);

	
}

void Credit()
{
	
	int i = 0;
	double input_status = 0;
	Account temp ={0},user[size]={0};

	f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","r");

	while(input_status!=EOF)
	{
		fscanf(f1,"%d%*c",&user[i].account_number);

		fscanf(f1,"%[^\n]s",&user[i].name);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].mobile);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].address);
		fscanf(f1,"%*c");
		fscanf(f1,"%[^\n]s%*c",&user[i].city);
		fscanf(f1,"%*c");
		input_status = fscanf(f1,"%lf%*c",&user[i].balance);
		

		i++;
	
	}
	retry:
	int tempacc=0;
	double amount=0;
	printf("enter the account number");
	scanf("%d",&tempacc);


	printf("enter the amount you want to credit: ");
	scanf("%lf",&amount);

		for(int j=0;j<size-1;j++)
		{


			if(user[j].account_number == tempacc)
			{
				user[j].balance+=amount;

				printf("%d",user[j].account_number);
				printf(" %s",user[j].name);
				printf(" %s",user[j].mobile);
				printf(" %s",user[j].address);
				printf(" %s",user[j].city);
				printf(" %lf",user[j].balance);
				printf("\n");
				

				

				goto jump;
			}
			
		}
			for(int j=0;j<size-1;j++)
			{
				if(user[j].account_number != tempacc)
				{
			
					printf("\ninvalid account number \n try again \n");
					goto retry;
				}
			}
			jump:
			fclose(f1);

			f1=fopen("Userssalem salemDesktopmooazzConsoleApplication20ConsoleApplication20.txt","w+");
			
			
		for(int j=0;j<size-1;j++)
		{
			check:
			if((user[j].account_number != tempacc) && (user[j].account_number != 0))
			{
				

				fprintf( f1, "%d\n", user[j].account_number);
				fprintf( f1, "%s\n", user[j].name);
				fprintf( f1, "%s\n", user[j].mobile);
				fprintf( f1, "%s\n", user[j].address);
				fprintf( f1, "%s\n", user[j].city);
				fprintf( f1, "%lf\n",user[j].balance);
				
				
			}
			else if(user[j].account_number == tempacc)
			{
				


				fprintf( f1, "%d\n", user[j].account_number);
				fprintf( f1, "%s\n", user[j].name);
				fprintf( f1, "%s\n", user[j].mobile);
				fprintf( f1, "%s\n", user[j].address);
				fprintf( f1, "%s\n", user[j].city);
				fprintf( f1, "%lf\n",user[j].balance);
				
			}
			else if(user[j].account_number == 0)
			{
				break;
			
			}
			
			
		}
	

		fclose(f1);

}


void main()
{
		//Function to color the text in the console
		system("color b");

		int number = 0;

		checkpoint:
		
		printf(" \t \t MAIN MENU \n1. Insert Record/Records\n2. Display Records as per Account Number\n3. Display Records as per Customer Name\n4. Display Records as per Customer Balance\n5. Delete Record\n6. Update Record\n7. Search Record Details as per the account number\n8. Search Record Details as per the Customer Name\n9. Debit/Withdraw from the account\n10. Credit into the account\n11. Exit\n");
		
		printf("Enter your choice: ");

		scanf("%d",&number);

		if(number==1)
		{
			insert();
			getch();
			//Clear the console screen
			system("cls");
			//Repeat main
			goto checkpoint;
		}
		else if(number==2)
		{
			Display_Per_Acc();
			getch();
			system("cls");
			goto checkpoint;
		}
		else if(number==3)
		{
			Display_Per_Name();
			getch();
			system("cls");
			goto checkpoint;
		}


		else if(number==4)
		{
			Display_per_Balance();
			getch();
			system("cls");
			goto checkpoint;
		}



		else if(number==5)
		{
			Delete_Record();
			getch();
			system("cls");
			goto checkpoint;
		}


		else if(number==6)
		{
			Update_Record();
			getch();
			system("cls");
			goto checkpoint;
		}


		else if(number==7)
		{
			Search_Per_Acc();
			getch();
			system("cls");
			goto checkpoint;
	
		}


		else if(number==8)
		{
			Search_Per_Name();
			getch();
			system("cls");
			goto checkpoint;
		
		}


		else if(number==9)
		{
	
			Withdraw();
			getch();
			system("cls");
			goto checkpoint;
		}


		else if(number==10)
		{
			Credit();
			getch();
			system("cls");
			goto checkpoint;
		}
		else if(number == 11)
		{
			exit(0);	
		}

		else if(( number > 11) || (number <= 0) )
		{
			printf("Please type a number that corresponds with the options\n\n");
			goto checkpoint;
		}

		getch();
	
}