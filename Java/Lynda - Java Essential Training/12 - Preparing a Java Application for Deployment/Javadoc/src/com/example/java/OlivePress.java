package com.example.java;


import com.example.java.model.Olive;

import java.util.List;


public class OlivePress implements Press {

    private int currentOil;

    public int getOil(List<Olive> olives) {

        int totalOil = currentOil;

        for (Olive o : olives) {
            totalOil += o.crush();
//            System.out.println(o.getName());
        }

        return totalOil;

    }

    @Override
    public void setOil(int oil) {
        currentOil = oil;
    }

}
