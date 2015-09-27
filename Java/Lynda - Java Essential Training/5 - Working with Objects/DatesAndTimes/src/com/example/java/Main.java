/**
 * Created by petru on 08-Sep-15.
 */


/*
Java 8 brought a new API !!!
 */


package com.example.java;

import java.text.DateFormat;
import java.time.LocalDate;
import java.time.LocalDateTime;     // new date API
import java.time.format.DateTimeFormatter;
import java.util.Date;              // old date API
import java.util.GregorianCalendar;

public class Main {

    public static void main(String[] args) {

        // in this way we can use a Date object
        // to represent the current moment in time
        Date d = new Date();
        System.out.println(d);

        // to represent a specific date
        // we instantiate gc with 2009, february, 28
        GregorianCalendar gc = new GregorianCalendar(2009, 1, 28);
        // add 1 to the date
        gc.add(GregorianCalendar.DATE, 1);
        Date d2 = gc.getTime();
        System.out.println(d2);

        // format the date to a specific style
        DateFormat dF = DateFormat.getDateInstance(DateFormat.FULL);
        System.out.println(dF.format(d2));


    /*
    About the new API now..
    */
        LocalDateTime ldt = LocalDateTime.now();
        // will print in UNIX time stamp
        System.out.println(d2);

        // in the old API month numbering went from 0 to 11
        // in the new one month numbering goes from 1 to 12
        LocalDate ld = LocalDate.of(2009, 1, 28);
        System.out.println(ld);

        DateTimeFormatter dtf1 = DateTimeFormatter.ISO_DATE;
        System.out.println(dtf1.format(ld));

        DateTimeFormatter dtf2 = DateTimeFormatter.ofPattern("d/MM/yyyy");
        System.out.println(dtf2.format(ld));

    }

}
