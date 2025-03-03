/*Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 months to repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0 - 0.5% */

#include <iostream>
using namespace std;

class LoanHelper
{
private:
    const float interestRate;
    double amount;
    int months;
    double monthlyReturn;
    double loan;

public:
    LoanHelper(float rate, double amo, int mon) : interestRate(rate), amount(amo), months(mon) {}

    void LoanRepayment()
    {
        monthlyReturn = amount / months;
        double interest = monthlyReturn * interestRate;
        loan = monthlyReturn + interest;
    }

    double getLoan() const
    {
        return loan;
    }

    double getMonthlyReturn() const
    {
        return monthlyReturn;
    }

    double getAmount() const
    {
        return amount;
    }

    double getMonths() const
    {
        return months;
    }

    void setAmount(double am)
    {
        amount = am;
    }
    void setMonths(double mon)
    {
        months = mon;
    }
};

int main()
{
    float rate;
    do
    {
        cout << "Enter interest rate: ";
        cin >> rate;
    } while (rate < 0 || rate > 0.5);

    LoanHelper l1(rate, 50000, 12);
    l1.LoanRepayment();
    cout << "You have to pay " << l1.getLoan() << " every month for " << l1.getMonths() << " months to repay your loan" << endl;

    return 0;
}
