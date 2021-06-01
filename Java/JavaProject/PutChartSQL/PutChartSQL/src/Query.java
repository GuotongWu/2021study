import java.sql.*;
public class Query {
    String databaseName="";
    String SQL;
    String [] columnName;
    String [][] record;
    public Query(){
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){
            System.out.println(e);
        }
    }
    public void setDatabaseName(String s){
        databaseName = s.trim();
    }
    public void setSQL(String SQL){
        this.SQL = SQL.trim();
    }
    public String[] getColumnName(){
        if(columnName == null){
            System.out.println("Error");
            return null;
        }
        return columnName;
    }
    public void startQuery(){
        Connection con;
        Statement sql;
        ResultSet rs;
        String url = "jdbc:mysql://localhost:3306/" + databaseName +"?useSSL=true&characterEncoding=utf-8";
        try{
            con = DriverManager.getConnection(url, "root", "wgtwgt0017");
            sql = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_READ_ONLY);
            rs = sql.executeQuery(SQL);
            ResultSetMetaData metaDate = rs.getMetaData();
            int columnCount = 3;
            columnName = new String[columnCount];
            for(int i=1; i<=columnCount; ++i){
                columnName[i-1] = metaDate.getColumnName(i);
            }
            rs.last();
            int recordAmount = rs.getRow();
            record = new String[recordAmount][columnCount];
            int i = 0;
            rs.beforeFirst();
            while(rs.next()){
                // record[i][0] = rs.getString(1);
                record[i][0] = Integer.toString(i+1);
                record[i][1] = rs.getString(2);
                record[i][2] = Float.toString(rs.getFloat(3)) + " sec";
                i++;
            }
            con.close();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
    public String[][] getRecord(){
        startQuery();
        return record;
    }
    public void startWrite(){
        Connection con;
        Statement sql;
        String url = "jdbc:mysql://localhost:3306/" + databaseName +"?useSSL=true&characterEncoding=utf-8";
        try{
            con = DriverManager.getConnection(url, "root", "wgtwgt0017");
            sql = con.createStatement();
            int ok = sql.executeUpdate(SQL);
            con.close();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
}
