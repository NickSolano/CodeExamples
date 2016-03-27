// Nicholas Solano Workout Program!
//Assignment #1 COMP 150 Leon Pan 2015/11/27
//Student ID - 300136694
/*      
 * AUTHOR:  Nicholas SOlano
 *
 * CONTACT INFORMATION:nicksolano96@gmail.com
 *
 * CREATION DATE:  22/11/2015
 *
 * PROBLEM STATEMENT:  To allow the user to input,save,sort,display their daily workout as well as open previous workout routines.
 * 
 * PROGRAM DESCRIPTION:   My program gives the user the capability to record their daily workout
 *                        I have multiple functions including , input, savefile, openfile, display file, display file
 *                        I have set up restrictions and error messages as well to prevent unambiguious errors
 *						  I am hoping to maybe make an android app for myself applying the syntax i've learned!	
 *
 * RUN INSTRUCTIONS: 	
 	1 - Enter the Date of Your Workout - Here you can enter the date of your exercise don't enter multiple dates, this program handles one day at a time.
	2 - Enter an exercise - Enter your exercises as many as you want , use whatever name suits you. You also can enter the sets, reps and weight.
	3 - Sort the names of your exercises - This will sort the name of the exercises in alphabetical order that way its more organized
	4 - Delete an exercise - You must enter a name that you desire, workout routine for that day will be deleted
	5 - Display your wokrout -  Here you select a workout and delete it
	6 - Save and name file - You can put in the desired name for the workout, **Remember the  txt file saves to directory of the programs location**
	7 - Open File - You can open a previous file, and use the display function to see the workout routine from previous days ! :)
	8 - Quit - Can either type quit or select number  8 to end the program.
 */

#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

struct workout{
	
	string name;
	string weight;
	string sets;
	string reps;
};

void getDates(vector<string>& dates);
void inputData(vector<workout>& workouts);
void saveFile(ofstream& fout,vector<workout>& workouts,vector<string>& dates);
void openFile(ifstream& fin, vector<string>& dates, vector<workout>& workouts);
void displayWorkout(vector<workout>& workouts);
void display(vector<string>& dates);
void sort(vector<workout>& workouts);
void removeName(vector<workout>& workouts, string& x);
const int MAXINPUT = 10;
const int DATE = 1;

int main()
{
	
	vector<string> date;
	vector<workout> data;
	string x;
	int indexworkout = data.size();
	int indexdate = date.size();	
	int option;
	
		do{
	//This is my Menu that I use to call functions too
	// I used if else, because I thought it was better being able to set conditions
	//And because I prefer it , but I could have also used a switch case for the menu.
	cout<<"*** === NICHOLAS *** SOLANO == ***\n";
	cout<<"*** RECORD YOUR WORKOUT V1.0 ***\n";
	cout<<"***Input the number you wish to operate a desired task***\n";
	cout<<endl;
	cout<<"1 - Enter the Date of Your Workout \n";
	cout<<"2 - Enter an exercise \n";
	cout<<"3 - Sort the names of your exercises \n";
	cout<<"4 - Delete an exercise \n";
	cout<<"5 - Display your wokrout \n";
	cout<<"6 - Save and name File\n";
	cout<<"7 - Open File\n";
	cout<<"8 - Quit"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n";
	cin>> option;
	if(option == 1){
	system("cls");
	getDates(date);
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\n";
	}
	else if ( option == 2){
	system("cls");
	inputData(data);
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\n";
	}
	else if (option == 3){
	system("cls");
	sort(data);
	cout<<"\n";
	cout<<"\n";
	}
	else if (option == 4){
	system("cls");
	removeName(data,x);
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\n";
		}
	else if (option == 5){
	system("cls");
	display(date);
    cout<<"S= sets | R= reps | lbs = pounds\n";
    cout<<"\n";
	displayWorkout(data);
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\n";
	}	
	else if( option ==6 )
	{
	system("cls");
	ofstream fout;
	saveFile(fout,data,date);
	cout<<"\n";
	cout<<"*****Your file has been saved.*****\n";
	cout<<"\n";
		
	}
	else if (option == 7){
	ifstream fin;
	system("cls");
	openFile(fin,date,data);
	
	}
	else if(option == 8){
	return 0;
	}
	else {
		break;
	}
    }while(option!=8);

}

