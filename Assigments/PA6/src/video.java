//  SUBCLASS VIDEO  //

public class video extends data implements visual , playable
{
	//CONSTRUCTORS

	//parameters: name
	public video(String n){super(n);}
	//parameters: name - duration - dimension - other info /-\ CALL SUPERCLASS CONSTRUCTOR
	public video(String n,double duration,double dimension,String other){super(n,duration,dimension,other);}


	//playable_info() function from interface
	public void playable_info(){
		System.out.println("INFORMATION OF MOVIE");
		System.out.printf("Name of the movie: %s-",get_name());
		System.out.printf("Duration = %.2f-",get_dd());
		System.out.printf("Dimention = %.2f-",get_dd2());
		System.out.printf("Other information about data: %s\n\n",get_other());
	}
	public void visual_info(){System.out.printf("Dimention = %.2f-",get_dd2());}
}