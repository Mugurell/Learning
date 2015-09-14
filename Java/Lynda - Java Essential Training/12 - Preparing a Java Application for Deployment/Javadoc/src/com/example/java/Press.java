package com.example.java;

import com.example.java.model.Olive;

import java.util.List;


public interface Press {

    // any class that implements this interface must have this method
    public int getOil(List<Olive> olives);

    public void setOil (int oil);

}
