/**
 * Created by petru on 28-Oct-15.
 */


public class CreditCard
{
    private long _ccNum;        // 8 bytes
    private double _balance;    // 8 bytes

    public CreditCard() {
        // do nothing
    }

    public CreditCard(long ccNum, double balance) {
        _ccNum = ccNum;
        _balance = balance;
    }


    public void setCreditCardNumber(long ccNum) {
        _ccNum = ccNum;
    }

    public long getCreditCardNumber() {
        return _ccNum;
    }

    public void setBalance(double balance) {
        _balance = balance;
    }

    public double getBalance() {
        return _balance;
    }
}
