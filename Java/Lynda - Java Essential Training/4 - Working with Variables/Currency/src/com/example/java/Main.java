package com.example.java;

/**
 * Created by petru on 08-Sep-15.
 */


import java.math.BigDecimal;


public class Main {

    public static void main(String[] args) {

        double value = .012;

        double primSum = value + value + value;

        System.out.println("Sum of primitives: " + primSum);

        String strValue = Double.toString(value);
        System.out.println("strValue: " + strValue);

        // BigDecimal is specifically designed to take care
        // of the precision problem
        BigDecimal bigValue = new BigDecimal(strValue);

        BigDecimal bigSum = bigValue.add(bigValue).add(bigValue);

        System.out.println("Sum of bigDecimals: " + bigSum.toString());

    }

}
