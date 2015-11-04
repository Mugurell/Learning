import java.util.Random;

/**
 * Created by petru on 18-Oct-15.
 */


public class SplitStrings
{
    public static void main(String[] args) {
        // Given two strings
        String colors  = "red|orange|yellow|green|blue|indigo|violet";
        String players = "John David Mike Jerry Sally Tina Jenni";

        // The task is to create a list of players with colors, making sure to not have any repeated players or colors
        // and try to do this in a random fashion.

        // First, we need to learn about a way to "split" the strings so we can get a list of colors and a list of
        // players.

        // The split() method will work, but it takes a regular expression.
        // Luckily, a " " (space) can be used without any problems but a pipe is a different issue.
        // We need \| to match and we have to add another \ to avoid a problem with the escape character.

        String[] allColors = colors.split("\\|");
        // Prove that it works:
        for (String s : allColors) {
            System.out.println("Color: " + s);
        }

        String[] allPlayers = players.split(" ");
        // Prove that it works:
        for (String s : allPlayers) {
            System.out.println("Player: " + s);
        }

        // This only works if players and colors are of equal length.
        if (!(allPlayers.length == allColors.length)) {
            // This will cause a hard stop.
            throw new IllegalStateException("Colors and Players must have equal numbers!");
        }

        // There are many ways we could combine allPlayers with allColors.
        // An easy way and good practice for splitting could be just to store the used indexes in a String and make
        // sure we get an unused index for each random.
        String usedPlayers = "";
        String usedColors = "";
        Random r = new Random();
        int size = allPlayers.length;
        int currentCreated = 0;
        boolean completed = false;
        PlayerColor[] playerColors = new PlayerColor[size];
        while (!completed) {
            boolean validPlayer = false;
            int nextPlayer = -1;
            while (!validPlayer) {
                nextPlayer = r.nextInt(size);
                String[] usedPlayersTemp = usedPlayers.split("\\|");
                boolean isValid = true;
                if (usedPlayers.length() > 0) {
                    for (String s : usedPlayersTemp) {
                        if (Integer.parseInt(s) == nextPlayer) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (isValid) {
                    validPlayer = true;
                    usedPlayers = usedPlayers + nextPlayer + "|";
                }
            }
            String player = allPlayers[nextPlayer];

            boolean validColor = false;
            int nextColor = -1;
            while (!validColor) {
                nextColor = r.nextInt(size);
                String[] usedColorsTemp = usedColors.split("\\|");
                boolean isValid =true;
                // If we have at least one element in our array, check to se
                if (usedColors.length() > 0) {
                    for (String s : usedColorsTemp) {
                        if (Integer.parseInt(s) == nextColor) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (isValid) {
                    validColor = true;
                    usedColors = usedColors + nextColor + "|";
                }
            }

            String color = allColors[nextColor];
            PlayerColor pc = new PlayerColor(player, color);

            playerColors[currentCreated++] = pc;
            if (currentCreated == size) {
                completed = true;
            }
        }

        for (PlayerColor pc : playerColors) {
            System.out.println("\nNext player - color combination:   " + pc.toString());
        }
    }
}
