#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsTransferScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with[" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount?";
        Amount = clsInputValidate::ReadFloatNumber();
        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t Transfer Screen");
        cout << "\nPlease enter AccountNumber to transfer From?";
        string AccountNumber1 = _ReadAccountNumber();

        clsBankClient SourceClient = clsBankClient::Find(AccountNumber1);
        _PrintClient(SourceClient);

        cout << "\nPlease enter AccountNumber to transfer to?";
        string AccountNumber2 = _ReadAccountNumber();

        clsBankClient DestinationClient = clsBankClient::Find(AccountNumber2);
        _PrintClient(DestinationClient);


        float Amount = ReadAmount(SourceClient);
    

        cout << "\nAre you sure you want to perform this transaction? y/n? ";
        char Answer = 'n';
        cin >> Answer;


        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};

