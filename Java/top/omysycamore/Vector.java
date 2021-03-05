package top.omysycamore;

public class Vector {
    private int[] _data;
    private int _size;
    public int size(){
        return _size;
    }
    public int get(int r){
        return _data[r];
    }
    public void put(int r, int e){
        _data[r] = e;
    }
    public void insert(int r, int e){
        for(int i=_size; i>r; --i)
            _data[i] = _data[i-1];
        _data[r] = e;
    }
    public int remove(int r){
        int tmp = _data[r];
        for(int i=r; i<_size-1; ++i)
            _data[i] = _data[i+1];
        return tmp;
    }
    public Vector(){
        _data = null;
        _size = 0;
    }
    public Vector(int n){
        int[] temp = new int[n];
        _data = temp;
        _size = n;
    }
    public Vector(int[] num){
        _data = num;
        _size = num.length;
    }
    public static void main(String[] args) {
        int[] a = {4, 2, 7};
        Vector v1 = new Vector(a);
        for(int n:v1._data){ 
            System.out.printf("%d ", n);
            
        }
        // 同一个包内不需要import
        hello h = new hello();
        h.max(5, 6);
    }
}
