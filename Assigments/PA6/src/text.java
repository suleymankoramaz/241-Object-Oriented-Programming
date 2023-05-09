//  SUBCLASS VIDEO  //

public class text extends data implements non_visual , non_playable 
{
	//CONSTRUCTORS

	//parameters: name
	public text(String n){super(n);}
	//parameters: name - other info /-\ CALL SUPERCLASS CONSTRUCTOR
	public text(String n,String other){super(n,other);}


	//non_playable_info() function from interface
	public void non_playable_info(){
		System.out.println("INFORMATION OF NOVEL");
		System.out.printf("Name of the novel: %s-",get_name());
		System.out.println("It's non-playable.-");
		System.out.printf("Other information about data: %s\n\n",get_other());
	}
	public void non_visual_info(){System.out.println("It's non-visual.-");}

}