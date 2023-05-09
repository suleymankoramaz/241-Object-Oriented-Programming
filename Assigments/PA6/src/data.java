//SUPERCLASS OF VIDEO-AUDIO-IMAGE-TEXT

class data
{
	//PRIVATE CLASS MEMBERS

	//Name
	private String name;
	//First information, it's dimension for video and image , duration for audio
	private double dimension_duration;
	//Second information, it's duration of video 
	private double dimension_duration2;
	//The other information of data
	private String other_info;

	//CONSTRUCTORS

	//Parameters: name
	public data(String n){name = n;}	
	//Parameters: name - other information
	public data(String n,String other)
	{
		name = n;
		other_info = other;
	}
	//Parameters: name - duration/dimension - other information
	public data(String n,double dd,String other)
	{
		name = n;
		dimension_duration = dd;
		other_info = other;
	}
	//Parameters: name - duration - dimension - other information
	public data(String n,double dd,double dd2,String other)
	{
		name = n;
		dimension_duration = dd;
		dimension_duration2 = dd2;
		other_info = other;
	}

	//GETTER FUNCTIONS
	public String get_name(){return name;}	
	public double get_dd(){return dimension_duration;}	
	public double get_dd2(){return dimension_duration2;}	
	public String get_other(){return other_info;}	
	
}