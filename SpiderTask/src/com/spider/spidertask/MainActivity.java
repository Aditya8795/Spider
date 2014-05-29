package com.spider.spidertask;

import android.app.Activity;
import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

public class MainActivity extends Activity {
	//check out the tosend function, for use in a intent we define the KEY,
	public final static String EXTRA_MESSAGE = "com.spider.spidertask.MESSAGE";
	//we use the app's pakage name as prefix as this ensure's the key is unique in case app to app interaction takes place

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
		
		//now we can start the intent..
		startActivity(intent);
		
	}

}
