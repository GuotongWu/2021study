import java.io.Serializable;

public class Player implements Serializable{
    int rank;
    String name;
    double time;
    // Player(String name, double time){
    //     this.rank = 0;
    //     this.name = name;
    //     this.time = time;
    // }
    public void setRank(int r){
        this.rank = r;
    }
    public void setName(String n){
        this.name = n;
    }
    public void setTime(double t){
        this.time = t;
    }
}