void inputData(vector<workout>& workouts)
{
	/*
 * TASK:     You can input the your workout
 
 * ACCEPTS:  Accpets a string of values. Since there is no real calculations being done,
 			 to make the programmore simple it was easier to use string for each struct variable.
 			 
 * RETURNS:  The values of the struct are passed by reference , through the variable input
 			 Then it is stored in the vector "workouts" where the multiple strings in the struct are stored in each individual index of the vector.
 			 
 * MODIFIES: Here it modifies the values of the struct workout then it is stored in the vector.
 			 The reason we use pass by reference and not pass by value is because we will need to carry these values, BUT be able to change them
 			 as we want to enter multiple ecercises. If it was pass by value, we could strictly only that that single value and not have the ability to store
 			 multiple workouts.
 */

	workout input;
	int index= workouts.size();
	int step=0;
	while(step<4){ //Here I set up a while loop condition to ensure the program only allows user to put in one exercise at a time.
				  //I thought this was a benefital way making the progam more sequential.
	cout<<"Please enter the name of your workout exercise, quit to exit:  \n";
	cin.ignore();
	getline(cin,input.name);
	step++;
	cout<<"Enter the number of sets you want to complete \n";
	cin>>input.sets;
	step++;
	cout<<"Enter the number of reps you want to complete \n";
	cin>>input.reps;
	step++;
	cout<<"Enter the amount of weight you are lifting (lbs) \n";
	cin>>input.weight;
	cin.ignore(1); // Ignores null character
	workouts.push_back(input); //Inputs each struct variable into the vector
	step++;
	}

}

void getDates(vector<string>& dates)
{
		/*
 * TASK:     You can input the date
 
 * ACCEPTS: Here we can accept ONE date, it wouldn't make sense to enter multiple dates so when this program
 			eventually saves the file it will only store the value of the first index in reality and wont save
 			multiple dates, this way we can disregard human error, of people entering multiple dates.
 			 
 * RETURNS:  Returns the string value of date
 			 
 * MODIFIES: We use pass by reference for the vector <string> dates because it is the simpilest way 
 		     to carry a vlaue nad call it to my main function
 			 in the menu option
 */

	string date;
	cout<<"Enter your the date of your workout ie. 'Feburary 21st 2015' :   ";
	cin.ignore();
	getline(cin,date);
	dates.push_back(date);	
}
	
void sort(vector<workout>& workouts)
{
/*
 * TASK:  Sorts the names of the workouts in alphabetical order.
 
 * ACCEPTS: None.
 			 
 * RETURNS:  Returns the struct string name stored in the vector in alphabetical order.
 			 
 * MODIFIES: Uses pass by reference that way we can pass the values throughout the function in order
 			 And this way we can sort them and it will update the vlaues in the index in alphabetical order
 			because we use pass by reference.
 */
	int n=workouts.size();	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			
			if(workouts[j].name>workouts[j+1].name){//Condition set to sort names in alphabetical order
				swap(workouts[j].name, workouts[j+1].name);
				swap(workouts[j].sets, workouts[j+1].sets);
				swap(workouts[j].reps, workouts[j+1].reps);
				swap(workouts[j].weight, workouts[j+1].weight);
				} //Sorts names in alphabetical order while carrying the values of sets , reps and weight WITH the names so it doens't get messed up.
		
		}
		
}
}




void saveFile(ofstream& fout, vector<workout>& workouts,vector<string>& dates)
{
			/*
 * TASK:     Allows user to save their workout with a desired name.
 
 * ACCEPTS: Doesn't accept any values.
 			 
 * RETURNS: Doesn't return values, but calls values inputted by user that are passsed by reference and stored in the vector.
 			 
 * MODIFIES: There is no values inside this function that are passed by reference... BUT we do call values stored in the struct
 			 that are passed by reference.
 */
	
	int n=workouts.size();
	int x=dates.size();
	int step=0;
	string fileName;
	cout<<"Enter the file name:  "; // Allows the user to enter a desired name.
	cin.ignore(); // If we don't getline -  the program will skip getline and won't allow the user to input their name.
	getline(cin,fileName);
	fileName += ".txt"; // Adds .txt automatically to the file name that way it will always save as a txt file.
	fout.open(fileName.c_str(),ios::app); //Opens the file of the desired name that was assigned to the txt file.
	
	for(int i=0; i<x; i++) //itterates through each index of the vector and prints accordingly.
	{
		fout<<dates[i]<<";"<<endl;
		if(i<x-1) // Doesn't go beyond its means.
			fout<<endl;
		for(int j=0; j<n; j++){
		fout<<workouts[j].name<<";";
		fout<<workouts[j].sets<<"S"<<";";
		fout<<workouts[j].reps<<"R"<<";";
		fout<<workouts[j].weight<<"lbs"<<";\n";
		if(i<n-1)
			fout<<endl;
		}
		
	
		fout.close(); //closes file
	}
}



