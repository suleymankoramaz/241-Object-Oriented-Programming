//  SUBCLASS AUDIO  //

public class audio extends data implements non_visual , playable 
{
	//CONSTRUCTORS

	//parameters: name
	public audio(String n){super(n);}
	//parameters: name - duration - other info /-\ CALL SUPERCLASS CONSTRUCTOR
	public audio(String n,double duration,String other){super(n,duration,other);}


	//playable_info() function from interface
	public void playable_info(){		
		System.out.println("INFORMATION OF PODCAST");
		System.out.printf("Name of the podcast: %s-",get_name());
		System.out.printf("Duration = %.2f-",get_dd());
		System.out.printf("Other information about data: %s\n\n",get_other());
	}
	public void non_visual_info(){System.out.println("It's non-visual.-");}

}