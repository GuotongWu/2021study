// Decompiled by Jad v1.5.7g. Copyright 2000 Pavel Kouznetsov.
// Jad home page: http://www.geocities.com/SiliconValley/Bridge/8617/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi 
// Source File Name:   MUKT

import java.awt.Color;
import java.util.HashMap;
import javax.swing.JToggleButton;

class Z extends Thread
{

    private final C GREEN;

    Z(C c)
    {
        GREEN = c;
    }

    public final void run()
    {
        java.awt.Point apoint[] = GREEN.Z.C();
        JToggleButton jtogglebutton = (JToggleButton)GREEN.B.get(apoint[0]);
        JToggleButton jtogglebutton1 = (JToggleButton)GREEN.B.get(apoint[1]);
        Color color = jtogglebutton.getBackground();
        jtogglebutton.setBackground(Color.GREEN);
        jtogglebutton1.setBackground(Color.GREEN);
        try
        {
            Thread.sleep(2000L);
        }
        catch(InterruptedException interruptedexception)
        {
            interruptedexception.printStackTrace();
        }
        jtogglebutton.setBackground(color);
        jtogglebutton1.setBackground(color);
    }
}
