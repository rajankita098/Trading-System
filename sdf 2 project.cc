#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
#include<conio.h>


using namespace std;

// Class created for binding
class Account
{
public:

    // Basic Variables declared
    int dogecoin=2000;
    int balance=50000;
    int bitcoin=1000;
    int my_dogecoin=0;
    int my_bitcoin=0;
    int deposit, withdraw;
    int total_equity = 100;
    int predict;
    int dogecoin_value=100;
    int bitcoin_value=200;
    int crypto_invest;
    int crypto_return;

    // Deposit Cash
     Account operator +(int deposit)
    {
        cout<<"enter ammout u want to deposite"<<endl;
        cin>>deposit;

        fstream file;
        balance=balance+deposit;
        cout << "deposite Amount = "<<deposit<<endl;
        cout<<"current balance is "<<balance<<endl;
        file.open("sdf2.txt",ios::app | ios::out);
        file<<"current balance = "<<balance<<"   "<<"deposit ammout = "<<deposit<<"\n";
        file.close();
        file>>balance;

    }


    // Withdraw Cash
    Account operator - ( int  withdraw)
    {
        cout<<"enter ammout u want to withdraw"<<endl;
        cin>>withdraw;

        fstream file;
        if (withdraw > balance) {
            cout<<"insfficient balance"<<endl;
        }

        balance=balance-withdraw;
        cout << "withdrawn Amount = "<<withdraw<<endl;
        cout<<"current balance is "<<balance<<endl;
        file.open("sdf2.txt",ios::app | ios::out);
        file<<"current balance = "<<balance<<"   "<<"withdraw ammout = "<<withdraw<<"\n";
        file.close();


    }

    // Buy Crypto function
    void buy()
    {
        int option;
        cout << "Want to purchase dogecoin press 1 else "
                "for bitcoin press 2\n";
        cin >> option;

        if(option==1)
        {
            int no_dg;
            cout<<"enter no. of dogecoin u want to buy"<<endl;
            cin>>no_dg;

            if(no_dg*dogecoin_value>balance)
            {
                cout<<"insufficient balance"<<endl;
            }

            else
            {
                my_dogecoin=no_dg;
                dogecoin=dogecoin-no_dg;
                balance=balance-no_dg*dogecoin_value;
                dogecoin_value=dogecoin_value+2*no_dg;
                cout<<" current value of dogecoin is "<<dogecoin_value<<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }

        }

        if(option==2)
        {
            int no_bt;
            cout<<"enter no. of bitcoin u want to buy"<<endl;
            cin>>no_bt;

            if(no_bt*bitcoin_value>balance)
            {
                cout<<"insufficient balance"<<endl;
            }
            else
            {
                my_bitcoin=no_bt;
                bitcoin=bitcoin-no_bt;
                balance=balance-no_bt*bitcoin_value;
                bitcoin_value=bitcoin_value+2*no_bt;
                cout<<"value of bitcoin is "<<bitcoin_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }
        }
    }

    // Selling crypto function
    void sell()
    {
        int option;
        cout << "Want to sell dogecoin press 1 else for "
                "bitcoin press 2\n";
        cin >> option;

        if(option==1)
        {
            int no_dg;
            cout<<"enter no. of dogecoin u want to sell"<<endl;
            cin>>no_dg;

                my_dogecoin=my_dogecoin-no_dg;
                dogecoin=dogecoin+no_dg;
                balance=balance+no_dg*dogecoin_value;
                dogecoin_value=dogecoin_value+2*no_dg;
                cout<<"value of dogecoin is "<<dogecoin_value<<endl;
                cout<<"current a/c balance is "<<balance<<endl;


        }

        if(option==2)
        {
            int no_bt;
            cout<<"enter no. of bitcoin u want to buy"<<endl;
            cin>>no_bt;

                my_bitcoin=my_bitcoin-no_bt;
                bitcoin=bitcoin+no_bt;
                balance=balance+no_bt*bitcoin;
                bitcoin_value=bitcoin_value-2*no_bt;
                cout<<"value of bitcoin is "<<bitcoin_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
        }


    }
    void Get_account_information()
    {
        fstream file;

        cout << "Money Details:\n";
        cout << "Bank Balance:" << balance << endl;
        cout << "Dogecoin:" << my_dogecoin << endl;
        cout << "Bitcoin:" << my_bitcoin << endl;
        file.open("sdf2.txt",ios::app|ios::out);
        file<<"dogecoin = "<<my_dogecoin<<"   "<<" bitcoin = "<<my_bitcoin<<" current balance = "<<balance<<endl;
        file.close();
    }

