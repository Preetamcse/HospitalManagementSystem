#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Hospital{
private:
    string Name, Address, BGroup;
public:
    Hospital():Name(""), Address(""), BGroup(""){}

    void setName(string name){
        Name = name;
    }

    void setAddress(string address){
        Address = address;
    }

    void setBGroup(string group){
        BGroup = group;
    }

    string getName(){
        return Name;
    }

    string getAddress(){
        return Address;
    }

    string getBGroup(){
        return BGroup;
    }
};

void admit(Hospital& patient){
    system("cls");
    string name, address, group;

    cout<<"\tEnter Name Of Patient: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    patient.setName(name);

    cout<<"\tEnter Address Of Patient: ";
    getline(cin, address);
    patient.setAddress(address);

    cout<<"\tEnter Blood Group Of Patient: ";
    getline(cin, group);
    patient.setBGroup(group);

    // Fixed file path with proper escape characters
    ofstream outfile("C:\\Users\\preet\\OneDrive\\Desktop\\HospitalManagementSystem.txt", ios::app);
    if(!outfile){
        cout<<"\tError: File Can't Open!"<<endl;
    }
    else{
        outfile<<"\t"<<patient.getName()<<" : "<<patient.getAddress()<<" : "<<patient.getBGroup()<<endl<<endl;
        cout<<"\tPatient Admitted!"<<endl;
    }
    outfile.close();
    Sleep(3000);
}

void discharge(){
    system("cls");
    string name;
    cout<<"\tEnter Name of Patient: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    // Consistent file paths
    ifstream infile("C:\\Users\\preet\\OneDrive\\Desktop\\HospitalManagementSystem.txt");
    ofstream outfile("C:\\Users\\preet\\OneDrive\\Desktop\\Hospital Temp.txt");
    if(!infile || !outfile){
        cout<<"\tError: File Can't Open!"<<endl;
    }
    else{
        string line;
        bool found = false;

        while(getline(infile, line)){
            // Need to check if the line contains the patient name, not just starts with it
            if(line.find(name) != string::npos){
                found = true;
                cout<<"\tPatient Discharged!"<<endl;
                // Skip this line by not writing it to output file
            }
            else{
                outfile<<line<<endl;
            }
        }
        if(!found){
            cout<<"\tIncorrect Name!"<<endl;
        }
    }
    outfile.close();
    infile.close();
    
    // Fixed file paths for consistency
    remove("C:\\Users\\preet\\OneDrive\\Desktop\\HospitalManagementSystem.txt");
    rename("C:\\Users\\preet\\OneDrive\\Desktop\\Hospital Temp.txt", 
           "C:\\Users\\preet\\OneDrive\\Desktop\\HospitalManagementSystem.txt");
    Sleep(3000);
}

int main(){
    Hospital patient;

    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tHospital Management System"<<endl;
        cout<<"\t**************************"<<endl;
        cout<<"\t1.Admit Patient."<<endl;
        cout<<"\t2.Discharge Patient."<<endl;
        cout<<"\t3.Exit."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>val;

        if(val==1){
            admit(patient);
        }

        else if(val==2){
            discharge();
        }

        else if(val==3){
            system("cls");
            exit = true;
            cout<<"\tGood Luck!"<<endl;
            Sleep(3000);
        }
    }
    return 0;
}