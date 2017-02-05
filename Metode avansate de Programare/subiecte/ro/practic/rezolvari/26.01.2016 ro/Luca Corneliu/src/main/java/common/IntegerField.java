/*
 * Copyright (c) 28.12.2015
 *  Name: Luca Corneliu Daniel
 *  Contact: luca_corneliu2003@yahoo.com
 */

package common;


import javafx.scene.control.TextField;

/**
 * Created by luca_ on 28.12.2015 at 19:45.
 */
public class IntegerField extends TextField {
    @Override
    public void replaceText(int start, int end, String text) {
        if (validate(text))
        {
            super.replaceText(start, end, text);
        }
    }

    @Override
    public void replaceSelection(String text)
    {
        if (validate(text))
        {
            super.replaceSelection(text);
        }
    }
    private boolean validate(String text) {
        return ("".equals(text) || text.matches("[0-9]"));
    }
}
