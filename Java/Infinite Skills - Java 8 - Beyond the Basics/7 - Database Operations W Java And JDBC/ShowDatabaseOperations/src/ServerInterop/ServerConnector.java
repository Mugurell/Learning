package ServerInterop;

import java.sql.Connection;

/**
 * Created by petru on 30-Oct-15.
 */


public interface ServerConnector
{
    Connection getConnection();
    String getConnectionURL();
    String getConnectionDetails();
    String getTablesSchemaQuery();
    String getDBName();
    String getServerName();
    String getUserName();
}
