#include <gtkmm.h>
#include <string>
#include <cstring>
#include <bits/stdc++.h> 
#include "send_Input.h"

using namespace std;
using namespace Gtk;
 
class GTKTest : public Window
{
    // controls 
    protected: 
        VBox vBoxMain;
        Label labelTextToDisplay;
        Entry entryTextToDisplay;
        Label labelDisplayTo;
        ComboBoxText comboBoxDisplayTo;
        CheckButton checkButtonPrependMessage;
        Button buttonDisplay;
 
    // methods
    public: GTKTest()
    {
        set_border_width(10);
 
        // vBoxMain
        add(vBoxMain);
        vBoxMain.show();
 
        // labelTextToDisplay
        labelTextToDisplay.set_label("Please Input Message Request:");
        vBoxMain.add(labelTextToDisplay);
        labelTextToDisplay.show();
 
        // entryTextToDisplay
        entryTextToDisplay.set_text("7DF#02010C0000000000");
        vBoxMain.add(entryTextToDisplay);
        entryTextToDisplay.show();
 
        // labelDisplayTo
        labelDisplayTo.set_label("Display message content to:");
        vBoxMain.add(labelDisplayTo);
        labelDisplayTo.show();
 
        // comboBoxDisplayTo
        comboBoxDisplayTo.append("Console");
        comboBoxDisplayTo.append("Dialog");
        comboBoxDisplayTo.set_active(0);
        vBoxMain.add(comboBoxDisplayTo);
        comboBoxDisplayTo.show();
 
        // checkButtonPrependMessage
        checkButtonPrependMessage.set_label("Prepend 'Message: '");
        vBoxMain.add(checkButtonPrependMessage);
        checkButtonPrependMessage.show();
 
        // buttonDisplay
        buttonDisplay.set_label("Send");
        buttonDisplay.signal_clicked().connect
        (
            sigc::mem_fun
            (
                *this,
                &GTKTest::buttonDisplayClicked
            )
        );
        vBoxMain.add(buttonDisplay);
        buttonDisplay.show();
    }
	
	public: char stringToChar(string s) 
	{ 	  
		int n = s.length(); 
	  
		// declaring character array 
		char char_array[n + 1]; 
	  
		// copying the contents of the string to char array 
		strcpy(char_array, s.c_str()); 
	  
		for (int i = 0; i < n; i++) 
			cout << char_array[i];  
		
		return char_array[n+1];
	} 
 
    // event handlers
 
    protected: void buttonDisplayClicked()
    {
        string textToDisplay = entryTextToDisplay.get_text();
	char *c = strcpy(new char[textToDisplay.length()+1], textToDisplay.c_str());
 
        bool prependMessage = checkButtonPrependMessage.get_active();
        if (prependMessage == true)
        {
            textToDisplay.insert(0, "Message: ");
        }
 
        string displayMode = comboBoxDisplayTo.get_active_text();
//	vector<char> writable(textToDisplay.begin(), testToDisplay.end());        
// char inputText[30] = stringToChar(textToDisplay);
		send_CAN(c);
 
        if (displayMode == "Console")
        {
            printf("%s\n", textToDisplay.c_str());
        }
        else if (displayMode == "Dialog")
        {       
            MessageDialog dialog(textToDisplay);
            dialog.run();
        }
        else
        {
            throw runtime_error("Unrecognized display mode!");
        }
    }
};
 
int main (int argc, char *argv[])
{
    Main kit(argc, argv);
    GTKTest GTKTest;
    Main::run(GTKTest);
    return 0;
}


