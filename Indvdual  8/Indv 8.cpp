//  FCI _Object oriented design and Analysis ( programming 2 )  _ 2018 - Assignment 1
/// Problem 6 page 536 In Problem Solving with C++ 9th Edition Book
//  Last Modification Date: 9/10/2018
/// Author : Abdelrahman Mohamed Ahmed Mahmoud
/// ID : 20170148 --- Group: 6
///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;
typedef string DArray;
// Functions Declaration
string AddEntry(string a[], int size, string NewEntry);
string DeleteEntry(string a[],int size, string Entry_to_delete);
int main ()
{   int size;
	cout<<"Enter the Array size..."<<endl;           // asking the user for the array size
	cin>> size;                                      // the user Enters the size of array
	DArray* a=new DArray [size];                     // creating the dynamic array
	for(int i=0;i<size;i++){cin>>a[i];}              // for loop for taking the words in araay
	for(int i=0;i<size;i++){cout<<a[i]<<"   ";}      // showing the taken words in the array to the user

	while (true)                                     // showing the options for the user to choose form to add or delete word form the array or stop the program
	{   int y;
		cout<<" \n Choose from the following... \n"<<" 1- Add a word to the array \n"
		    <<" 2- Delete a word from the array \n"<<" 3- Stop the program "<<endl;
		cin>>y;
		if(y==1)                                     // if he want to add choose 1 , he is going to enter the new word
        {   string Newword;
			cout<<"Enter the new word"<<endl;
			cin>>Newword;
			cout<<AddEntry (a,size,Newword);
		}
		else if(y==2)                                // if he want to add choose 2 , he is going to delete a word from the array
		{   string Delete;
			cout<<"Enter a word to delete"<<endl;
			cin>>Delete;
			cout<<DeleteEntry(a,size,Delete);
		}
		else{                                        // if the user enter any another keys , the program will stop working and inform him
         cout<<"The program stopped Working :("<<endl;
		 break;
		}
	}
	delete [] a;
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////// AddEntry Function Definition
string AddEntry(string a[], int size, string NewEntry){
	string* b=new string[size+1];                    // creating a new dynamic array one element larger than dynamicArray
	for(int i=0;i<size+1;i++)
	{   if(i==size){b[i]=NewEntry;}
		else{b[i]=a[i];}
	}
	for(int i=0;i<size+1;i++)                        // copying all elements from dynamicArray into the new array
	{   cout <<"The new array =   " <<b[i]<<"  ";    // adding the new entry onto the end of the new array
	}
	return *b;                                       // returning the new dynamic array
	delete []a;                                      // delete dynamicArray
	delete b;
}
/////////////////////////////////////////////////////////////////////////////////////// DeleteEntry Function Definition
string DeleteEntry(string a[],int size, string Entry_to_delete){
    string* b=new string[size];                      // create a new dynamic array
    for(int i=0;i<size;i++){
    if(a[i]==Entry_to_delete){a[i]=" ";}             // searching dynamicArray for entryToDelete
    }
    for(int j=0;j<size;j++){                         // Copy all elements except entryToDelete into the new array
    b[j]=a[j];
    }
    for(int i=0;i<size;i++){
    cout <<"The new array =   " <<b[i]<<"  ";
    }
    delete []a;                                       // delete dynamicArray and decrementing size
    return *b;                                        // returning the new dynamic array
    delete b;





}
