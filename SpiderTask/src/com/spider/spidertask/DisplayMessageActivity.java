package com.spider.spidertask;

import android.app.Activity;
import android.app.Fragment;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Bundle;
import android.text.Html;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;


public class DisplayMessageActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		setContentView(R.layout.fragment_display_message);
		/*
		if (savedInstanceState == null) {
			getFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
		*/
		
		//so when the intent starts, this activity will be started.. so oncreate() will be called
		// we get the message from the intent
		Intent intent =getIntent();
		// get the message (value) using EXTRA_MESSAGE (the key)
		String message = intent.getStringExtra(MainActivity.EXTRA_MESSAGE); 
		//get which colour it is and default is black (6)
		int colour = intent.getIntExtra(MainActivity.COLOUR, 6);
		//store this message into the prexisting Textview, which has the id textview1 in the xml file (fragment_display_message)
		//using find viewbyid, we establish the handle on the textview
		TextView text = (TextView)findViewById(R.id.textView1);
		//decide which color it is and set it
				if(colour==1) text.setTextColor(Color.parseColor("green"));
				if(colour==2) text.setTextColor(Color.parseColor("red"));
				if(colour==3) text.setTextColor(Color.parseColor("blue"));
				if(colour==4) text.setTextColor(Color.parseColor("yellow"));
				if(colour==5) text.setTextColor(Color.parseColor("cyan"));
				if(colour==6) text.setTextColor(Color.parseColor("black"));
		//Now take the font size
		int font_size=intent.getIntExtra(MainActivity.FONT_SIZE, 20);
		text.setTextSize(TypedValue.COMPLEX_UNIT_SP, font_size);
		//now we take the status of bold,underlined and italics
		int bold = intent.getIntExtra("bold", 0);
		int underlined = intent.getIntExtra("underlined", 0);
		int italics = intent.getIntExtra("italics", 0);
		if(bold==1 && italics==0)
		{
			text.setTypeface(null, Typeface.BOLD); 
		}
		if(italics==1 && bold==0)
		{
			text.setTypeface(null, Typeface.ITALIC); 
		}
		if(italics==1 && bold==1)
		{
			text.setTypeface(null, Typeface.BOLD_ITALIC); 
		}
		
		if(underlined==1)
		{
			String s = "<u>" +message+"</u>";
			text.setText(Html.fromHtml(s));
			return;
		}
		
		//set the value of the string in the textveiw1 as the message
		text.setText(message);
		
				
	}
/*
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
*/
	/**
	 * A placeholder fragment containing a simple view.
	 */
	
	public static class PlaceholderFragment extends Fragment {

		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_display_message,
					container, false);
			return rootView;
		}
	}

}
