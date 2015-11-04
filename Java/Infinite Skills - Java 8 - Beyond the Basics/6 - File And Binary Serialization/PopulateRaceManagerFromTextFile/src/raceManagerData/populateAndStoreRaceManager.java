package raceManagerData;

import raceManagerObjects.Athlete;
import raceManagerObjects.Biker;
import raceManagerObjects.Runner;
import raceManagerObjects.Swimmer;

import java.io.*;
import java.util.ArrayList;


/**
 * Created by petru on 27-Oct-15.
 */


public class populateAndStoreRaceManager
{
    /**
     * get the Athletes out of a flat text file.
     * @param path the path of the data file.
     * @return an ArrayList containing valid Athletes.
     * @throws IOException if the file is not found or is not accessible for any reason.
     */
    public static ArrayList<Athlete> getAthletesFromFile(String path) throws IOException {
        FileReader         fr       = new FileReader(path);
        BufferedReader     br       = new BufferedReader(fr);
        String             nextLine = null;
        ArrayList<Athlete> athletes = new ArrayList<>();

        while ((nextLine = br.readLine()) != null) {
            Athlete a = processAthlete(nextLine);
            if (a != null) {
                athletes.add(a);
            }
        }

        br.close();
        br = null;
        fr.close();
        fr = null;

        return athletes;
    }


    /**
     * Get an Athlete from a flat text file.
     * @param data  String containing Athlete information.
     *                must have the format:
     *                  TYPE|key=value;key=value;key=value;key=value;
     * @return Athlete generated from the received data.
     */
    public static Athlete processAthlete(String data) {
        Athlete  a          = null;
        String[] dataValues = data.split("\\|");

        // Get the type by splitting on pipe -> on the left we should have the type.
        switch (dataValues[0]) {
            case "RUNNER":
                a = new Runner();
                break;
            case "BIKER":
                a = new Biker();
                break;
            case "SWIMMER":
                a = new Swimmer();
                break;
            default:
                a = null;
                break;
        }
        if (a == null)
            return null;

        // Now will split the right part based on ';' to get the "key=value" pairs
        String[] properties = dataValues[1].split(";");
        // Split every "key=value" pair to get each Athlete property
        for (String s : properties) {   // 4 or 5 "key=value" strings
            String[] propValues = s.split("=");
            switch (propValues[0]) {
                case "name":
                    a.setName(propValues[1]);
                    break;
                case "age":
                    a.setAge(Integer.parseInt(propValues[1]));
                    break;
                case "injured":
                    a.setIsInjured(Boolean.parseBoolean(propValues[1]));
                    break;
                case "shoes":
                    ((Runner) a).setShoeBrand(propValues[1]);
                    break;
                case "clips":
                    ((Biker) a).setUsesClips(Boolean.parseBoolean(propValues[1]));
                default:
                    break;
            }
        }
        return a;
    }


    /**
     * Get if we succeeded to write any new Athlete to file.
     * @param path  the location of the output file.
     * @param athletes  all the athletes we have read, need to save.
     * @return boolean to signal if we saved at least one Athlete.
     * @throws IOException if cannot write to file for any reason.
     */
    public static boolean writeAthletesToFile(String path, ArrayList<Athlete> athletes) throws IOException {
        FileWriter     fw         = new FileWriter(path);
        BufferedWriter bw         = new BufferedWriter(fw);
        boolean        atLeastOne = false;

        for (Athlete a : athletes) {
            bw.write(a.toDataString());
            bw.newLine();
            atLeastOne = true;
        }
        bw.close();
        bw = null;
        fw.close();
        fw = null;

        return atLeastOne;
    }
}
