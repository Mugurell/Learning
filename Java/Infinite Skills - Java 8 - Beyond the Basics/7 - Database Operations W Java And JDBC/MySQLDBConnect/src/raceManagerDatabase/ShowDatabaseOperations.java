package raceManagerDatabase;

import ServerInterop.DBManager;
import ServerInterop.MySQLServerConnector;
import ServerInterop.ServerConnector;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by petru on 30-Oct-15.
 */


public class ShowDatabaseOperations
{
    private static final String CONFIG_PATH = "src/ServerInterop/dataconfig.json";
    private static final String DB_KEY      = "racemanagerdb";


    public static void main(String[] args) {
        try {
            // create the connector
            ServerConnector sc = new MySQLServerConnector(CONFIG_PATH, DB_KEY);

            // create the manager
            DBManager dbm = new DBManager(sc);

            // connect
            dbm.openConnection();

            // ResultSet for table schema -- prove we connected
            ResultSet rs = dbm.ExecuteRSGetTableSchema();
            while (rs.next()) {
                System.out.println("Table found: " + rs.getString("TABLE_NAME"));
            }
            rs.close();

            // close connection
            dbm.closeConnection(false);
        } catch (Exception e) {
            // TODO need better logging.
            e.printStackTrace();
        }
    }
}
