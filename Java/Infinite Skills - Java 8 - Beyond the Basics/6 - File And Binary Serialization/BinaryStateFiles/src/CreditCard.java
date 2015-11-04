import java.io.Serializable;

/**
 * Created by petru on 28-Oct-15.
 */

// The serialization interface has no methods or fields and serves only to identify the semantics of being serializable.

public class CreditCard implements Serializable
{
    // By serializing CreditCard we'll not gonna have to worry about sizes anymore.
    // We'll be able to save the entire object as a bytecode.
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

    public String toString() {
        return ("Credit Card Number: " + _ccNum + "  Balance: " + _balance);
    }
}
