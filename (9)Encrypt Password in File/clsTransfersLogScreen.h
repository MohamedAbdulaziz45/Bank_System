#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

class clsTransfersLogScreen:protected clsScreen
{
private:
    static void PrintTransferLoginRecordLine(clsBankClient::stTransferLogRecord TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLog.destBalanceAfter;
        cout << "| " << setw(8) << left << TransferLog.UserName;
    }

public:
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTransferLogRecord>vTransfersLogRecord
             = clsBankClient::GetTransferLoginList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransfersLogRecord.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(23) << left << "Date/Time";
        cout << "| " << setw(8) << left << "s.Acct";
        cout << "| " << setw(8) << left << "d.Acct";
        cout << "| " << setw(8) << left << "Amount";
        cout << "| " << setw(10) << left << "sBalance";
        cout << "| " << setw(10) << left << "dBalance";
        cout << "| " << setw(8) << left << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vTransfersLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";

        else

            for (clsBankClient::stTransferLogRecord Record : vTransfersLogRecord)
            {

                PrintTransferLoginRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

