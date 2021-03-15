import java.sql.*;
 
public class Mysqldemo {
    public static void main(String[] args) {
        Connection con = null;
        Statement sql;
        ResultSet rs;
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){}
        String userName = "root";
        String password = "wgtwgt0017";
        String uri = "jdbc:mysql://localhost:3306/runoob?useSSL=true";
        try{
            con = DriverManager.getConnection(uri, userName, password);
        }catch(SQLException e){}
        try{
            sql = con.createStatement();
            rs = sql.executeQuery("SELECT * FROM websites");
            while(rs.next()){
                System.out.println(rs.getInt(1)+rs.getString(2));
            }
            con.close();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
}