// Decompiled by Jad v1.5.7g. Copyright 2000 Pavel Kouznetsov.
// Jad home page: http://www.geocities.com/SiliconValley/Bridge/8617/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi 
// Source File Name:   MUKT

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

class I
    implements ActionListener
{

    int MUKT;
    private final C getMaximum;

    I(C c)
    {
        getMaximum = c;
        MUKT = 0;
    }

    public final void actionPerformed(ActionEvent actionevent)
    {
        if(MUKT++ < getMaximum.C.getMaximum())
        {
            getMaximum.C.setValue(MUKT);
        } else
        {
            String s;
            if(getMaximum.Z.Z())
                s = "Successful!";
            else
                s = "no Successful!";
            JOptionPane.showMessageDialog(null, s);
            ((Timer)actionevent.getSource()).stop();
        }
    }
}
