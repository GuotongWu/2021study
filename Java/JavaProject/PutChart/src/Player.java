import java.io.*;
public class Player implements Serializable{
    private int rank;
    private String username;
    private double miliseconds;
    public void setRank(int r){
        rank = r;
    }
    public void setUsername(String name){
        username = name;
    }
    public void setMiliseconds(double time){
        miliseconds = time;
    }
    public int getRank(){
        return rank;
    }
    public String getUsername(){
        return username;
    }
    public double getMiliseconds(){
        return miliseconds;
    }
}