void openFile(ifstream& fin, vector<string>& dates, vector<workout>& workouts)
{
			/*
 * TASK:     You can input the date
 
 * ACCEPTS: Here we can accept ONE date, it wouldn't make sense to enter multiple dates so when this program
 			eventually saves the file it will only store the value of the first index in reality and wont save
 			multiple dates, this way we can disregard human error, of people entering multiple dates.
 			 
 * RETURNS:  Returns the string value of date
 			 
 * MODIFIES: We use pass by reference for the vector <string> dates because it is the simpilest way 
 		     to carry a vlaue nad call it to my main function
 			 in the menu option
 */
	
	workout info;
	string filename;
	string str;
	cout<<"Enter a file name to open:  "; // Can select a name of the file you wana save.
	cin.ignore();
	getline(cin,filename);
	filename += ".txt"; //Autmatically reviews file name with a .txt
	fin.open(filename.c_str());
	if(fin.fail()){
			cerr<<"ERROR: File cannot be opened \n"; //Error message
			cout<<"Either the file doens't exist or the name is wrong.\n";
			system("pause");// Allows user to sort of see what happened and just pauses the screen for a sec.
			system("cls");//
	}
	else {
		cout<<" Opening file..."<<endl;
		dates.clear(); // Clears vector that way it doens't mix up data of previos entered data.
		workouts.clear(); //Clears the vector that way it doesn't mix data up of previos entered data
		while(!fin.eof())//Allows us to itterate through the text file till there is no more data.
		{
			// Takes information from the desired text file and inputs it into the vector
			
		getline(fin,str,';');
		getline(fin,info.name,';');
		getline(fin,info.sets,';');
		getline(fin,info.reps,';');
		getline(fin,info.weight,';');
		dates.push_back(str);// pushes values of dates into vector
		workouts.push_back(info); //pushes values of struct into vector
		}
		cout<<"Successfully Opened to Display Contents select Display option on main menu\n";
	}
	}


void display(vector<string>& dates)
{
/*
 * TASK:  Displays dates
 
 * ACCEPTS: None
 			 
 * RETURNS:  None
 			 
 * MODIFIES: Dates the values of dates and itterates through the vector displaying the date.
 */
	int n=dates.size();
	for(int i=0; i<n; i++) //itterates through the vector using the forloop.
	{
		cout<<dates.at(i)<<endl;
		cout<<"\n";
	
	}
	
}
void displayWorkout(vector<workout>& workouts)
{
			/*
 * TASK:     Itterates through the vector of workouts and displays the workout.
 
 * ACCEPTS: None
 			 
 * RETURNS:  None
 			 
 * MODIFIES: Calls the values sotre in the vector workouts. It's a struct so we select each individual string inside the struct.
 */
	int n=workouts.size(); //So we doens't go past the size of the vector giving an error..
	for(int i=0; i<n;i++){
		cout<<workouts[i].name<<'\t'<<workouts[i].sets<<"S"<<'\t'<<workouts[i].reps<<"R"<<'\t'<<workouts[i].weight<<"lbs"<<endl;
	}
}


void removeName(vector<workout>& workouts, string& x)
{
			/*
 * TASK:     Removes a workout from the desired wrokoutdate.
 
 * ACCEPTS: This program accepts a string that is passed by reference
 			 
 * RETURNS:  Returns a value by deleting a name inside the struct
 			 
 * MODIFIES: The program uses pass by reference to compare the string that is entered
 			 With any of the names inside the vector
 			 If the value is inside the vector, it will be succesfully remvoed along with the sets reps and weight.
 			 You can remove a name digitally.
 */
	bool found = false; //Set up a boolean condition.
	cout<<"Type a name of a workout you want to delete: "; //Types the name of a workout that you wana remove.
    cin>>x;
        for (int i=0; i<workouts.size(); i++) {//Itterates through the size of the vector not going past its parameters.
             if (x == workouts.at(i).name) {  //Sets condition that IF input is = a namestored inside the vector display the following.
			 cout<<"\n"; //finds the name by comparing it to each names in the vector list.
             cout<<"You have removed the name:  "<<workouts.at(i).name<<endl;   //name printed if found.
             workouts.erase(workouts.begin()+i); // Deletes and removes the vector moving everything back one space, so there are no empty indexs within.
             									// the size of the vector.
             found = true;
             break;
        	} 
    	 }  
     if (found == false) cout<<"Name not found"<<endl; //If the condition is false name isn't found go back to main menu.
}
