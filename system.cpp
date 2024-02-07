#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    int a,i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string  creds[2],cp[2];
    cout<<"               Security System "<<endl;
    cout<<"______________________________________________\n";
    cout<<"|            1. Register                      |\n";
    cout<<"|            2. Login                         |\n";
    cout<<"|            3. Change Password               |\n";
    cout<<"|____________4. End Program___________________|\n\n";
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;
        switch (a) {
            case 1:
            {
                cout<<"______________________________________________\n\n";
                cout<<"|---------------Register----------------------|\n";
                cout<<"|_____________________________________________|\n\n";
                cout<<"Please enter username:- ";
                cin>>name;
                cout<<"\nPlease enter the password:- ";
                cin>>password0;
                cout<<"\nPlease enter your age:- ";
                cin>>age;
                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    cout<<"Registration successfull"<<endl;
                }

                break;
            }
            case 2:
            {
                i=0;
                cout<<"______________________________________________\n\n";
                cout<<"|------------------Login----------------------|\n";
                cout<<"|_____________________________________________|\n\n";
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:- ";
                cin>>user;
                cout<<"Please enter the password:- ";
                cin>>pass;
                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2,text))
                        {
                            istringstream iss(text);
                            iss>>word;
                            creds[i++]=word;
                        }
                        if(user==creds[0] && pass==creds[1])
                        {
                            cout<<"---Login Successfull---";
                            cout<<endl<<endl;
                            cout<<"Details: "<<endl;
                            cout<<"Username: "<<creds[0]<<endl;
                            cout<<"Password: "<<creds[1]<<endl;
                            cout<<"Age: "<<age<<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|    1. Press 2 to Login              |"<<endl;
                            cout<<"|    2. Press 3 to Change Password    |"<<endl;
                            break;
                        }
                    }

                }

                break;
            }
            case 3:
            {
                i=0;
                cout<<"------------------Change password----------------"<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password:- ";
                cin>>old;
                if(of0.is_open())
                {
                    while(!of0.eof())
                    {
                        while(getline(of0,text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i++]=word1;
                        }
                        if(old==cp[1])
                        {
                            of0.close();
                            ofstream of1;
                            if(of1.is_open()) {
                                cout << "Enter your new password:- ";
                                cin >> password1;
                                cout << "Reenter your new password again:- ";
                                cin >> password2;
                                if (password1 == password2) {
                                    cp[1] = password1;
                                    of1 << cp[0] << endl;
                                    of1 << password1;
                                    cout << "Password changes successfully" << endl;
                                } else {
                                    of1 << cp[0] << "\n";
                                    of1 << old;
                                    cout << "Password do not match" << endl;
                                }
                            }
                        }
                        else{
                            cout<<"Please enter a valid password"<<endl;
                            break;
                        }

                    }

                }

                break;
            }
            case 4:
            {
                cout<<"__________Thank you!_________"<<endl;
                break;
            }
            default:
            {
                cout<<"Enter the valid choice 1-4?"<<endl;
            }
        }
    }
    while(a!=4);
    return 0;
}

