import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class FilePlayer {
    Player [] players;
    FilePlayer(){
        players = new Player[5];
        int cnt = 0;
        for(int i=0; i<players.length; ++i){
            players[i] = new Player();
            players[i].setRank(++cnt);
            players[i].setName("hhh123");
            players[i].setTime(12.2);
        }
    }
    public void read(){
        try{
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("rank.txt"));
            Player [] objArr = (Player [])ois.readObject();
            for(Player obj: objArr){
                System.out.print(obj.rank + "  " + obj.name + "  " + obj.time + "\n");
            }
            ois.close();
        }catch(ClassNotFoundException event){
            System.out.println(event);
        }catch(IOException event){
            System.out.println(event);
        }
    }
    public void write(){
        try{
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("rank.txt"));
            oos.writeObject(players);
            oos.close();
        }catch(IOException event){
            System.out.println(event);
        }
    }
}