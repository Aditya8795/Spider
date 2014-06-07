package com.spider.spidertask;


import com.spider.spidertask.R;

import android.app.Activity;
import android.app.Fragment;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color; 
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	//6 because if NO radio button is checked then the colour is black(6 indicates black)
	int colour=6;
	//this stores the font size (default is 29)
	int font=29;
	//this stores the status of the 3 check boxes for b,i and u
	int bold=0,italics=0,underlined=0;
	//check out the tosend function, for use in a intent we define the KEY for the message
	public final static String EXTRA_MESSAGE = "com.spider.spidertask.MESSAGE";
	// and the KEY for the colour
	public final static String COLOUR = "com.spider.spidertask.COLOUR";
	//we use the app's pakage name as prefix as this ensure's the key is unique in case app to app interaction takes place
	//NOW the key for font size
	public final static String FONT_SIZE = "com.spider.spidertask.FONT";

	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		//on the opening of the app this oncreate() is called as per the app lifecycle
		//we define the activity layout with setcontentview as activity_main
		setContentView(R.layout.activity_main);
		
		/*
		 * you will get the Bundle null when activity get starts firt time. 
		 * and the Bundle argument to onCreate(Bundle) will be non-null if and only if 
		 * the Activity had it's onSaveInstanceState method previously called.
		 *This happens during orientation changes... and also happens when the activity is coming back after
		 *being killed by the OS, and when you trigger any other configuration change of interest on your device.
		 */
		//In order to add a fragment to the activity during the activity runtime. we do this ->>
		
		//WHY during activity runtime?
		//Because the fragment has been added to the FrameLayout container at runtime—
		//instead of defining it in the activity's layout with a <fragment> element—
		//the activity can remove the fragment and replace it with a different one.
		
		//This is necessary if you plan to change fragments during the life of the activity.
		 // However, if we're being restored from a previous state,
        // then we don't need to do anything and should return or else
        // we could end up with overlapping existing fragments thats why we check if savedinstancestate is NULL
		
		if (savedInstanceState == null) {
			
			//using fragment manager we perform fragment transactions like add,remove fragments..
			//we call commit in order to finilize the changes, ie adding the fragment
			//we keept the cointainer 
			
			getFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
		
		
		
	}
	
	

