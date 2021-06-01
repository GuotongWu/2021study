// Decompiled by Jad v1.5.7g. Copyright 2000 Pavel Kouznetsov.
// Jad home page: http://www.geocities.com/SiliconValley/Bridge/8617/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi 
// Source File Name:   MUKT

import java.awt.Point;
import java.io.Serializable;
import java.util.Random;

public class B implements Serializable
{

    static int MUKT = 14;
    static int append = 18;
    int max[][];
    int min[][];
    int nextInt[];

    public B()
    {
        max = new int[MUKT][append];
        min = new int[MUKT][append];
        nextInt = new int[40];
        for(int i = 0; i < 40; i++)
            nextInt[i] = 3;

        for(int j = 0; j < MUKT; j++)
        {
            for(int k = 0; k < append; k++)
                min[j][k] = 0;

        }

    }

    public final void I(int i, int j, int k)
    {
        max[i][j] = k;
    }

    public final int I(int i, int j)
    {
        return max[i][j];
    }

    public final boolean I(int i, int j, int k, int l)
    {
        if(i == k && j == l)
            return false;
        if(I(i, j) != I(k, l))
            return false;
        int i1 = I(i, j);
        int j1 = I(k, l);
        I(i, j, 0);
        I(k, l, 0);
        for(int k1 = 0; k1 < MUKT; k1++)
            if(append(k1, j, l) && MUKT(j, k1, i) && MUKT(l, k1, k))
            {
                I(i, j, i1);
                I(k, l, j1);
                return true;
            }

        for(int l1 = 0; l1 < append; l1++)
            if(MUKT(l1, i, k) && append(i, l1, j) && append(k, l1, l))
            {
                I(i, j, i1);
                I(k, l, j1);
                return true;
            }

        I(i, j, i1);
        I(k, l, j1);
        return false;
    }

    public final void I()
    {
        Random random = new Random();
        for(int i = 0; i < MUKT; i++)
        {
            for(int k = 0; k < append; k++)
            {
                if(i == 0 || k == 0 || i == MUKT - 1 || k == append - 1)
                {
                    I(i, k, 0);
                    continue;
                }
                if(k % 2 != 1)
                    continue;
                int i1;
                do
                    i1 = random.nextInt(40) + 1;
                while(nextInt[i1 - 1] <= 0);
                nextInt[i1 - 1]--;
                I(i, k, i1);
                I(i, k + 1, i1);
            }

        }

        for(int j = 0; j < 1000; j++)
        {
            for(int l = 1; l < MUKT - 1; l++)
            {
                for(int j1 = 1; j1 < append - 1; j1++)
                {
                    int k1 = random.nextInt(MUKT - 2) + 1;
                    int l1 = random.nextInt(append - 2) + 1;
                    int i2 = I(l, j1);
                    I(l, j1, I(k1, l1));
                    I(k1, l1, i2);
                }

            }

        }

    }

    private boolean MUKT(int i, int j, int k)
    {
        for(int l = Math.min(j, k); l <= Math.max(j, k); l++)
            if(I(l, i) != 0)
                return false;

        return true;
    }

    private boolean append(int i, int j, int k)
    {
        for(int l = Math.min(j, k); l <= Math.max(j, k); l++)
            if(I(i, l) != 0)
                return false;

        return true;
    }

    public final boolean Z()
    {
        for(int i = 0; i < MUKT; i++)
        {
            for(int j = 0; j < append; j++)
                if(I(i, j) != 0)
                    return false;

        }

        return true;
    }

    public final Point[] C()
    {
        for(int i = 0; i < MUKT; i++)
        {
            for(int j = 0; j < append; j++)
            {
                Point point = new Point(i, j);
                for(int k = 0; k < MUKT; k++)
                {
                    for(int l = 0; l < append; l++)
                    {
                        Point point1 = new Point(k, l);
                        if(I(point.x, point.y) != 0 && I(point1.x, point1.y) != 0 && I(point.x, point.y, point1.x, point1.y))
                        {
                            String s = "x=" + point.y + " y=" + point.x + "    " + "x=" + point1.y + " y=" + point1.x;
                            Point apoint[] = new Point[2];
                            apoint[0] = point;
                            apoint[1] = point1;
                            return apoint;
                        }
                    }

                }

            }

        }

        return null;
    }

    public final void B()
    {
        Random random = new Random();
        for(int i = 1; i < MUKT - 1; i++)
        {
            for(int j = 1; j < append - 1; j++)
            {
                int k = random.nextInt(MUKT - 2) + 1;
                int l = random.nextInt(append - 2) + 1;
                int i1 = I(i, j);
                I(i, j, I(k, l));
                I(k, l, i1);
            }

        }

    }

}
