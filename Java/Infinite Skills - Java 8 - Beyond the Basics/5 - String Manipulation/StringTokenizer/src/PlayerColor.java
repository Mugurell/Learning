/**
 * Created by petru on 24-Oct-15.
 */


public class PlayerColor
{
    private String _name;
    private String _color;

    public PlayerColor(String name, String color) {
        _name = name;
        _color = color;
    }

    public String toString() {
        return String.format("%6s : %-6s", _name, _color);
    }
}