// i deleted the dropdown settings (at the top right corner of the screen)
	
	/**
	 * A placeholder fragment containing a simple view.
	 * this defines the PlaceholderFragment.. which is set in the oncreate()
	 */
	public static class PlaceholderFragment extends Fragment {
 
		public PlaceholderFragment() {
		}

		//the fragment itself has its OWN lifecycle!
		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			
			return rootView; //as far as I understood, it returns the "highest parent view" of the current screen of the fragment???
		}
	}
	 
	public void add(View v)
	{
		font++;
		//a handle on no
		TextView no = (TextView)findViewById(R.id.textView3);
		no.setText(String.valueOf(font));
	}
	public void subtract(View v)
	{
		if(font==0)
		{
			Context context = getApplicationContext();
			CharSequence text = "You cant have a Font size Less Than 0";
			int duration = Toast.LENGTH_SHORT;

			Toast toast = Toast.makeText(context, text, duration);
			toast.show();
			return;
		}
		font--;
		//a handle on no
		TextView no = (TextView)findViewById(R.id.textView3);
		no.setText(String.valueOf(font));
	}
	//on clicking the button this function will be called as we have set in the button's on click attribute
	public void nextpage(View v)
	{
		//the variable v contains the view of the Screen at the instance of the click registering
		//first we need to create a intent  to provide runtime binding between this (mainactivity) and the (newactivity)
		Intent intent = new Intent(this,DisplayMessageActivity.class);
		//here "this", its the context of current state of the application/object. 
		//It lets newly created objects (in this case - intent) understand what has been going on. 
		//Typically you call it to get information regarding another part of your program
		//the NewActivity class is to where the system should deliver the intent in case the intent is started
		
		//this intent is 'explicit' as its specified the 'app component' (in this case a activity) to which the 
		//intent should be given..
		//in the case of 'implicit' intents, any app installed on the device can respond to the intent
		//as long as the meta data specifications are satisfied
		
		//we can also use the intent to carry a bundle of data to the 'app component' (in this case a activity)
		
		//first we organise the data we wish to send,
		EditText message = (EditText)findViewById(R.id.editText1); //we access the edit text and get the data the user entered
		//store this data which is in "edittext" form IN string form
		String tosend = message.getText().toString(); //we convert the "edittext" to "text" and then to string
		//now we can store this message into the intent we just created
		//intents store the data as key-value pairs called extras
		intent.putExtra(EXTRA_MESSAGE,tosend); //for the message, 'tosend' the key is EXRA_MESSAGE
		//This is why define the key at the start of the MainActivity
		
		//we also need to send the information regarding the colour of the text,
		//first we establish the 6 handles on the 6 radio buttons
		RadioButton radio1 = (RadioButton)findViewById(R.id.radioButtonGreen);
		RadioButton radio2 = (RadioButton)findViewById(R.id.radioButtonRed);
		RadioButton radio3 = (RadioButton)findViewById(R.id.radioButtonBlue);
		RadioButton radio4 = (RadioButton)findViewById(R.id.radioButtonYellow);
		RadioButton radio5 = (RadioButton)findViewById(R.id.radioButtonPink);
		RadioButton radio6 = (RadioButton)findViewById(R.id.radioButtonBlack);
		//now we find which colour the text has
		if(radio1.isChecked()) colour=1;
		if(radio2.isChecked()) colour=2;
		if(radio3.isChecked()) colour=3;
		if(radio4.isChecked()) colour=4;
		if(radio5.isChecked()) colour=5;
		if(radio6.isChecked()) colour=6;
		//now we need to put this information into the intent
		intent.putExtra(COLOUR, colour);
		//and we put in the font size
		//font=np.getValue();
		intent.putExtra(FONT_SIZE,font);
		//now we need the info if the text is to be bold and/or italic and/or underlined
		final CheckBox checkBoxb = (CheckBox) findViewById(R.id.checkBoxbold);
		final CheckBox checkBoxi = (CheckBox) findViewById(R.id.checkBoxitalics);
		final CheckBox checkBoxu = (CheckBox) findViewById(R.id.checkBoxunderlined);
        if (checkBoxb.isChecked()) {
            bold=1;
        }
        else
        {
        	bold=0;
        }
        if (checkBoxi.isChecked()) {
        	italics=1;
        }
        else
        {
        	italics=0;
        }
        if (checkBoxu.isChecked()) {
            underlined=1;
        }
        else
        {
        	underlined=0;
        }
        //now we have to store it in the intent as a extra
        intent.putExtra("bold",bold);
        intent.putExtra("italics",italics);
        intent.putExtra("underlined",underlined);
        //if the text field is empty
        if(message.getText().toString().length() == 0)
        {
        	Context context = getApplicationContext();
			CharSequence text = "You Havent Entered Anything!!";
			int duration = Toast.LENGTH_SHORT;

			Toast toast = Toast.makeText(context, text, duration);
			toast.show();
			return;
        }
        
        //COULDNT implement spinner
        //get a handle on the spinner
        //Spinner spinner = (Spinner) findViewById(R.id.spinner1);
        //get the info on the font
        //String Text = spinner.getSelectedItem().toString();
        //store this info (on which font it is) in the intent using extra
        
		//now we can start the intent..
		startActivity(intent);
		
	}
	//the functions for each color
	//APPLY THE LOGIC given in this function green (below) to all other colors..
	public void green(View v)
	{
		//we access the edit text and get the text the user entered and change it to green
		EditText edit = (EditText)findViewById(R.id.editText1);
		edit.setTextColor(Color.parseColor("green"));
		
		//here we establish handles on all other radio buttons
		RadioButton radio2 = (RadioButton)findViewById(R.id.radioButtonRed);
		RadioButton radio3 = (RadioButton)findViewById(R.id.radioButtonBlue);
		RadioButton radio4 = (RadioButton)findViewById(R.id.radioButtonYellow);
		RadioButton radio5 = (RadioButton)findViewById(R.id.radioButtonPink);
		RadioButton radio6 = (RadioButton)findViewById(R.id.radioButtonBlack);
		
		//check if any of them is checked, if so, we uncheck them
		if(radio2.isChecked()) radio2.setChecked(false);
		if(radio3.isChecked()) radio3.setChecked(false);
		if(radio4.isChecked()) radio4.setChecked(false);
		if(radio5.isChecked()) radio5.setChecked(false);
		if(radio6.isChecked()) radio6.setChecked(false);
	}
	public void red(View v)
	{
		//we access the edit text and get the text the user entered
		EditText edit = (EditText)findViewById(R.id.editText1);
		edit.setTextColor(Color.parseColor("red"));
		RadioButton radio1 = (RadioButton)findViewById(R.id.radioButtonGreen);
		RadioButton radio3 = (RadioButton)findViewById(R.id.radioButtonBlue);
		RadioButton radio4 = (RadioButton)findViewById(R.id.radioButtonYellow);
		RadioButton radio5 = (RadioButton)findViewById(R.id.radioButtonPink);
		RadioButton radio6 = (RadioButton)findViewById(R.id.radioButtonBlack);
		if(radio1.isChecked()) radio1.setChecked(false);
		if(radio3.isChecked()) radio3.setChecked(false);
		if(radio4.isChecked()) radio4.setChecked(false);
		if(radio5.isChecked()) radio5.setChecked(false);
		if(radio6.isChecked()) radio6.setChecked(false);
	}
	public void blue(View v)
	{
		//we access the edit text and get the text the user entered
		EditText edit = (EditText)findViewById(R.id.editText1);
		edit.setTextColor(Color.parseColor("blue"));
		RadioButton radio1 = (RadioButton)findViewById(R.id.radioButtonGreen);
		RadioButton radio2 = (RadioButton)findViewById(R.id.radioButtonRed);
		RadioButton radio4 = (RadioButton)findViewById(R.id.radioButtonYellow);
		RadioButton radio5 = (RadioButton)findViewById(R.id.radioButtonPink);
		RadioButton radio6 = (RadioButton)findViewById(R.id.radioButtonBlack);
		if(radio2.isChecked()) radio2.setChecked(false);
		if(radio1.isChecked()) radio1.setChecked(false);
		if(radio4.isChecked()) radio4.setChecked(false);
		if(radio5.isChecked()) radio5.setChecked(false);
		if(radio6.isChecked()) radio6.setChecked(false);
	}
	public void yellow(View v)
	{
		//didnt like yellow
		//we access the edit text and get the text the user entered
		EditText edit = (EditText)findViewById(R.id.editText1);
		edit.setTextColor(Color.parseColor("gray"));
		
		RadioButton radio1 = (RadioButton)findViewById(R.id.radioButtonGreen);
		RadioButton radio2 = (RadioButton)findViewById(R.id.radioButtonRed);
		RadioButton radio3 = (RadioButton)findViewById(R.id.radioButtonBlue);
		RadioButton radio5 = (RadioButton)findViewById(R.id.radioButtonPink);
		RadioButton radio6 = (RadioButton)findViewById(R.id.radioButtonBlack);
		if(radio2.isChecked()) radio2.setChecked(false);
		if(radio3.isChecked()) radio3.setChecked(false);
		if(radio1.isChecked()) radio1.setChecked(false);
		if(radio5.isChecked()) radio5.setChecked(false);
		if(radio6.isChecked()) radio6.setChecked(false);
	}
	public void pink(View v)
	{
		//PINK WAS NOT AVAILABLE, SO I PUT CYAN...
		//we access the edit text and get the text the user entered
		EditText edit = (EditText)findViewById(R.id.editText1);
		edit.setTextColor(Color.parseColor("cyan"));
		
		RadioButton radio1 = (RadioButton)findViewById(R.id.radioButtonGreen);
		RadioButton radio2 = (RadioButton)findViewById(R.id.radioButtonRed);
		RadioButton radio3 = (RadioButton)findViewById(R.id.radioButtonBlue);
		RadioButton radio4 = (RadioButton)findViewById(R.id.radioButtonYellow);
		RadioButton radio6 = (RadioButton)findViewById(R.id.radioButtonBlack);
		if(radio2.isChecked()) radio2.setChecked(false);
		if(radio3.isChecked()) radio3.setChecked(false);
		if(radio4.isChecked()) radio4.setChecked(false);
		if(radio1.isChecked()) radio1.setChecked(false);
		if(radio6.isChecked()) radio6.setChecked(false);
	}
	public void black(View v)
	{
		//we access the edit text and get the text the user entered
		EditText edit = (EditText)findViewById(R.id.editText1);
		edit.setTextColor(Color.parseColor("black"));
		
		RadioButton radio1 = (RadioButton)findViewById(R.id.radioButtonGreen);
		RadioButton radio2 = (RadioButton)findViewById(R.id.radioButtonRed);
		RadioButton radio3 = (RadioButton)findViewById(R.id.radioButtonBlue);
		RadioButton radio4 = (RadioButton)findViewById(R.id.radioButtonYellow);
		RadioButton radio5 = (RadioButton)findViewById(R.id.radioButtonPink);
		if(radio2.isChecked()) radio2.setChecked(false);
		if(radio3.isChecked()) radio3.setChecked(false);
		if(radio4.isChecked()) radio4.setChecked(false);
		if(radio5.isChecked()) radio5.setChecked(false);
		if(radio1.isChecked()) radio1.setChecked(false);
	}
	

	
}