    void check_crypto_value()
    {
        fstream file;
         cout<<"value of dogecoin is "<<dogecoin_value<<endl;
         cout<<"value of bitcoin is "<<bitcoin_value <<endl;
        file.open("sdf2.txt",ios::app|ios::out);
        file<<"dogecoin value = "<<dogecoin_value<<"  "<<"bitcoin value = "<<bitcoin_value<<"  "<<endl;
        file.close();


    }
};

class stock : public Account
{
public:
   int no_stock=1000;
   int stock_value=150;
    int my_stock;

    void buy()
    {
        int no_stock_b;
         cout<<"enter no. of stock u want to buy"<<endl;
            cin>>no_stock_b;

            if(no_stock_b*stock_value>balance)
            {
                cout<<"insufficient balance"<<endl;
            }

            else
            {
                my_stock=no_stock_b;
                balance=balance-my_stock*stock_value;
                stock_value=stock_value+2*no_stock_b;
                cout<<"value of stock is "<<stock_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }

    }

    void sell()
    {
         int no_stock_s;
            cout<<"enter no. of stock u want to sell"<<endl;
            cin>>no_stock_s;

            if(no_stock_s>my_stock)
            {
                cout<<"insufficient no. of stock"<<endl;
            }
            else
            {
                my_stock=my_stock-no_stock_s;
                balance=balance+no_stock_s*stock_value;
                stock_value=stock_value-2*no_stock_s;
                cout<<"value of stock is "<<stock_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }
    }

    void check_stock_value()
    {
        fstream file;
        cout<<"current value of stock market is "<<stock_value<<endl;
        file.open("sdf2.txt",ios::app|ios::out);
        file<<"current stock value = "<<stock_value<<endl;
        file.close();

    }

};



int main()
{
    cout<<endl;
    cout<<"                                            ONLINE TRADING SYSTEM"<<endl;
    cout<<"________________________________________________________________________________________________________________________"<<endl;
    char password[11], username[] = "rajankita@", us[11], ch;
    int i = 0;
    bool isincorrect;
    while((isincorrect == false) )
    {
        cout << "                                               Enter username: ";
        cin >> us;
        if(strcmp(username, us) == 0)
        {
            cout << "                                               Enter password: ";
            isincorrect = true;
            for(i = 0; i < 10; i++)
            {
                ch = getch();
                if(ch == 13)
                {
                    password[i] = '\0';
                    break;
                }
                else
                {
                    password[i] = ch;
                    cout << "*";
                }
            }
            if(strcmp(password, "ankita") == 0)
            {
                cout << "\nLogin successful\n";

    Account *person=new stock;
    Account obj;
    stock p;
    //person=&p;
    int amount, choice,n;
    while (n)
    {

        cout <<"NOW MANAGE YOUR ACCOUNT AT YOUR OWN PACE"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

        cout << endl;
        cout << "Press 1 if want to have your Account Info "
             << endl;
        cout << "Press 2 if want to Deposit your money "
             << endl;
        cout << "Press 3 if want to withdraw your money "
             << endl;
        cout << "Press 4 if want to know your Buy Crypto/stock "
             << endl;
        cout << "Press 5 if want to know your Sell Crypto/stock "
             << endl;
        cout << "press 6 to current crypto and stock market"
             <<endl;
        cout << "Else press any invalid key for exit \n"
             << endl;

        cout << "  "
                "**"
                "*  \n";

        cin >> choice;

        switch (choice)

    {
        case 1:
            person->Get_account_information();
            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
            cin>>n;


        case 2:
             obj + (amount);

            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
        cin>>n;


        case 3:
             obj - (amount);
            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
        cin>>n;


        case 4:
              person->buy();
            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
        cin>>n;


        case 5:
              person->sell();
            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
        cin>>n;

        case 6:
            person->check_crypto_value();
            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
        cin>>n;


        case 7:
            p.check_stock_value();
            break;
            cout<<"Do u want to continue or exit 1/0"<<endl;
        cin>>n;

        }

}


            }
            else
            {
                cout << "\nWrong password\n";
            }
        }
        else
        {
            cout << "Wrong username\n";
        }
        i++;
    }



    return 0;
}

