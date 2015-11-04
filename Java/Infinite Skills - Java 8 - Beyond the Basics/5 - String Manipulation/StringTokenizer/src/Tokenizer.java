import java.util.Random;
import java.util.StringTokenizer;

/**
 * Created by petru on 24-Oct-15.
 */


public class Tokenizer
{
    public static void main(String[] args) {
        // Given two Strings
        String colors = "red|orange|yellow|green|blue|indigo|violet";
        String players = "John David Mike Jerry Sally Tina Jenny";

        StringTokenizer allColors = new StringTokenizer(colors, "\\|");
        while (allColors.hasMoreTokens()) {
            System.out.println("Color: " + allColors.nextToken());
        }

        // A String tokenizer uses the default delimiter set - " \t\n\r\f"
        StringTokenizer allPlayers = new StringTokenizer(players);
        int size = allPlayers.countTokens();        // needed later
        while (allPlayers.hasMoreTokens()) {
            System.out.println(" Player: " + allPlayers.nextToken());
        }

    /*****************************************************************************/
        boolean completed = false;
        String usedPlayers = "";
        String usedColors = "";
        Random r = new Random();
        int currentCreated = 0;
        // This will store the player - color combinations
        PlayerColor[] playerColors = new PlayerColor[size];

        while (!completed) {
            boolean validPlayer = false;
            int nextPlayer = -1;
            String player = "";
            while (!validPlayer) {
                nextPlayer = r.nextInt(size);
                StringTokenizer usedPlayersTemp = new StringTokenizer(usedPlayers, ", ");
                boolean isValid = true;
                // If there is >=1 player selected, make sure the next one is unique
                if (usedPlayers.length() > 0) {
                    while (usedPlayersTemp.hasMoreTokens()) {
                        if (Integer.parseInt(usedPlayersTemp.nextToken()) == nextPlayer) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (isValid) {
                    validPlayer = true;
                    usedPlayers = usedPlayers + nextPlayer + ", ";
                }
            }

            // allPlayers is a managed iteration of a token collection, and one rule of this is that
            // there is no way to go back to a previous token, so if we need to access a previous element
            // we need to reparse it by creating a new StringTokenizer on that string.
            allPlayers = new StringTokenizer(players);
            int index = 0;
            while (allPlayers.hasMoreTokens()) {
                String s = allPlayers.nextToken();
                if (index == nextPlayer) {
                    player = s;
                }
                index++;
            }


            boolean validColor = false;
            int nextColor = -1;
            String color = "";
            while (!validColor) {
                nextColor = r.nextInt(size);
                StringTokenizer usedColorTemp = new StringTokenizer(usedColors, ", ");
                boolean isValid = true;
                if (usedColors.length() > 0) {
                    while (usedColorTemp.hasMoreTokens()) {
                        if (Integer.parseInt(usedColorTemp.nextToken()) == nextColor) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (isValid) {
                    validColor = true;
                    usedColors = usedColors + nextColor + ", ";
                }

            }
            allColors = new StringTokenizer(colors, "\\|");
            index = 0;
            while (allColors.hasMoreTokens()) {
                String s = allColors.nextToken();
                if (index == nextColor) {
                    color = s;
                }
                index++;
            }

            PlayerColor pc = new PlayerColor(player, color);
            playerColors[currentCreated++] = pc;
            if (currentCreated == size) {
                completed = true;
            }
        }

        for (PlayerColor pc : playerColors) {
            System.out.println("Next player - color combination   " + pc.toString());
        }

    }
}
